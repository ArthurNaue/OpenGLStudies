#include "dt/dt.hpp"

float dt = 0.0f;
float lastFrame = 0.0f;

void UpdateDt(void)
{
	float currentFrame = static_cast<float>(glfwGetTime());
	dt = currentFrame - lastFrame;
	lastFrame = currentFrame;
}
