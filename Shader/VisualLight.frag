#version 460 core

layout(location = 0) out vec4 outColor;

uniform vec4 lightColor;

void main()
{
	outColor = lightColor;
}