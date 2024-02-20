#include <array>

#include <glad/glad.h>

#include "Assertion.h"
#include "FrameBuffer.h"
#include "PostEffectPass.h"


PostEffectShader::~PostEffectShader()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void PostEffectShader::Initialize(const std::string& fsPath)
{
	CHECK(!bIsInitialized_);

	std::string vsPath = "Shader/PostEffectPass.vert";

	Shader::Initialize(vsPath, fsPath);

	std::array<float, 30> vertices = 
	{
		// position          // uv
		-1.0f, +1.0f, 0.0f,  0.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,  0.0f, 1.0f,
		+1.0f, +1.0f, 0.0f,  1.0f, 0.0f,
		+1.0f, +1.0f, 0.0f,  1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,  0.0f, 1.0f,
		+1.0f, -1.0f, 0.0f,  1.0f, 1.0f,
	};
	uint32_t stride = static_cast<uint32_t>(5 * sizeof(float));

	GL_FAILED(glGenVertexArrays(1, &vertexArrayObject_));
	GL_FAILED(glGenBuffers(1, &vertexBufferObject_));

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_));
	GL_FAILED(glBufferData(GL_ARRAY_BUFFER, static_cast<uint32_t>(sizeof(float) * vertices.size()), reinterpret_cast<const void*>(vertices.data()), GL_STATIC_DRAW));

	GL_FAILED(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)(0 * sizeof(float))));
	GL_FAILED(glEnableVertexAttribArray(0));

	GL_FAILED(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float))));
	GL_FAILED(glEnableVertexAttribArray(1));

	GL_FAILED(glBindVertexArray(0), "failed to unbind frame buffer vertex array...");
}

void PostEffectShader::Release()
{
	CHECK(bIsInitialized_);

	GL_FAILED(glDeleteBuffers(1, &vertexBufferObject_));
	GL_FAILED(glDeleteVertexArrays(1, &vertexArrayObject_));

	Shader::Release();
}

void PostEffectShader::Blit(FrameBuffer* framebuffer)
{
	framebuffer->Active(0);

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glDrawArrays(GL_TRIANGLES, 0, 6));
	GL_FAILED(glBindVertexArray(0));
}