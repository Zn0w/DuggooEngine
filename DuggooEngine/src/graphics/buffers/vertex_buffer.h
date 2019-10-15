#pragma once

#include <glad/glad.h>

#include "buffer_layout.h"


namespace dg { namespace graphics {

	class VertexBuffer
	{
	private:
		unsigned int buffer_id;
		BufferLayout layout;
		
	public:
		VertexBuffer(float* data, unsigned int size);
		~VertexBuffer();

		void setLayout(const BufferLayout& layout);
		const BufferLayout& getLayout();

		void bind();
		void unbind();
	};

} }