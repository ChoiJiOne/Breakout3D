#version 460 core

layout(location = 0) in vec2 inTexCoords;

layout(location = 0) out vec4 outColor;

layout(binding = 0) uniform sampler2D hdrFrameBuffer;

uniform float exposure;

void main()
{
	const float gamma = 2.2f;

	vec3 hdrRGB = texture(hdrFrameBuffer, inTexCoords).rgb;

	vec3 resultRGB = vec3(1.0f) - exp(-hdrRGB * exposure);
	resultRGB = pow(resultRGB, vec3(1.0f / gamma));

	outColor = vec4(resultRGB, 1.0f);
}