#pragma once

#include "Dershlibob\core.h"

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"

struct GLFWwindow;

class DERSHLIBOB_API Camera
{
public:
	glm::mat4 view;
	glm::mat4 proj;

	glm::vec3 cameraPos;
	glm::vec3 cameraUp;
	glm::vec3 cameraFront;

	glm::vec3 cameraTarget;
	glm::vec3 cameraDirection;

	glm::vec3 up;
	glm::vec3 cameraRight;

	float deltaTime = 0.0f;

	Camera();
	~Camera();

	void UpdateCamera();
	void processInput(GLFWwindow* window);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX = 0.0f, lastY = 0.0f;
	bool bMouseFirst = true;
private:
	float lastFrame = 0.0f;

};