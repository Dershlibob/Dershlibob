#include "Camera.h"
#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include <iostream>
#include "Window.h"
#include <math.h>

Camera* cam;


Camera::Camera()
{
	cam = this;
	view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	proj = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);

	cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraDirection = glm::normalize(cameraPos - cameraTarget);
	
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraRight = glm::normalize(glm::cross(up, cameraDirection));
	cameraUp = glm::cross(cameraDirection, cameraRight);

	cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);

	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

Camera::~Camera()
{

}

void WrapperFunc(GLFWwindow* window, double xpos, double ypos) {
	if (cam)
	{
		cam->mouse_callback(window, xpos, ypos);
	}
};

void Camera::UpdateCamera()
{
	Window* window = Window::getInstance();
	processInput(window->window);
	
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::processInput(GLFWwindow *window)
{
	glfwSetCursorPosCallback(window, WrapperFunc);

	float cameraSpeed = 4.0f * deltaTime; // adjust accordingly
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void Camera::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (bMouseFirst)
	{
		lastX = xpos;
		lastY = ypos;
		bMouseFirst = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.15f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	yaw = std::fmod((yaw + xoffset), (GLfloat)360.0f);
	
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}