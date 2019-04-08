#include "gl_shader.h"

#include <vector>

#include "../../../log/log.h"

namespace dg { namespace graphics {

	Shader::Shader(const char* s_vertexShaderPath, const char* s_fragmentShaderPath)
		: vertexShaderPath(s_vertexShaderPath), fragmentShaderPath(s_fragmentShaderPath)
	{
		shaderId = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(shaderId);
	}

	void Shader::enable()
	{
		glUseProgram(shaderId);
	}

	void Shader::disable()
	{
		glUseProgram(0);
	}

	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		const char* vertexSource = readFile(vertexShaderPath).c_str();
		const char* fragmentSource = readFile(fragmentShaderPath).c_str();

		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);

			LOG_ERROR("Failed to compile vertex shader:");
			LOG_ERROR(&error[0]);
			
			glDeleteShader(vertex);

			return 0;
		}

		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);


		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);

			LOG_ERROR("Failed to compile fragment shader:");
			LOG_ERROR(&error[0]);

			glDeleteShader(fragment);

			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

} }