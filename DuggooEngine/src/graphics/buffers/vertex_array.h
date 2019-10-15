#pragma once

#include <vector>

#include <glad/glad.h>

#include "vertex_buffer.h"
#include "indexbuffer.h"
#include "buffer_layout.h"


namespace dg { namespace graphics {

	class VertexArray
	{
	private:
		unsigned int array_id;
		std::vector<VertexBuffer*> vbs;
		IndexBuffer* ib;

	public:
		VertexArray();
		~VertexArray();

		void addVertexBuffer(VertexBuffer* buffer, unsigned int layout_index);
		void setIndexBuffer(IndexBuffer* buffer);

		void bind();
		void unbind();
	};

} }