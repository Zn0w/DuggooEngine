 #shader vertex
#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 a_Color;

uniform mat4 u_ViewProjection;

out vec3 v_position;
out vec4 v_color;

void main()
{
	v_position = position;
	v_color = a_Color;
	gl_Position = u_ViewProjection * vec4(position, 1.0);
}

#shader fragment
#version 410 core

layout(location = 0) out vec4 color;

in vec3 v_position;
in vec4 v_color;

void main()
{
	color = vec4(v_position * 0.5 + 0.5, 1.0);
	color = v_color;
}

// Set color of the pixel to it's position vector / 2 + 0.5 (since the colors are within [0, 1] range and position axis coordinates are in [-1, 1] range)