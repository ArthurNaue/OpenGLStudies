#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "shader/shader.hpp"
#include "window_config/window_config.hpp"
#include "texture/texture.hpp"
#include "models/models.hpp"
#include "camera/camera.hpp"
#include "user_input/user_input.hpp"
#include "dt/dt.hpp"

int main()
{
    glfwInit();

    GLFWwindow* window = InitWindow();

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    Shader ourShader("assets/shaders/shader.vs", "assets/shaders/shader.fs");

    Texture wallTex("assets/images/wallTexture.png");
    Texture testTex("assets/images/testTexture.png");
    CreateCubeSize(wallTex, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(3.0f, 6.0f, 1.0f));

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, cubesList[0].GetVerticesSize(), cubesList[0].GetVertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    ourShader.use();
    ourShader.setInt("texture", 0);

    while (!glfwWindowShouldClose(window))
    {
	UpdateDt();

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.use();

	DrawCamera(window, ourShader);

        glBindVertexArray(VAO);

	DrawCubes(ourShader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
