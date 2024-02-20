#version 460 core

layout(location = 0) in vec3 inWorldPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inTexCoords;
layout(location = 3) in vec4 inWorldPositionInLightSpace;

layout(location = 0) out vec4 outColor;

layout(binding = 0) uniform sampler2D albedoMap;
layout(binding = 1) uniform sampler2D shadowMap;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition;

float ComputeShadow(vec4 worldPositionInLightSpace)
{
	vec3 projCoords = worldPositionInLightSpace.xyz / worldPositionInLightSpace.w;
	projCoords = projCoords * 0.5f + 0.5f;

	float closestDepth = texture(shadowMap, projCoords.xy).r;
	float currentDepth = projCoords.z;
	
	return currentDepth > closestDepth ? 1.0f : 0.0f;
}

void main()
{
	vec3 albedo = texture(albedoMap, inTexCoords).rgb;

	// ambient
	vec3 ambientRGB = 0.3 * lightColor;

	// diffuse
	vec3 lightDirection = normalize(lightPosition - inWorldPosition);
	vec3 normal = normalize(inNormal);
	float diff = max(dot(lightDirection, normal), 0.0f);
	vec3 diffuseRGB = diff * lightColor;

	// specular
	vec3 viewDirection = normalize(viewPosition - inWorldPosition);
	vec3 reflectDirection = reflect(-lightDirection, normal);
	vec3 halfwayDirection = normalize(lightDirection + viewDirection);
	float spec = pow(max(dot(normal, halfwayDirection), 0.0f), 32.0f);
	vec3 specularRGB = spec * lightColor;

	float shadow = ComputeShadow(inWorldPositionInLightSpace);

	outColor = vec4((ambientRGB + (1.0f - shadow) * (diffuseRGB + specularRGB)) * albedo, 1.0f);

	float gamma = 2.2;
	outColor.rgb = pow(outColor.rgb, vec3(1.0f / gamma));
}