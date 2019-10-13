#include "vertex_array.h"


namespace dg { namespace graphics {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &array_id);
	}

	VertexArray::~VertexArray()
	{
		for (VertexBuffer* vb : vbs)
			delete vb;

		glDeleteVertexArrays(1, &array_id);
	}

	void VertexArray::addBuffer(VertexBuffer* buffer, unsigned int layout_index)
	{
		
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