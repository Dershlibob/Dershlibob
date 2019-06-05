#include "Window.h"

#include "glad\glad.h"
#include "GLFW\glfw3.h"

Window::Window()
{
	/* Initialize the library */
	if (!glfwInit())
		__debugbreak();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "Dershlibob Engine", NULL, NULL);
	glfwSetWindowPos(window, 500, 200);
	if (!window)
	{
		glfwTerminate();
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSwapInterval(2);
}

int Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void Window::WindowUpdate()
{
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();
}

Window::~Window()
{

}

Window* Window::instance = 0;

Window* Window::getInstance()
{
	if (instance == 0)
	{
		instance = new Window();
	}

	return instance;
}