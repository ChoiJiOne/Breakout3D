#include <array>

#include <glad/glad.h>

#include "Assertion.h"
#include "FrameBuffer.h"
#include "PostEffectPass.h"

/**
 * @brief 후처리 셰이더 내부에서 사용하는 정점입니다.
 */
struct VertexPositionTexture
{
	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 기본 생성자입니다.
	 */
	VertexPositionTexture() noexcept
		: position_(0.0f, 0.0f, 0.0f)
		, uv_(0.0f, 0.0f) {}


	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치입니다.
	 * @param uv 정점의 텍스처 위치입니다.
	 */
	VertexPositionTexture(Vec3f&& position, Vec2f&& uv) noexcept
		: position_(position)
		, uv_(uv) {}


	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 생성자입니다.
	 *
	 * @param position 정점의 위치입니다.
	 * @param st 정점의 텍스처 위치입니다.
	 */
	VertexPositionTexture(const Vec3f& position, const Vec2f& uv) noexcept
		: position_(position)
		, uv_(uv) {}


	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 생성자입니다.
	 *
	 * @param x 위치의 X좌표입니다.
	 * @param y 위치의 Y좌표입니다.
	 * @param z 위치의 Z좌표입니다.
	 * @param u 텍스처 위치의 U좌표입니다.
	 * @param v 텍스처 위치의 V좌표입니다.
	 */
	VertexPositionTexture(
		float x, float y, float z,
		float u, float v
	) noexcept
		: position_(x, y, z)
		, uv_(u, v) {}


	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점 인스턴스입니다.
	 */
	VertexPositionTexture(VertexPositionTexture&& instance) noexcept
		: position_(instance.position_)
		, uv_(instance.uv_) {}


	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 생성자입니다.
	 *
	 * @param instance 복사할 정점 인스턴스입니다.
	 */
	VertexPositionTexture(const VertexPositionTexture& instance) noexcept
		: position_(instance.position_)
		, uv_(instance.uv_) {}


	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionTexture& operator=(VertexPositionTexture&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 위치와 텍스처 정보를 가진 정점의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	VertexPositionTexture& operator=(const VertexPositionTexture& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 파이트 보폭(Stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(VertexPositionTexture);
	}


	/**
	 * @brief 정점의 위치입니다.
	 */
	Vec3f position_;


	/**
	 * @brief 정점의 텍스처 좌표입니다.
	 */
	Vec2f uv_;
};

PostEffectPass::~PostEffectPass()
{
	if (bIsInitialized_)
	{
		Release();
	}
}

void PostEffectPass::Initialize(const std::string& fsPath)
{
	CHECK(!bIsInitialized_);

	std::string vsPath = "Shader/PostEffectPass.vert";

	Shader::Initialize(vsPath, fsPath);

	std::array<VertexPositionTexture, 6> vertices = {
		VertexPositionTexture(Vec3f(-1.0f, +1.0f, 0.0f), Vec2f(0.0f, 0.0f)),
		VertexPositionTexture(Vec3f(-1.0f, -1.0f, 0.0f), Vec2f(0.0f, 1.0f)),
		VertexPositionTexture(Vec3f(+1.0f, +1.0f, 0.0f), Vec2f(1.0f, 0.0f)),
		VertexPositionTexture(Vec3f(+1.0f, +1.0f, 0.0f), Vec2f(1.0f, 0.0f)),
		VertexPositionTexture(Vec3f(-1.0f, -1.0f, 0.0f), Vec2f(0.0f, 1.0f)),
		VertexPositionTexture(Vec3f(+1.0f, -1.0f, 0.0f), Vec2f(1.0f, 1.0f)),
	};

	//GL_FAILED(glGenVertexArrays(1, &vertexArrayObject_));
	//GL_FAILED(glGenBuffers(1, &vertexBufferObject_));

	//GL_FAILED(glBindVertexArray(vertexArrayObject_));
	//GL_FAILED(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_));
	//GL_FAILED(glBufferData(GL_ARRAY_BUFFER, static_cast<uint32_t>(sizeof(float) * vertices.size()), reinterpret_cast<const void*>(vertices.data()), GL_STATIC_DRAW));

	//GL_FAILED(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)(0 * sizeof(float))));
	//GL_FAILED(glEnableVertexAttribArray(0));

	//GL_FAILED(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float))));
	//GL_FAILED(glEnableVertexAttribArray(1));

	//GL_FAILED(glBindVertexArray(0));

	GL_ASSERT(glGenVertexArrays(1, &vertexArrayObject_), "failed to generate frame buffer vertex array...");
	GL_ASSERT(glGenBuffers(1, &vertexBufferObject_), "failed to generate frame buffer vertex buffer...");

	GL_ASSERT(glBindVertexArray(vertexArrayObject_), "failed to bind frame buffer vertex array...");
	GL_ASSERT(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject_), "failed to bind frame buffer vertex buffer...");
	GL_ASSERT(glBufferData(GL_ARRAY_BUFFER, VertexPositionTexture::GetStride() * vertices.size(), reinterpret_cast<const void*>(vertices.data()), GL_STATIC_DRAW),
		"failed to create a new data store for vertex buffer object...");

	GL_ASSERT(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VertexPositionTexture::GetStride(), (void*)(offsetof(VertexPositionTexture, position_))),
		"failed to specify the location and data format of the array of generic vertex attributes at index...");
	GL_ASSERT(glEnableVertexAttribArray(0), "failed to enable vertex attrib array...");

	GL_ASSERT(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, VertexPositionTexture::GetStride(), (void*)(offsetof(VertexPositionTexture, uv_))),
		"failed to specify the location and data format of the array of generic vertex attributes at index...");
	GL_ASSERT(glEnableVertexAttribArray(1), "failed to enable vertex attrib array...");

	GL_ASSERT(glBindVertexArray(0), "failed to unbind frame buffer vertex array...");
}

void PostEffectPass::Release()
{
	CHECK(bIsInitialized_);

	GL_FAILED(glDeleteBuffers(1, &vertexBufferObject_));
	GL_FAILED(glDeleteVertexArrays(1, &vertexArrayObject_));

	Shader::Release();
}

void PostEffectPass::Blit(FrameBuffer* framebuffer)
{
	framebuffer->Active(0);

	GL_FAILED(glBindVertexArray(vertexArrayObject_));
	GL_FAILED(glDrawArrays(GL_TRIANGLES, 0, 6));
	GL_FAILED(glBindVertexArray(0));
}