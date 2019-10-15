#include "vertex_buffer.h"

namespace dg { namespace graphics {

	VertexBuffer::VertexBuffer(float* vertices, unsigned int size)
	{
		glGenBuffers(1, &buffer_id);
		glBindBuffer(GL_ARRAY_BUFFER, buffer_id);

		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &buffer_id);
	}

	void VertexBuffer::setLayout(const BufferLayout& s_layout)
	{
		layout = s_layout;
	}

	const BufferLayout& VertexBuffer::getLayout()
	{
		return layout;
	}

	void VertexBuffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
	}

	void VertexBuffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

} }