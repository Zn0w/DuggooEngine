#shader vertex
#version 410 core

layout(location = 0) in vec3 position;

void main()
{
	gl_Position = vec4(position, 1.0);
};

#shader fragment
#version 410 core

layout(location = 0) out vec4 color;

void main()
{
	color = vec4(1.0, 0.1, 0.1, 1.0);
};

// Basic test shader to test the Shader class, color of the polygon is set to (1.0, 0.1, 0.1, 1.0)