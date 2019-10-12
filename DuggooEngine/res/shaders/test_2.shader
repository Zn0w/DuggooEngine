#shader vertex
#version 410 core

layout(location = 0) in vec3 position;

out vec3 v_position;

void main()
{
	v_position = position;
	gl_Position = vec4(position, 1.0);
}

#shader fragment
#version 410 core

layout(location = 0) out vec4 color;

in vec3 v_position;

void main()
{
	color = vec4(v_position * 0.5 + 0.5, 1.0);
}

// Set color of the pixel to it's position vector / 2 + 0.5 (since the colors are within [0, 1] range and position axis coordinates are in [-1, 1] range)