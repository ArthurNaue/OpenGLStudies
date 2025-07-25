#ifndef WINDOW_CONFIG_HPP
#define WINDOW_CONFIG_HPP

#include <iostream>
#include "camera/camera.hpp"
#include <glm/glm.hpp>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern float lastX;
extern float lastY;
extern float yaw;
extern float pitch;
extern bool firstMouse;

GLFWwindow* InitWindow(void);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xPos, double yPos);
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

#endif
