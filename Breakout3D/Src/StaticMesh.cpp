#include <glad/glad.h>

#include "Assertion.h"
#include "StaticMesh.h"

StaticMesh::~StaticMesh()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void StaticMesh::Initialize(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices)
{
	CHECK(!bIsInitialized_);

	vertices_ = vertices;
	indices_ = indices;

	const void* vertexBufferPtr = reinterpret_cast<const void*>(vertices_.data());
	uint32_t vertexBufferSize = static_cast<uint32_t>(vertices_.size()) * Vertex::GetStride();

	const void* indexBufferPtr = reinterpret_cast<const void*>(indices_.data());
	uint32_t indexBufferSize = static_cast<uint32_t>(indices_.size()) * sizeof(uint32_t);

	GL_FAILED(glGenVertexArrays(1, &vertexArrayObject_));
	GL_FAILED(glGenBuffers(1, &vertexBufferObject_));
	GL_FAILED(glGenBuffers(1, &indexBufferObject_));

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_));
	GL_FAILED(glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, vertexBufferPtr, GL_STATIC_DRAW));
	GL_FAILED(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject_));
	GL_FAILED(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferSize, indexBufferPtr, GL_STATIC_DRAW));

	GL_FAILED(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::GetStride(), Vertex::GetOffsetOfPosition()));
	GL_FAILED(glEnableVertexAttribArray(0));

	GL_FAILED(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, Vertex::GetStride(), Vertex::GetOffsetOfNormal()));
	GL_FAILED(glEnableVertexAttribArray(1));

	GL_FAILED(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, Vertex::GetStride(), Vertex::GetOffsetOfUV()));
	GL_FAILED(glEnableVertexAttribArray(2));

	GL_FAILED(glBindVertexArray(0));

	bIsInitialized_ = true;
}

void StaticMesh::Release()
{
	CHECK(bIsInitialized_);

	GL_FAILED(glDeleteBuffers(1, &indexBufferObject_));
	GL_FAILED(glDeleteBuffers(1, &vertexBufferObject_));
	GL_FAILED(glDeleteVertexArrays(1, &vertexArrayObject_));

	bIsInitialized_ = false;
}

void StaticMesh::Bind()
{
	GL_FAILED(glBindVertexArray(vertexArrayObject_));
}

void StaticMesh::Unbind()
{
	GL_FAILED(glBindVertexArray(0));
}