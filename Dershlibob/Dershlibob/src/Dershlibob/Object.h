#pragma once

#include "Dershlibob\Rendering\OpenGL\Renderer.h"
#include "Dershlibob\Rendering\OpenGL\Texture.h"
#include "Dershlibob\Rendering\OpenGL\Camera.h"

#include "Dershlibob\core.h"

#include <vector>

enum ObjectType
{
	SQUARE,
	CUBE
};

class DERSHLIBOB_API Object
{
private:
	int ObjectType;
	Camera* camera;
	Texture* texture;

public:

	glm::vec3 Position;

	void Update(const VertexArray& va, const IndexBuffer& ib, Shader& shader);
	Object(int ObjType, Camera* camera);
	~Object();
private:
	IndexBuffer* ib;
	VertexArray* va;

	// Only used for models. not for primitive objects.
	std::vector<float> Positions;
	std::vector<unsigned int> Indices;
};