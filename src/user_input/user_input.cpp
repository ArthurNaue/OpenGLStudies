#include "user_input/user_input.hpp"

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){glfwSetWindowShouldClose(window, true);}

	float cameraSpeed = static_cast<float>(2.5 * dt);
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){cameraPos+=cameraSpeed*cameraFront;}
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;}
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){cameraPos-=cameraSpeed*cameraFront;}
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;}
}
