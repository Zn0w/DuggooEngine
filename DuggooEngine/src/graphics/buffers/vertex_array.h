#pragma once

#include <vector>

#include <glad/glad.h>

#include "vertex_buffer.h"


namespace dg { namespace graphics {

	class VertexArray
	{
	private:
		unsigned int array_id;
		std::vector<VertexBuffer*> vbs;

	public:
		VertexArray();
		~VertexArray();

		void addBuffer(VertexBuffer* buffer, unsigned int layout_index);
		void bind();
		void unbind();
	};

} }