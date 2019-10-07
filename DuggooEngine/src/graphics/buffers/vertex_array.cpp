#include "vertex_array.h"

#include <vector>

#include <glad/glad.h>

#include "buffer.h"

namespace dg { namespace graphics {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, arrayId);
	}

	VertexArray::~VertexArray()
	{
		//for (int i = 0; i < buffers.size(); i++)
			//delete buffers[i];
	}

	void VertexArray::addBuffer(Buffer* buffer, GLuint index)
	{
		bind();
		buffer->bind();

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->unbind();
		unbind();
	}
	
	void VertexArray::bind()
	{
		glBindVertexArray(*arrayId);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}

} }