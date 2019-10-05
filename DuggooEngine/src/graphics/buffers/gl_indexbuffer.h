#pragma once

#include <glad/glad.h>

namespace dg { namespace graphics {

	class IndexBuffer
	{
	private:
		GLuint bufferId;
		GLuint count;
	public:
		IndexBuffer(GLushort* data, GLsizei s_count);

		void bind();
		void unbind();

		GLuint getCount() { return count; }
	};

} }