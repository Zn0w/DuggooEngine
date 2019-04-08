#pragma once

#include "glad/glad.h"

#include "../../../utils/file_io.h"

namespace dg { namespace graphics {

	class Shader
	{
	private:
		GLuint shaderId;				// Shader id, used when there is need to fetch a shader from opengl
		const char* vertexShaderPath;	// The whole vertex
		const char* fragmentShaderPath;	// Only one component of the vertex (dot)
	
	public:
		Shader(const char* s_vertexShaderPath, const char* s_fragmentShaderPath);
		~Shader();

		void enable();
		void disable();

	private:
		GLuint load();
	};

} }