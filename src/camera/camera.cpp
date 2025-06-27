#include "camera/camera.hpp"

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float fov = 45.0f;

void DrawCamera(GLFWwindow* window, Shader shader)
{
	int displayWidth, displayHeight;
	glfwGetFramebufferSize(window, &displayWidth, &displayHeight);
	glm::mat4 projection = glm::perspective(glm::radians(fov), (float)displayWidth / (float)displayHeight, 0.1f, 100.0f);
	shader.setMat4("projection", projection);

	glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	shader.setMat4("view", view);
}
