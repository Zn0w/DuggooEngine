#include "indexbuffer.h"

namespace dg { namespace graphics {

	IndexBuffer::IndexBuffer(unsigned int* indices, unsigned int s_count)
		: count(s_count)
	{
		glGenBuffers(1, &buffer_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, s_count * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &buffer_id);
	}

	void IndexBuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
	}

	void IndexBuffer::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

} }