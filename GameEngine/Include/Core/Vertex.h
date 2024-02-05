#pragma once

#include "Vector/Vector2.h"
#include "Vector/Vector3.h"
#include "Vector/Vector4.h"


/**
 * @brief 정점(Vertex)입니다.
 */
struct Vertex
{
	/**
	 * @brief 정점(Vertex)의 기본 생성자입니다.
	 */
	Vertex() noexcept
		: position(0.0f, 0.0f, 0.0f)
		, normal(0.0f, 0.0f, 0.0f)
		, uv(0.0f, 0.0f) {}


	/**
	 * @brief 정점(Vertex)의 복사 생성자입니다.
	 *
	 * @param instance 복사할 정점 인스턴스입니다.
	 */
	Vertex(Vertex&& instance) noexcept
		: position(instance.position)
		, normal(instance.normal)
		, uv(instance.uv) {}


	/**
	 * @brief 정점(Vertex)의 복사 생성자입니다.
	 *
	 * @param instance 복사할 정점 인스턴스입니다.
	 */
	Vertex(const Vertex& instance) noexcept
		: position(instance.position)
		, normal(instance.normal)
		, uv(instance.uv) {}


	/**
	 * @brief 정점(Vertex)의 생성자입니다.
	 *
	 * @param p 정점의 위치입니다.
	 * @param n 정점의 노말 벡터입니다.
	 * @param tex 정점의 텍셀 좌표입니다.
	 */
	Vertex(Vector3f&& p, Vector3f&& n, Vector2f&& tex) noexcept
		: position(p)
		, normal(n)
		, uv(tex) {}


	/**
	 * @brief 정점(Vertex)의 생성자입니다.
	 *
	 * @param p 정점의 위치입니다.
	 * @param n 정점의 노말 벡터입니다.
	 * @param tex 정점의 텍셀 좌표입니다.
	 */
	Vertex(const Vector3f& p, const Vector3f& n, const Vector2f& tex) noexcept
		: position(p)
		, normal(n)
		, uv(tex) {}


	/**
	 * @brief 정점(Vertex)의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	Vertex& operator=(Vertex&& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		normal = instance.normal;
		uv = instance.uv;

		return *this;
	}


	/**
	 * @brief 정점(Vertex)의 대입 연산자입니다.
	 *
	 * @param instance 대입할 정점 인스턴스입니다.
	 *
	 * @return 대입한 객체의 참조자를 반환합니다.
	 */
	Vertex& operator=(const Vertex& instance) noexcept
	{
		if (this == &instance) return *this;

		position = instance.position;
		normal = instance.normal;
		uv = instance.uv;

		return *this;
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


	/**
	 * @brief 정점의 위치입니다.
	 */
	Vector3f position;


	/**
	 * @brief 정점의 노말 벡터입니다.
	 */
	Vector3f normal;


	/**
	 * @brief 정점의 텍셀입니다.
	 */
	Vector2f uv;
};