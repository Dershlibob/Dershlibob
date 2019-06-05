#include "Object.h"
#include <iostream>


Object::Object(int ObjType, Camera* camera) :
	ObjectType(ObjType),
	camera(camera)
{
	Renderer* renderer = Renderer::getInstance();
	Position = glm::vec3(4, 2, 3);
	texture = new Texture("Circle.jpg");

	if (ObjectType == SQUARE)
	{

	}
}

Object::~Object()
{

}

void Object::Update(const VertexArray& va, const IndexBuffer& ib, Shader& shader)
{
	//Shader* shaderObj = Shader::getInstance("Basic.shader");
	Renderer* renderer = Renderer::getInstance();

	texture->Bind();
	glm::mat4 model = glm::translate(glm::mat4(1.0f), Position);
	glm::mat4 mvp = camera->proj * camera->view * model;
	shader.Bind();
	shader.SetUniformMat4f("u_MVP", mvp);
	renderer->Draw(va, ib, shader);
}