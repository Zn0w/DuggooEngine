#include "shader.h"


namespace dg { namespace graphics {

Shader::Shader(const char* filepath)
{
	parseShader(filepath);
	renderer_id = createShader();
}

Shader::~Shader()
{
	glDeleteProgram(renderer_id);
}

void Shader::parseShader(const char* filepath)
{
	enum ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::stringstream ss[2]; // 2 streams to store vertex and fragment code

	std::istringstream stream(readFile(filepath));
	std::string line;
	ShaderType type = NONE;
	while (std::getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = VERTEX;
			if (line.find("fragment") != std::string::npos)
				type = FRAGMENT;
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}

	vertex_shader = ss[0].str();
	fragment_shader = ss[1].str();

	printf("Vertex shader:\n%s\nFragment shader:\n%s", vertex_shader.c_str(), fragment_shader.c_str());
}

unsigned int Shader::compileShader(unsigned int shader_type, const char* source)
{
	unsigned int id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	int compile_status;
	glGetShaderiv(id, GL_COMPILE_STATUS, &compile_status);
	if (compile_status == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		// alloca allocates memory on the stack (maybe use more secure malloca)
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		printf("Failed to compile shader:\n%s\n", message);
	}

	return id;
}

unsigned int Shader::createShader()
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertex_shader.c_str());
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragment_shader.c_str());

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	// after linking tham to a program, we don't need those in memory any more
	glDetachShader(program, vs);
	glDetachShader(program, fs);
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

void Shader::bind()
{
	glUseProgram(renderer_id);
}

void Shader::unbind()
{
	glUseProgram(0);
}

int Shader::getUniformLocation(const char* name)
{
	int location = glGetUniformLocation(renderer_id, name);
	if (location == -1)
		printf("Warning: uniform %s doesn't exist\n", name);
	return location;
}

void Shader::setUniform4f(const char* name, float v0, float v1, float v2, float v3)
{
	glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

} }