#pragma once

#include "glad\glad.h"
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Dershlibob\core.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) \
{\
	GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))\
}\

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class DERSHLIBOB_API Renderer
{
public:
	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

	void Draw(const VertexArray & va, const Shader & shader) const;
	
	static Renderer* getInstance();

	float SquarePositions[16]{
		-1.0f,  -1.0f, 0.0f, 0.0f,
		1.0f,  -1.0f, 1.0f, 0.0f,
		1.0f,  1.0f, 1.0f, 1.0f,
		-1.0f,  1.0f, 0.0f, 1.0f
	};
	 unsigned int SquareIndices[6]{
		0, 1, 2,
		2, 3, 0
	};

	 float CubePositions[8 * 3]{
		 -1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, 1.0f, -1.0f,
		 -1.0f, 1.0f, -1.0f,
		 -1.0f, -1.0f, 1.0f,
		 1.0f, -1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 -1.0f, 1.0f, 1.0f
	 };

	 unsigned int CubeIndices[6 * 6]{
		 0, 1, 3, 3, 1, 2,
		 1, 5, 2, 2, 5, 6,
		 5, 4, 6, 6, 4, 7,
		 4, 0, 7, 7, 0, 3,
		 3, 2, 7, 7, 2, 6,
		 4, 5, 0, 0, 5, 1
	 };

	 float TriangleBasedPyramidVertices[5 * 4]{
		 -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		 0.0f, -0.5f, 0.5f, 0.0f, 1.0f,
		 0.0f, 0.5f, 0.0f, 1.0f, 1.0f
	 };

	 unsigned int TriangleBasedPyramidIndices[12]{
		 0, 1, 2,
		 0, 3, 2,
		 3, 1, 2,
		 0, 1, 3
	 };
private:
	static Renderer* instance;
};