#include "vertex_array.h"


namespace dg { namespace graphics {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &array_id);
		glBindVertexArray(array_id);
	}

	VertexArray::~VertexArray()
	{
		for (VertexBuffer* vb : vbs)
			delete vb;

		glDeleteVertexArrays(1, &array_id);
	}

	void VertexArray::addVertexBuffer(VertexBuffer* buffer, unsigned int layout_index)
	{
		glBindVertexArray(array_id);
		buffer->bind();

		glEnableVertexAttribArray(layout_index);
		glVertexAttribPointer(layout_index, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	}
	
	void VertexArray::bind()
	{
		glBindVertexArray(array_id);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}

} }