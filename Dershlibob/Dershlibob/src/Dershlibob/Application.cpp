#include <iostream>
#include "Application.h"

#include "glad\glad.h"
#include "GLFW\glfw3.h"

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"

#include "Dershlibob\Rendering\OpenGL\Renderer.h"
#include "Dershlibob\Rendering\OpenGL\VertexBufferLayout.h"

#include "Dershlibob\Rendering\OpenGL\Texture.h"

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace DB
{
	Application::Application()
	{
		InitApplication();
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			cout << "hi" << endl;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		glfwSwapInterval(2);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		float positions[] = {
			100.0f,  100.0f, 0.0f, 0.0f,
			200.0f,  100.0f, 1.0f, 0.0f,
			200.0f,  200.0f, 1.0f, 1.0f,
			100.0f,  200.0f, 0.0f, 1.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC1_ALPHA);

		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));
		glm::mat4 mvp = proj * view * model;
		
		Shader shader("Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Colour", 0.8f, 0.3f, 0.8f, 1.0f);
		shader.SetUniformMat4f("u_MVP", mvp);

		Texture texture("Mario.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture,", 0);

		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();

		Renderer renderer;

		float r = 0.0f;
		float increment = 0.05f;

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();

			shader.Bind();
			shader.SetUniform4f("u_Colour", r, 0.3f, 0.8f, 1.0f);

			renderer.Draw(va, ib, shader);

			if (r > 1.0f)
				increment = -0.05f;
			else if (r < 0.0f)
				increment = 0.05f;

			r += increment;

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();

	}

	void Application::InitApplication()
	{

	}
}