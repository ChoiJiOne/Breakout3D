#include <glad/glad.h>

#include "Assertion.h"
#include "Skybox.h"
#include "SkyboxPass.h"

SkyboxPass::~SkyboxPass()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void SkyboxPass::Initialize()
{
	CHECK(!bIsInitialized_);

	std::string vsPath = "Shader/Skybox.vert";
	std::string fsPath = "Shader/Skybox.frag";

	Shader::Initialize(vsPath, fsPath);

	std::vector<float> vertices =
	{
		-1.0f, +1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		+1.0f, -1.0f, -1.0f,
		+1.0f, -1.0f, -1.0f,
		+1.0f, +1.0f, -1.0f,
		-1.0f, +1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, +1.0f, -1.0f,
		-1.0f, +1.0f, -1.0f,
		-1.0f, +1.0f, +1.0f,
		-1.0f, -1.0f, +1.0f,

		+1.0f, -1.0f, -1.0f,
		+1.0f, -1.0f, +1.0f,
		+1.0f, +1.0f, +1.0f,
		+1.0f, +1.0f, +1.0f,
		+1.0f, +1.0f, -1.0f,
		+1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		+1.0f,  1.0f,  1.0f,
		+1.0f,  1.0f,  1.0f,
		+1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		+1.0f,  1.0f, -1.0f,
		+1.0f,  1.0f,  1.0f,
		+1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		+1.0f, -1.0f, -1.0f,
		+1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		+1.0f, -1.0f,  1.0f
	};
	vertexCount_ = static_cast<uint32_t>(vertices.size());

	GL_FAILED(glGenVertexArrays(1, &vertexArrayObject_));
	GL_FAILED(glGenBuffers(1, &vertexBufferObject_));
	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_));
	GL_FAILED(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * static_cast<uint32_t>(vertices.size()), vertices.data(), GL_STATIC_DRAW));

	GL_FAILED(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0)));
	GL_FAILED(glEnableVertexAttribArray(0));

	GL_FAILED(glBindVertexArray(0));
}

void SkyboxPass::Release()
{
	CHECK(bIsInitialized_);

	GL_FAILED(glDeleteBuffers(1, &vertexBufferObject_));
	GL_FAILED(glDeleteVertexArrays(1, &vertexArrayObject_));

	Shader::Release();
}

void SkyboxPass::Draw(const Matrix4x4f& view, const Matrix4x4f& projection, const Skybox* skybox)
{
	Bind();
	GL_FAILED(glDepthFunc(GL_LEQUAL));

	SetUniform("view", view);
	SetUniform("projection", projection);

	skybox->Active(0);

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glDrawArrays(GL_TRIANGLES, 0, vertexCount_));
	GL_FAILED(glBindVertexArray(0));

	GL_FAILED(glDepthFunc(GL_LESS));
	Unbind();
}