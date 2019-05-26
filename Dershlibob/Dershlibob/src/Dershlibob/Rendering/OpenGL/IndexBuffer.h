#pragma once
#include "Dershlibob\core.h"

class DERSHLIBOB_API IndexBuffer
{
private:
	unsigned int m_renderer_ID;
	unsigned int m_Count;
public:
	IndexBuffer(unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return m_Count; }
};