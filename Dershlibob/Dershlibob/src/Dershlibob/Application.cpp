// xcopy /y /d "$(OutDir)Dershlibob.dll" "$(OutDir)..\Sandbox"

#include <iostream>

#include "Application.h"
#include "Object.h"

#include "Dershlibob\Rendering\OpenGL\Window.h"
#include "Dershlibob\Rendering\OpenGL\Camera.h"
#include "Dershlibob\Rendering\OpenGL\Renderer.h"
#include "Dershlibob\Rendering\OpenGL\VertexBufferLayout.h"
#include "Dershlibob\Rendering\OpenGL\Texture.h"
#include "Dershlibob\Rendering\OpenGL\Model.h"

#include "GLFW\glfw3.h"

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"

#include "glad\glad.h"

#include "assimp\cimport.h"
#include "assimp\scene.h"
#include "assimp\postprocess.h"

using namespace std;

namespace DB
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		Window* window = Window::getInstance();
		Camera camera;
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		Renderer* renderer = Renderer::getInstance();
		Object TestObj(0, &camera);
		Model MyModel("models/crysis/nanosuit.obj");

		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC1_ALPHA);
		glEnable(GL_DEPTH_TEST);

		VertexArray va;
		VertexBuffer vb(renderer->SquarePositions, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		
		va.AddBuffer(vb, layout);
		
		IndexBuffer ib(renderer->SquareIndices, 6);
		
		glm::vec3 translationA(0, 0, 0);
		glm::vec3 translationB(2, 0, 0);
		glm::vec3 translationC(1, 4, 0);
		glm::vec3 translationD(3, 0, 0);
		
		Shader shader("Basic.shader");
		shader.Bind();
		
		Texture texture("res/textures/Mario.png");
		Texture texture2("res/textures/Luigi.png");
		Texture texture3("Circle.jpg");
		shader.SetUniform1i("u_Texture", 0);
		
		va.Unbind();
		vb.Unbind();
		ib.Unbind();
		shader.Unbind();
		
		//VertexArray TBPArray;
		//VertexBuffer TBPBuffer(renderer->TriangleBasedPyramidVertices, 5 * 4 * sizeof(float));
		//VertexBufferLayout TBPLayout;
		//TBPLayout.Push<float>(3);
		//TBPLayout.Push<float>(2);
		//
		//TBPArray.AddBuffer(TBPBuffer, TBPLayout);
		//
		//IndexBuffer TBPIndex(renderer->TriangleBasedPyramidIndices, 12);
		//
		//Shader lightingShader("Lighting.shader");
		//lightingShader.Bind();
		//
		//lightingShader.SetUniform3f("objectColour", 1.0f, 0.5f, 0.31f);
		//lightingShader.SetUniform3f("lightColour", 1.0f, 1.0f, 1.0f);
		//
		//TBPArray.Unbind();
		//TBPBuffer.Unbind();
		//TBPIndex.Unbind();
		//lightingShader.Unbind();

		Shader ModelShader("Model.shader");
		ModelShader.Bind();


		/* Loop until the user closes the window */
		while (!window->ShouldClose())
		{
			camera.UpdateCamera();
			/* Render here */
			renderer->Clear();
			//{
			//	texture.Bind();
			//	glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
			//	glm::mat4 mvp = camera.proj * camera.view * model;
			//	shader.Bind();
			//	shader.SetUniformMat4f("u_MVP", mvp);
			//	renderer->Draw(va, ib, shader);
			//}
			//{
			//	texture2.Bind();
			//	glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
			//	glm::mat4 mvp = camera.proj * camera.view * model;
			//	shader.Bind();
			//	shader.SetUniformMat4f("u_MVP", mvp);
			//	renderer->Draw(va, ib, shader);
			//}
			{
				//texture.Bind();
				//glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
				//glm::mat4 mvp = camera.proj * camera.view * model;
				//shader.Bind();
				//shader.SetUniformMat4f("u_MVP", mvp);
				//renderer->Draw(TBPArray, TBPIndex, shader);
			}
			{
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translationD);
				glm::mat4 mvp = camera.proj * camera.view * model;
				ModelShader.Bind();
				ModelShader.SetUniformMat4f("u_MVP", mvp);
				MyModel.Draw(ModelShader);
			}
			//TestObj.Update(va, ib, shader);
			window->WindowUpdate();
		}
		glfwTerminate();
	}
}