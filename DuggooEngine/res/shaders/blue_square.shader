#shader vertex
#version 410 core

layout(location = 0) in vec3 position;

uniform mat4 u_ViewProjection;

out vec3 v_position;

void main()
{
	v_position = position;
	gl_Position = u_ViewProjection * vec4(position, 1.0);
}

#shader fragment
#version 410 core

layout(location = 0) out vec4 color;

in vec3 v_position;

void main()
{
	color = vec4(0.2, 0.3, 0.8, 1.0);
}