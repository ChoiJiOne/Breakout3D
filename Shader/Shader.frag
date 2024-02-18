#version 460 core

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoords;

layout(location = 0) out vec4 outColor;

layout(binding = 0) uniform sampler2D albedoMap;

uniform vec3 lightPosition;
uniform vec3 viewPosition;

void main()
{
	vec3 albedo = texture(albedoMap, inTexCoords).rgb;

	// ambient
	vec3 ambientRGB = 0.05 * albedo;

	// diffuse
	vec3 lightDirection = normalize(lightPosition - inWorldPosition);
	vec3 normal = normalize(inNormal);
	float diff = max(dot(lightDirection, normal), 0.0f);
	vec3 diffuseRGB = diff * albedo;

	// specular
	vec3 viewDirection = normalize(viewPosition - inWorldPosition);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	vec3 halfwayDirection = normalize(lightDirection + viewDirection);
	float spec = pow(max(dot(normal, halfwayDirection), 0.0f), 32.0f);
	vec3 specularRGB = vec3(0.6f) * spec;

	outColor = vec4(ambientRGB + diffuseRGB + specularRGB, 1.0f);

	float gamma = 2.2;
	outColor.rgb = pow(outColor.rgb, vec3(1.0f / gamma));
}