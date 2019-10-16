#include "vertex_array.h"


namespace dg { namespace graphics {

	static GLenum ShaderDataType_to_OpenglBaseType(graphics::ShaderDataType type)
	{
		switch (type)
		{
		case graphics::ShaderDataType::FLOAT:
		case graphics::ShaderDataType::FLOAT2:
		case graphics::ShaderDataType::FLOAT3:
		case graphics::ShaderDataType::FLOAT4:
		case graphics::ShaderDataType::MAT3:
		case graphics::ShaderDataType::MAT4:
			return GL_FLOAT;

		case graphics::ShaderDataType::INT:
		case graphics::ShaderDataType::INT2:
		case graphics::ShaderDataType::INT3:
		case graphics::ShaderDataType::INT4:
			return GL_INT;

		case graphics::ShaderDataType::BOOL:	return GL_BOOL;


		default:
			printf("Unknown shader data type\n");
			return 0;
		}
	}
	
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &array_id);
		glBindVertexArray(array_id);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &array_id);
	}

	void VertexArray::addVertexBuffer(VertexBuffer* vertex_buffer)
	{
		glBindVertexArray(array_id);
		vertex_buffer->bind();

		unsigned int index = 0;
		for (const graphics::BufferElement& element : vertex_buffer->getLayout())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.getComponentCount(),
				ShaderDataType_to_OpenglBaseType(element.type),
				element.normalized ? GL_TRUE : GL_FALSE,
				vertex_buffer->getLayout().getStride(),
				(const void*)element.offset
			);
			index++;
		}
		vbs.push_back(vertex_buffer);
	}

	void VertexArray::setIndexBuffer(IndexBuffer* index_buffer)
	{
		glBindVertexArray(array_id);
		index_buffer->bind();

		ib = index_buffer;
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