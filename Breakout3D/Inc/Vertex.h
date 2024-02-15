#pragma once

#include "MathModule.h"


/**
 * @brief 정점(Vertex)입니다.
 */
class Vertex
{
public:
	/**
	 * @brief 정점(Vertex)의 디폴트 생성자입니다.
	 */
	Vertex() noexcept
		: position_(0.0f, 0.0f, 0.0f)
		, normal_(0.0f, 0.0f, 0.0f)
		, uv_(0.0f, 0.0f) {}


	/**
	 * @brief 정점(Vertex)의 생성자입니다.
	 * 
	 * @param position 정점의 위치입니다.
	 * @param normal 정점의 법선 벡터입니다.
	 * @param uv 정점의 텍스처 좌표입니다.
	 */
	Vertex(Vector3f&& position, Vector3f&& normal, Vector2f&& uv) noexcept
		: position_(position)
		, normal_(normal)
		, uv_(uv) {}


	/**
	 * @brief 정점(Vertex)의 생성자입니다.
	 *
	 * @param position 정점의 위치입니다.
	 * @param normal 정점의 법선 벡터입니다.
	 * @param uv 정점의 텍스처 좌표입니다.
	 */
	Vertex(const Vector3f& position, const Vector3f& normal, const Vector2f& uv) noexcept
		: position_(position)
		, normal_(normal)
		, uv_(uv) {}


	/**
	 * @brief 정점(Vertex)의 생성자입니다.
	 * 
	 * @param px 정점 위치의 X좌표입니다.
	 * @param py 정점 위치의 Y좌표입니다.
	 * @param pz 정점 위치의 Z좌표입니다.
	 * @param nx 정점 법선 벡터의 X성분입니다.
	 * @param ny 정점 법선 벡터의 Y성분입니다.
	 * @param nz 정점 법선 벡터의 Z성분입니다.
	 * @param u 정점 텍스처 좌표의 U성분입니다.
	 * @param v 정점 텍스처 좌표의 V성분입니다.
	 */
	Vertex(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float u, float v
	) noexcept 
		: position_(px, py, pz)
		, normal_(nx, ny, nz)
		, uv_(u, v) {}


	/**
	 * @brief 정점(Vertex)의 복사 생성자입니다.
	 * 
	 * @param instance 복사를 수행할 정점(Vertex) 인스턴스입니다.
	 */
	Vertex(Vertex&& instance) noexcept
		: position_(instance.position_)
		, normal_(instance.normal_)
		, uv_(instance.uv_) {}


	/**
	 * @brief 정점(Vertex)의 복사 생성자입니다.
	 *
	 * @param instance 복사를 수행할 정점(Vertex) 인스턴스입니다.
	 */
	Vertex(const Vertex& instance) noexcept
		: position_(instance.position_)
		, normal_(instance.normal_)
		, uv_(instance.uv_) {}


	/**
	 * @brief 정점(Vertex)의 대입 연산자입니다.
	 * 
	 * @param instance 복사를 수행할 정점(Vertex) 인스턴스입니다.
	 * 
	 * @return 대인한 객체의 참조자를 반환합니다.
	 */
	Vertex& operator=(Vertex&& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 정점(Vertex)의 대입 연산자입니다.
	 *
	 * @param instance 복사를 수행할 정점(Vertex) 인스턴스입니다.
	 *
	 * @return 대인한 객체의 참조자를 반환합니다.
	 */
	Vertex& operator=(const Vertex& instance) noexcept
	{
		if (this == &instance) return *this;

		position_ = instance.position_;
		normal_ = instance.normal_;
		uv_ = instance.uv_;

		return *this;
	}


	/**
	 * @brief 정점의 위치를 얻습니다.
	 * 
	 * @return 정점의 위치를 반환합니다.
	 */
	Vector3f GetPosition() { return position_; }


	/**
	 * @brief 정점의 위치를 얻습니다.
	 *
	 * @return 정점의 위치를 반환합니다.
	 */
	const Vector3f& GetPosition() const { return position_; }


	/**
	 * @brief 정점의 법선 벡터를 얻습니다.
	 * 
	 * @return 정점의 법선 벡터를 반환합니다.
	 */
	Vector3f GetNormal() { return normal_; }


	/**
	 * @brief 정점의 법선 벡터를 얻습니다.
	 *
	 * @return 정점의 법선 벡터를 반환합니다.
	 */
	const Vector3f& GetNormal() const { return normal_; }


	/**
	 * @brief 정점의 텍스처 좌표를 얻습니다.
	 * 
	 * @return 정점의 텍스처 좌표를 반환합니다.
	 */
	Vector2f GetUV() { return uv_; }


	/**
	 * @brief 정점의 텍스처 좌표를 얻습니다.
	 *
	 * @return 정점의 텍스처 좌표를 반환합니다.
	 */
	const Vector2f& GetUV() const { return uv_; }

	
	/**
	 * @brief 정점의 위치 오프셋 포인터를 얻습니다.
	 * 
	 * @return 정점의 위치 오프셋 포인터를 반환합니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/offsetof-macro?view=msvc-170
	 */
	static void* GetOffsetOfPosition()
	{
		return (void*)(offsetof(Vertex, position_));
	}


	/**
	 * @brief 정점의 법선 벡터 오프셋 포인터를 얻습니다.
	 * 
	 * @return 정점의 법선 벡터 오프셋 포인터를 반환합니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/offsetof-macro?view=msvc-170
	 */
	static void* GetOffsetOfNormal()
	{
		return (void*)(offsetof(Vertex, normal_));
	}


	/**
	 * @brief 정점의 텍스처 좌표 오프셋 포인터를 얻습니다.
	 * 
	 * @return 정점의 텍스처 좌표 오프셋 포인터를 반환합니다.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/offsetof-macro?view=msvc-170
	 */
	static void* GetOffsetOfUV()
	{
		return (void*)(offsetof(Vertex, uv_));
	}


	/**
	 * @brief 정점의 바이트 보폭 값을 얻습니다.
	 *
	 * @return 정점의 파이트 보폭(Stride) 값을 반환합니다.
	 */
	static uint32_t GetStride()
	{
		return sizeof(Vertex);
	}


private:
	/**
	 * @brief 정점의 위치입니다.
	 */
	Vector3f position_;


	/**
	 * @brief 정점의 법선 벡터입니다.
	 */
	Vector3f normal_;


	/**
	 * @brief 정점의 텍스처 좌표입니다.
	 */
	Vector2f uv_;
};