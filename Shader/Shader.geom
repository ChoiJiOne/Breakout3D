#version 460 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

layout(location = 0) in vec2 inTexCoords[];
layout(location = 0) out vec2 outTexCoords;

uniform float time;

vec3 GetNormal()
{
	vec3 a = vec3(gl_in[0].gl_Position) - vec3(gl_in[1].gl_Position);
	vec3 b = vec3(gl_in[2].gl_Position) - vec3(gl_in[1].gl_Position);
	return normalize(cross(a, b));
}

vec4 explode(in vec4 position, in vec3 normal)
{
	float magnitude = 2.0f;
	vec3 direction = normal * time * magnitude;
	return position + vec4(direction, 0.0f);
}

void main()
{
	vec3 normal = GetNormal();

	gl_Position = explode(gl_in[0].gl_Position, normal);
	outTexCoords = inTexCoords[0];
	EmitVertex();

	gl_Position = explode(gl_in[1].gl_Position, normal);
	outTexCoords = inTexCoords[1];
	EmitVertex();

	gl_Position = explode(gl_in[2].gl_Position, normal);
	outTexCoords = inTexCoords[2];
	EmitVertex();

	EndPrimitive();
}