#pragma once

#include "Dershlibob\core.h"

class DERSHLIBOB_API VertexBuffer
{
private:
	unsigned int m_renderer_ID;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};