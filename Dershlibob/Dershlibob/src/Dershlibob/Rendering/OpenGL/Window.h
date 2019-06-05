#pragma once

#include "Dershlibob\core.h"

struct GLFWwindow;

class DERSHLIBOB_API Window
{
public:
	~Window();
	void WindowUpdate();
	int ShouldClose();

	friend class Camera;

	static Window* getInstance();

private:
	GLFWwindow* window;
	Window();
	static Window* instance;
};