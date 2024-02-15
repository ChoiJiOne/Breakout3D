#include "MathModule.h"

#include "Assertion.h"
#include "GeometryGenerator.h"

void GeometryGenerator::CreateCube(const Vector3f& size, std::vector<Vertex>& outVertices, std::vector<uint32_t>& outIndices)
{
	outVertices.resize(0);
	outIndices.resize(0);

	static const uint32_t faceCount = 6;
	static const Vector3f faceNormals[faceCount] = 
	{
		Vector3f(+0.0f, +0.0f, +1.0f),
		Vector3f(+0.0f, +0.0f, -1.0f),
		Vector3f(+1.0f, +0.0f, +0.0f),
		Vector3f(-1.0f, +0.0f, +0.0f),
		Vector3f(+0.0f, +1.0f, +0.0f),
		Vector3f(+0.0f, -1.0f, +0.0f),
	};

	static const Vector2f uvs[4] = 
	{
		Vector2f(1.0f, 1.0f),
		Vector2f(1.0f, 0.0f),
		Vector2f(0.0f, 0.0f),
		Vector2f(0.0f, 1.0f),
	};

	Vector3f tsize = Vector3f(size.x * 0.5f, size.y * 0.5f, size.z * 0.5f);

	for (uint32_t face = 0; face < faceCount; ++face)
	{
		const Vector3f& normal = faceNormals[face];
		Vector3f basis = (face >= 4) ? Vector3f(0.0f, 0.0f, 1.0f) : Vector3f(0.0f, 1.0f, 0.0f);

		Vector3f side1 = MathModule::CrossProduct(normal, basis);
		Vector3f side2 = MathModule::CrossProduct(normal, side1);

		const size_t vbase = outVertices.size();
		outIndices.push_back(vbase + 0);
		outIndices.push_back(vbase + 2);
		outIndices.push_back(vbase + 1);

		outIndices.push_back(vbase + 0);
		outIndices.push_back(vbase + 3);
		outIndices.push_back(vbase + 2);

		outVertices.push_back(Vertex(((normal - side1 - side2) * tsize), normal, uvs[0]));
		outVertices.push_back(Vertex(((normal - side1 + side2) * tsize), normal, uvs[1]));
		outVertices.push_back(Vertex(((normal + side1 + side2) * tsize), normal, uvs[2]));
		outVertices.push_back(Vertex(((normal + side1 - side2) * tsize), normal, uvs[3]));
	}
}

void GeometryGenerator::CreateSphere(float radius, uint32_t tessellation, std::vector<Vertex>& outVertices, std::vector<uint32_t>& outIndices)
{
	CHECK(tessellation >= 3);

	outVertices.resize(0);
	outIndices.resize(0);

	const uint32_t verticalSegments = tessellation;
	const uint32_t horizontalSegments = tessellation * 2;

	for (uint32_t vertical = 0; vertical <= verticalSegments; ++vertical)
	{
		float v = 1.0f - static_cast<float>(vertical) / static_cast<float>(verticalSegments);
		float latitude = MathModule::Pi * (static_cast<float>(vertical) / static_cast<float>(verticalSegments)) - MathModule::PiDiv2;
		float dy = MathModule::Sin(latitude);
		float dxz = MathModule::Cos(latitude);

		for (uint32_t horizon = 0; horizon <= horizontalSegments; ++horizon)
		{
			float u = static_cast<float>(horizon) / static_cast<float>(horizontalSegments);
			float longitude = MathModule::TwoPi * static_cast<float>(horizon) / static_cast<float>(horizontalSegments);
			float dx = dxz * MathModule::Sin(longitude);
			float dz = dxz * MathModule::Cos(longitude);

			Vector3f position(radius * dx, radius * dy, radius * dz);
			Vector3f normal(dx, dy, dz);
			Vector2f uv(u, 1.0f - v);

			outVertices.push_back(Vertex(position, normal, uv));
		}
	}

	uint32_t stride = horizontalSegments + 1;
	for (uint32_t vertical = 0; vertical < verticalSegments; ++vertical)
	{
		for (uint32_t horizon = 0; horizon <= horizontalSegments; ++horizon)
		{
			outIndices.push_back((vertical + 0) * stride + (horizon + 0) % stride);
			outIndices.push_back((vertical + 0) * stride + (horizon + 1) % stride);
			outIndices.push_back((vertical + 1) * stride + (horizon + 0) % stride);

			outIndices.push_back((vertical + 0) * stride + (horizon + 1) % stride);
			outIndices.push_back((vertical + 1) * stride + (horizon + 1) % stride);
			outIndices.push_back((vertical + 1) * stride + (horizon + 0) % stride);
		}
	}
}

