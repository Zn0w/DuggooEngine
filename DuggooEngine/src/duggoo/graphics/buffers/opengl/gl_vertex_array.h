#pragma once

#include <vector>

#include "gl_buffer.h"

namespace dg { namespace graphics {

	class VertexArray
	{
	private:
		GLuint* arrayId;
		std::vector<Buffer*> buffers;

	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, GLuint index);
		void bind();
		void unbind();
	};

} }