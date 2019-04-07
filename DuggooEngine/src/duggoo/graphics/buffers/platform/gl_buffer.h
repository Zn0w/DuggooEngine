#pragma once

#include <glad/glad.h>

namespace dg { namespace graphics {

	class OpenglBuffer
	{
	private:
		GLuint bufferId;
		GLuint componentCount;		// The number of elements in one component, e.g. 2.0f, 5.0f, -1.5f, 3.5f can be a 1 vec4, or two vec2s, so the component count specifies it
	public:
		OpenglBuffer(GLfloat* data, GLsizei count, GLuint s_componentCount);

		void bind();		// Select this buffer (a specific buffer will be selected to be used)
		void unbind();		// Unselect the buffer

		GLuint getComponentCount() { return componentCount; }
	};

} }