void GeometryGenerator::CreateCylinder(float radius, float height, uint32_t tessellation, std::vector<Vertex>& outVertices, std::vector<uint32_t>& outIndices)
{
	CHECK(tessellation >= 3);

	outVertices.resize(0);
	outIndices.resize(0);

	height *= 0.5f;

	Vector3f topOffset(0.0f, height, 0.0f);
	uint32_t stride = tessellation + 1;

	for (uint32_t index = 0; index <= tessellation; ++index)
	{
		float angle = MathModule::TwoPi * static_cast<float>(index) / static_cast<float>(tessellation);
		float dx = MathModule::Sin(angle);
		float dz = MathModule::Cos(angle);

		Vector3f normal(dx, 0.0f, dz);
		Vector3f sideOffset(normal.x * radius, normal.y * radius, normal.z * radius);

		Vector2f uv(static_cast<float>(index) / static_cast<float>(tessellation), 0.0f);
		Vector2f uv0 = uv + Vector2f(0.0f, 0.0f);
		Vector2f uv1 = uv + Vector2f(0.0f, 1.0f);

		outVertices.push_back(Vertex(sideOffset + topOffset, normal, Vector2f(uv0.x, 1.0f - uv0.y)));
		outVertices.push_back(Vertex(sideOffset - topOffset, normal, Vector2f(uv1.x, 1.0f - uv1.y)));

		outIndices.push_back((index * 2 + 0));
		outIndices.push_back((index * 2 + 1));
		outIndices.push_back((index * 2 + 2) % (stride * 2));

		outIndices.push_back((index * 2 + 1));
		outIndices.push_back((index * 2 + 3) % (stride * 2));
		outIndices.push_back((index * 2 + 2) % (stride * 2));
	}

	CreateCylinderCap(radius, height, tessellation, true, outVertices, outIndices);
	CreateCylinderCap(radius, height, tessellation, false, outVertices, outIndices);
}

void GeometryGenerator::CreateCylinderCap(float radius, float height, uint32_t tessellation, bool bIsTop, std::vector<Vertex>& outVertices, std::vector<uint32_t>& outIndices)
{
	for (size_t index = 0; index < tessellation - 2; index++)
	{
		size_t i1 = (index + 1) % tessellation;
		size_t i2 = (index + 2) % tessellation;

		if (bIsTop)
		{
			std::swap(i1, i2);
		}

		const size_t vbase = outVertices.size();
		outIndices.push_back(vbase + 0);
		outIndices.push_back(vbase + i2);
		outIndices.push_back(vbase + i1);
	}

	Vector3f normal(0.0f, 1.0f, 0.0f);
	Vector2f textureScale(-0.5f, -0.5f);

	if (!bIsTop)
	{
		normal = Vector3f(0.0f, -1.0f, 0.0f);
		textureScale = Vector2f(0.5f, -0.5f);
	}

	for (size_t index = 0; index < tessellation; ++index)
	{
		float angle = MathModule::TwoPi * static_cast<float>(index) / static_cast<float>(tessellation);
		float dx = MathModule::Sin(angle);
		float dz = MathModule::Cos(angle);

		Vector3f position = Vector3f(dx * radius, normal.y * height, dz * radius);
		Vector2f uv = Vector2f(dx, dz) * textureScale + Vector2f(0.5f, 0.5f);

		outVertices.push_back(Vertex(position, normal, Vector2f(uv.x, 1.0f - uv.y)));
	}
}