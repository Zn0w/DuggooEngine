#include "gl_indexbuffer.h"

namespace dg { namespace graphics {

	IndexBuffer::IndexBuffer(GLushort* data, GLsizei s_count)
	{
		count = s_count;

		glGenBuffers(1, &bufferId);		// generate buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);		// unbind buffer (second argument means unbind everything)

	}

	void IndexBuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
	}

	void IndexBuffer::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

} }