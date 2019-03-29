#pragma once

#include <glad/glad.h>

namespace dg { namespace graphics {

	class Buffer
	{
	private:
		GLuint bufferId;
		GLuint componentCount;
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint s_componentCount);

		void bind();
		void unbind();

		GLuint getComponentCount() { return componentCount; }
	};

} }