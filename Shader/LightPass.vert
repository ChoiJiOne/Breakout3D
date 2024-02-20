#version 460 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoords;

layout(location = 0) out vec3 outWorldPosition;
layout(location = 1) out vec3 outNormal;
layout(location = 2) out vec2 outTexCoords;
layout(location = 3) out vec4 outWorldPositionInLightSpace;

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 lightView;
uniform mat4 lightProjection;

void main()
{
	gl_Position = projection * view * world * vec4(inPosition, 1.0f);

	vec4 worldPosition = world * vec4(inPosition, 1.0f);

	outWorldPosition = worldPosition.xyz;
	outNormal = mat3(transpose(inverse(world))) * inNormal;
	outTexCoords = inTexCoords;
	outWorldPositionInLightSpace = lightProjection * lightView * worldPosition;
}