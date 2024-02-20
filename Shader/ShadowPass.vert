#version 460 core

layout(location = 0) in vec3 inPosition;

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * world * vec4(inPosition, 1.0f);
}