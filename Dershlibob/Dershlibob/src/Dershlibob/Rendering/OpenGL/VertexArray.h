#pragma once

#include "vertexBuffer.h"
#include "Dershlibob\core.h"

class VertexBufferLayout;

class DERSHLIBOB_API VertexArray
{
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;
};