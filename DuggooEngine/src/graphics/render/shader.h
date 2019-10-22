#pragma once

#include <glad/glad.h>
#include <string>
#include <stdio.h>
#include <sstream>

#include <glm.hpp>

#include "../../utils/file_io.h"


// TODO: cache uniform locations in unordered map

namespace dg { namespace graphics {

	class Shader
	{
		unsigned int renderer_id;
		std::string vertex_shader, fragment_shader;

	public:
		Shader(const char* filepath);
		~Shader();

		void createShader();

		void bind();
		void unbind();

		void setUniform4f(const char* name, float v0, float v1, float v2, float v3);
		void uploadUniformMat4f(const char* name, const glm::mat4& matrix);
		
	private:
		void parseShader(const char* filepath);
		unsigned int compileShader(unsigned int shader_type, const char* source);

		int getUniformLocation(const char* name);
	};

} }