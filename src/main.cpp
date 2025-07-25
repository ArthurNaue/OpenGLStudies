#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "shader/shader.hpp"
#include "renderer/renderer.hpp"
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

	Renderer renderer;

	Model cone(CONE, wallTex, glm::vec3(0.0f, 0.0f, 0.0f));
	Model cube(CUBE, testTex, glm::vec3(0.0f, -0.5f, 0.0f));

	renderer.AddInstance(cone);
	renderer.AddInstance(cube);

	ourShader.Use();
	ourShader.SetInt("texture", 0);

	while (!glfwWindowShouldClose(window))
	{
		UpdateDt();

		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ourShader.Use();

		DrawCamera(window, ourShader);

		renderer.DrawAll(ourShader);	

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	renderer.Delete();    

	glfwTerminate();
	return 0;
}
