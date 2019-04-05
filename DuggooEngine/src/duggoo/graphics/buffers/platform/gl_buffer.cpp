#include "gl_buffer.h"

namespace dg { namespace graphics {

	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint s_componentCount)	// count is the number of elements in the array (buffer)
	{
		componentCount = s_componentCount;

		glGenBuffers(1, &bufferId);		// generate buffer
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);		// unbind buffer (second argument means unbind everything)

	}

	void Buffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	}

	void Buffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);		// 0 means no buffer (unbind the binded buffer)
	}

} }