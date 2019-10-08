#pragma once

#include <glad/glad.h>
#include <string>
#include <stdio.h>
#include <sstream>

#include "../../utils/file_io.h"


namespace dg { namespace graphics {

	class Shader
	{
		unsigned int renderer_id;
		std::string vertex_shader, fragment_shader;

	public:
		Shader(const char* filepath);
		~Shader();

		unsigned int createShader();

		void bind();
		void unbind();

		void setUniform4f(const char* name, float v0, float v1, float v2, float v3);
		
	private:
		void parseShader(const char* filepath);
		unsigned int compileShader(unsigned int shader_type, const char* source);

		int getUniformLocation(const char* name);
	};

} }