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

		void addVertexBuffer(VertexBuffer* vertex_buffer);
		void setIndexBuffer(IndexBuffer* index_buffer);

		inline std::vector<VertexBuffer*> getVertexBuffers() { return vbs; }
		inline IndexBuffer* getIndexBuffer() { return ib; }

		void bind();
		void unbind();
	};

} }