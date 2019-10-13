#pragma once

#include <glad/glad.h>

namespace dg { namespace graphics {

	class VertexBuffer
	{
	private:
		unsigned int buffer_id;
		
	public:
		VertexBuffer(float* data, unsigned int size);
		~VertexBuffer();

		void bind();
		void unbind();
	};

} }