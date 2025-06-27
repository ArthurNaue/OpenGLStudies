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

    // configure global opengl state
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader program
    Shader ourShader("assets/shaders/shader.vs", "assets/shaders/shader.fs");

    Model cube1(CUBE, glm::vec3(0.0f, 0.0f, 0.0f));
    Model cube2(CUBE, glm::vec3(1.0f, 0.0f, 0.0f));

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, cubesList[0].GetVerticesSize(), cubesList[0].GetVertices(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

	Texture wallTexture("assets/images/wallTexture.png");
	Texture testTexture("assets/images/testTexture.png");

    ourShader.use();
    ourShader.setInt("texture", 0);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
	UpdateDt();

        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.use();

        // update projection using current framebuffer size
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glm::mat4 projection = glm::perspective(glm::radians(fov), (float)display_w / (float)display_h, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        ourShader.setMat4("view", view);

        glBindVertexArray(VAO);
        for (unsigned int i = 0; i < cubesNumber; i++)
        {
		if(i % 2 == 0){wallTexture.SetActiveTexture();}
		else{testTexture.SetActiveTexture();}

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubesList[i].GetPos());
            float angle = 0.0f;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            ourShader.setMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
