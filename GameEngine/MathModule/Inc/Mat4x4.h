#pragma once

#include "Vec4.h"


/**
 * @brief 템플릿 기반의 4x4 행렬입니다.
 */
template <typename T>
struct TMat4x4
{
	/**
	 * @brief 4x4 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	TMat4x4() noexcept
	{
		e00 = static_cast<T>(0); e01 = static_cast<T>(0); e02 = static_cast<T>(0); e03 = static_cast<T>(0);
		e10 = static_cast<T>(0); e11 = static_cast<T>(0); e12 = static_cast<T>(0); e13 = static_cast<T>(0);
		e20 = static_cast<T>(0); e21 = static_cast<T>(0); e22 = static_cast<T>(0); e23 = static_cast<T>(0);
		e30 = static_cast<T>(0); e31 = static_cast<T>(0); e32 = static_cast<T>(0); e33 = static_cast<T>(0);
	}


	/**
	 * @brief 4x4 행렬의 생성자입니다.
	 *
	 * @param ee00 행렬의 (0, 0) 성분입니다.
	 * @param ee01 행렬의 (0, 1) 성분입니다.
	 * @param ee02 행렬의 (0, 2) 성분입니다.
	 * @param ee03 행렬의 (0, 3) 성분입니다.
	 * @param ee10 행렬의 (1, 0) 성분입니다.
	 * @param ee11 행렬의 (1, 1) 성분입니다.
	 * @param ee12 행렬의 (1, 2) 성분입니다.
	 * @param ee13 행렬의 (1, 3) 성분입니다.
	 * @param ee20 행렬의 (2, 0) 성분입니다.
	 * @param ee21 행렬의 (2, 1) 성분입니다.
	 * @param ee22 행렬의 (2, 2) 성분입니다.
	 * @param ee23 행렬의 (2, 3) 성분입니다.
	 * @param ee30 행렬의 (3, 0) 성분입니다.
	 * @param ee31 행렬의 (3, 1) 성분입니다.
	 * @param ee32 행렬의 (3, 2) 성분입니다.
	 * @param ee33 행렬의 (3, 3) 성분입니다.
	 */
	TMat4x4(
		T&& ee00, T&& ee01, T&& ee02, T&& ee03,
		T&& ee10, T&& ee11, T&& ee12, T&& ee13,
		T&& ee20, T&& ee21, T&& ee22, T&& ee23,
		T&& ee30, T&& ee31, T&& ee32, T&& ee33
	) noexcept
	{
		e00 = ee00; e01 = ee01; e02 = ee02; e03 = ee03;
		e10 = ee10; e11 = ee11; e12 = ee12; e13 = ee13;
		e20 = ee20; e21 = ee21; e22 = ee22; e23 = ee23;
		e30 = ee30; e31 = ee31; e32 = ee32; e33 = ee33;
	}


	/**
	 * @brief 4x4 행렬의 생성자입니다.
	 *
	 * @param ee00 행렬의 (0, 0) 성분입니다.
	 * @param ee01 행렬의 (0, 1) 성분입니다.
	 * @param ee02 행렬의 (0, 2) 성분입니다.
	 * @param ee03 행렬의 (0, 3) 성분입니다.
	 * @param ee10 행렬의 (1, 0) 성분입니다.
	 * @param ee11 행렬의 (1, 1) 성분입니다.
	 * @param ee12 행렬의 (1, 2) 성분입니다.
	 * @param ee13 행렬의 (1, 3) 성분입니다.
	 * @param ee20 행렬의 (2, 0) 성분입니다.
	 * @param ee21 행렬의 (2, 1) 성분입니다.
	 * @param ee22 행렬의 (2, 2) 성분입니다.
	 * @param ee23 행렬의 (2, 3) 성분입니다.
	 * @param ee30 행렬의 (3, 0) 성분입니다.
	 * @param ee31 행렬의 (3, 1) 성분입니다.
	 * @param ee32 행렬의 (3, 2) 성분입니다.
	 * @param ee33 행렬의 (3, 3) 성분입니다.
	 */
	TMat4x4(
		const T& ee00, const T& ee01, const T& ee02, const T& ee03,
		const T& ee10, const T& ee11, const T& ee12, const T& ee13,
		const T& ee20, const T& ee21, const T& ee22, const T& ee23,
		const T& ee30, const T& ee31, const T& ee32, const T& ee33
	) noexcept
	{
		e00 = ee00; e01 = ee01; e02 = ee02; e03 = ee03;
		e10 = ee10; e11 = ee11; e12 = ee12; e13 = ee13;
		e20 = ee20; e21 = ee21; e22 = ee22; e23 = ee23;
		e30 = ee30; e31 = ee31; e32 = ee32; e33 = ee33;
	}


	/**
	 * @brief 4x4 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	TMat4x4(T&& e) noexcept
	{
		e00 = e; e01 = e; e02 = e; e03 = e;
		e10 = e; e11 = e; e12 = e; e13 = e;
		e20 = e; e21 = e; e22 = e; e23 = e;
		e30 = e; e31 = e; e32 = e; e33 = e;
	}


	/**
	 * @brief 4x4 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	TMat4x4(const T& e) noexcept
	{
		e00 = e; e01 = e; e02 = e; e03 = e;
		e10 = e; e11 = e; e12 = e; e13 = e;
		e20 = e; e21 = e; e22 = e; e23 = e;
		e30 = e; e31 = e; e32 = e; e33 = e;
	}


	/**
	 * @brief 4x4 행렬의 복사 생성자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 */
	TMat4x4(TMat4x4<T>&& m) noexcept
	{
		e00 = m.e00; e01 = m.e01; e02 = m.e02; e03 = m.e03;
		e10 = m.e10; e11 = m.e11; e12 = m.e12; e13 = m.e13;
		e20 = m.e20; e21 = m.e21; e22 = m.e22; e23 = m.e23;
		e30 = m.e30; e31 = m.e31; e32 = m.e32; e33 = m.e33;
	}


	/**
	 * @brief 4x4 행렬의 복사 생성자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 */
	TMat4x4(const TMat4x4<T>& m) noexcept
	{
		e00 = m.e00; e01 = m.e01; e02 = m.e02; e03 = m.e03;
		e10 = m.e10; e11 = m.e11; e12 = m.e12; e13 = m.e13;
		e20 = m.e20; e21 = m.e21; e22 = m.e22; e23 = m.e23;
		e30 = m.e30; e31 = m.e31; e32 = m.e32; e33 = m.e33;
	}


	/**
	 * @brief 4x4 행렬의 대입 연산자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	TMat4x4<T>& operator=(TMat4x4<T>&& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01; e02 = m.e02; e03 = m.e03;
		e10 = m.e10; e11 = m.e11; e12 = m.e12; e13 = m.e13;
		e20 = m.e20; e21 = m.e21; e22 = m.e22; e23 = m.e23;
		e30 = m.e30; e31 = m.e31; e32 = m.e32; e33 = m.e33;

		return *this;
	}


	/**
	 * @brief 4x4 행렬의 대입 연산자입니다.
	 *
	 * @param m 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	TMat4x4<T>& operator=(const TMat4x4<T>& m) noexcept
	{
		if (this == &m) return *this;

		e00 = m.e00; e01 = m.e01; e02 = m.e02; e03 = m.e03;
		e10 = m.e10; e11 = m.e11; e12 = m.e12; e13 = m.e13;
		e20 = m.e20; e21 = m.e21; e22 = m.e22; e23 = m.e23;
		e30 = m.e30; e31 = m.e31; e32 = m.e32; e33 = m.e33;

		return *this;
	}


	/**
	 * @brief 4x4 행렬의 모든 원소에 -부호를 취합니다.
	 *
	 * @return 모든 원소에 -부호를 취한 새로운 행렬을 반환합니다.
	 */
	TMat4x4<T> operator-() const
	{
		return TMat4x4<T>(
			-e00, -e01, -e02, -e03,
			-e10, -e11, -e12, -e13,
			-e20, -e21, -e22, -e23,
			-e30, -e31, -e32, -e33
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param m 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	TMat4x4<T> operator+(TMat4x4<T>&& m) const
	{
		return TMat4x4<T>(
			e00 + m.e00, e01 + m.e01, e02 + m.e02, e03 + m.e03,
			e10 + m.e10, e11 + m.e11, e12 + m.e12, e13 + m.e13,
			e20 + m.e20, e21 + m.e21, e22 + m.e22, e23 + m.e23,
			e30 + m.e30, e31 + m.e31, e32 + m.e32, e33 + m.e33
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param m 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	TMat4x4<T> operator+(const TMat4x4<T>& m) const
	{
		return TMat4x4<T>(
			e00 + m.e00, e01 + m.e01, e02 + m.e02, e03 + m.e03,
			e10 + m.e10, e11 + m.e11, e12 + m.e12, e13 + m.e13,
			e20 + m.e20, e21 + m.e21, e22 + m.e22, e23 + m.e23,
			e30 + m.e30, e31 + m.e31, e32 + m.e32, e33 + m.e33
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param m 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	TMat4x4<T> operator-(TMat4x4<T>&& m) const
	{
		return TMat4x4<T>(
			e00 - m.e00, e01 - m.e01, e02 - m.e02, e03 - m.e03,
			e10 - m.e10, e11 - m.e11, e12 - m.e12, e13 - m.e13,
			e20 - m.e20, e21 - m.e21, e22 - m.e22, e23 - m.e23,
			e30 - m.e30, e31 - m.e31, e32 - m.e32, e33 - m.e33
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param m 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	TMat4x4<T> operator-(const TMat4x4<T>& m) const
	{
		return TMat4x4<T>(
			e00 - m.e00, e01 - m.e01, e02 - m.e02, e03 - m.e03,
			e10 - m.e10, e11 - m.e11, e12 - m.e12, e13 - m.e13,
			e20 - m.e20, e21 - m.e21, e22 - m.e22, e23 - m.e23,
			e30 - m.e30, e31 - m.e31, e32 - m.e32, e33 - m.e33
			);
	}


	/**
	 * @brief 두 4x4 행렬을 곱합니다.
	 *
	 * @param m 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	TMat4x4<T> operator*(TMat4x4<T>&& m) const
	{
		return TMat4x4(
			e00 * m.e00 + e01 * m.e10 + e02 * m.e20 + e03 * m.e30,
			e00 * m.e01 + e01 * m.e11 + e02 * m.e21 + e03 * m.e31,
			e00 * m.e02 + e01 * m.e12 + e02 * m.e22 + e03 * m.e32,
			e00 * m.e03 + e01 * m.e13 + e02 * m.e23 + e03 * m.e33,
			e10 * m.e00 + e11 * m.e10 + e12 * m.e20 + e13 * m.e30,
			e10 * m.e01 + e11 * m.e11 + e12 * m.e21 + e13 * m.e31,
			e10 * m.e02 + e11 * m.e12 + e12 * m.e22 + e13 * m.e32,
			e10 * m.e03 + e11 * m.e13 + e12 * m.e23 + e13 * m.e33,
			e20 * m.e00 + e21 * m.e10 + e22 * m.e20 + e23 * m.e30,
			e20 * m.e01 + e21 * m.e11 + e22 * m.e21 + e23 * m.e31,
			e20 * m.e02 + e21 * m.e12 + e22 * m.e22 + e23 * m.e32,
			e20 * m.e03 + e21 * m.e13 + e22 * m.e23 + e23 * m.e33,
			e30 * m.e00 + e31 * m.e10 + e32 * m.e20 + e33 * m.e30,
			e30 * m.e01 + e31 * m.e11 + e32 * m.e21 + e33 * m.e31,
			e30 * m.e02 + e31 * m.e12 + e32 * m.e22 + e33 * m.e32,
			e30 * m.e03 + e31 * m.e13 + e32 * m.e23 + e33 * m.e33
		);
	}


	/**
	 * @brief 두 4x4 행렬을 곱합니다.
	 *
	 * @param m 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	TMat4x4<T> operator*(const TMat4x4<T>& m) const
	{
		return TMat4x4(
			e00 * m.e00 + e01 * m.e10 + e02 * m.e20 + e03 * m.e30,
			e00 * m.e01 + e01 * m.e11 + e02 * m.e21 + e03 * m.e31,
			e00 * m.e02 + e01 * m.e12 + e02 * m.e22 + e03 * m.e32,
			e00 * m.e03 + e01 * m.e13 + e02 * m.e23 + e03 * m.e33,
			e10 * m.e00 + e11 * m.e10 + e12 * m.e20 + e13 * m.e30,
			e10 * m.e01 + e11 * m.e11 + e12 * m.e21 + e13 * m.e31,
			e10 * m.e02 + e11 * m.e12 + e12 * m.e22 + e13 * m.e32,
			e10 * m.e03 + e11 * m.e13 + e12 * m.e23 + e13 * m.e33,
			e20 * m.e00 + e21 * m.e10 + e22 * m.e20 + e23 * m.e30,
			e20 * m.e01 + e21 * m.e11 + e22 * m.e21 + e23 * m.e31,
			e20 * m.e02 + e21 * m.e12 + e22 * m.e22 + e23 * m.e32,
			e20 * m.e03 + e21 * m.e13 + e22 * m.e23 + e23 * m.e33,
			e30 * m.e00 + e31 * m.e10 + e32 * m.e20 + e33 * m.e30,
			e30 * m.e01 + e31 * m.e11 + e32 * m.e21 + e33 * m.e31,
			e30 * m.e02 + e31 * m.e12 + e32 * m.e22 + e33 * m.e32,
			e30 * m.e03 + e31 * m.e13 + e32 * m.e23 + e33 * m.e33
		);
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	TMat4x4<T>& operator+=(TMat4x4<T>&& m) noexcept
	{
		e00 += m.e00; e01 += m.e01; e02 += m.e02; e03 += m.e03;
		e10 += m.e10; e11 += m.e11; e12 += m.e12; e13 += m.e13;
		e20 += m.e20; e21 += m.e21; e22 += m.e22; e23 += m.e23;
		e30 += m.e30; e31 += m.e31; e32 += m.e32; e33 += m.e33;

		return *this;
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	TMat4x4<T>& operator+=(const TMat4x4<T>& m) noexcept
	{
		e00 += m.e00; e01 += m.e01; e02 += m.e02; e03 += m.e03;
		e10 += m.e10; e11 += m.e11; e12 += m.e12; e13 += m.e13;
		e20 += m.e20; e21 += m.e21; e22 += m.e22; e23 += m.e23;
		e30 += m.e30; e31 += m.e31; e32 += m.e32; e33 += m.e33;

		return *this;
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	TMat4x4<T>& operator-=(TMat4x4<T>&& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01; e02 -= m.e02; e03 -= m.e03;
		e10 -= m.e10; e11 -= m.e11; e12 -= m.e12; e13 -= m.e13;
		e20 -= m.e20; e21 -= m.e21; e22 -= m.e22; e23 -= m.e23;
		e30 -= m.e30; e31 -= m.e31; e32 -= m.e32; e33 -= m.e33;

		return *this;
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param m 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	TMat4x4<T>& operator-=(const TMat4x4<T>& m) noexcept
	{
		e00 -= m.e00; e01 -= m.e01; e02 -= m.e02; e03 -= m.e03;
		e10 -= m.e10; e11 -= m.e11; e12 -= m.e12; e13 -= m.e13;
		e20 -= m.e20; e21 -= m.e21; e22 -= m.e22; e23 -= m.e23;
		e30 -= m.e30; e31 -= m.e31; e32 -= m.e32; e33 -= m.e33;

		return *this;
	}


	/**
	 * @brief 4x4 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4x4 행렬 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &e00; }


	/**
	 * @brief 4x4 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4x4 행렬 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &e00; }


	/**
	 * @brief 4x4 행렬의 모든 원소가 0인 행렬을 얻습니다.
	 *
	 * @return 모든 원소가 0인 4x4 행렬을 반환합니다.
	 */
	static inline TMat4x4<T> Zero()
	{
		return TMat4x4(
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)
		);
	}


	/**
	 * @brief 4x4 행렬의 단위 행렬을 얻습니다.
	 *
	 * @return 4x4 행렬의 단위 행렬를 반환합니다.
	 */
	static inline TMat4x4<T> Identity()
	{
		return TMat4x4(
			static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 4x4 행렬의 전치 행렬을 얻습니다.
	 *
	 * @param m 원소들을 전치할 4x4 행렬입니다.
	 *
	 * @return 원소가 전치된 4x4 행렬을 반환합니다.
	 */
	static inline TMat4x4<T> Transpose(const TMat4x4<T>& m)
	{
		return TMat4x4(
			m.e00, m.e10, m.e20, m.e30
			m.e01, m.e11, m.e21, m.e31,
			m.e02, m.e12, m.e22, m.e32,
			m.e03, m.e13, m.e23, m.e33
		);
	}


	/**
	 * @brief 4x4 행렬의 행렬식 값을 얻습니다.
	 *
	 * @param m 행렬식 값을 계산할 4x4 행렬입니다.
	 *
	 * @return 4x4 행렬의 행렬식 값을 반환합니다.
	 */
	static inline T Determinant(const TMat4x4<T>& m)
	{
		T subFactor00 = m.e22 * m.e33 - m.e32 * m.e23;
		T subFactor01 = m.e21 * m.e33 - m.e31 * m.e23;
		T subFactor02 = m.e21 * m.e32 - m.e31 * m.e22;
		T subFactor03 = m.e20 * m.e33 - m.e30 * m.e23;
		T subFactor04 = m.e20 * m.e32 - m.e30 * m.e22;
		T subFactor05 = m.e20 * m.e31 - m.e30 * m.e21;

		T cof0 = +(m.e11 * subFactor00 - m.e12 * subFactor01 + m.e13 * subFactor02);
		T cof1 = -(m.e10 * subFactor00 - m.e12 * subFactor03 + m.e13 * subFactor04);
		T cof2 = +(m.e10 * subFactor01 - m.e11 * subFactor03 + m.e13 * subFactor05);
		T cof3 = -(m.e10 * subFactor02 - m.e11 * subFactor04 + m.e12 * subFactor05);

		return m.e00 * cof0 + m.e01 * cof1 + m.e02 * cof2 + m.e03 * cof3;
	}


	/**
	 * @brief 4x4 행렬의 역행렬을 얻습니다.
	 *
	 * @param m 역행렬을 계산할 4x4 행렬입니다.
	 *
	 * @return 4x4 행렬의 역행렬을 반환합니다.
	 */
	static inline TMat4x4<T> Inverse(const TMat4x4<T>& m)
	{
		T oneOverDeterminant = static_cast<T>(1) / Determinant(m);

		T coef00 = m.e22 * m.e33 - m.e32 * m.e23;
		T coef02 = m.e12 * m.e33 - m.e32 * m.e13;
		T coef03 = m.e12 * m.e23 - m.e22 * m.e13;

		T coef04 = m.e21 * m.e33 - m.e31 * m.e23;
		T coef06 = m.e11 * m.e33 - m.e31 * m.e13;
		T coef07 = m.e11 * m.e23 - m.e21 * m.e13;

		T coef08 = m.e21 * m.e32 - m.e31 * m.e22;
		T coef10 = m.e11 * m.e32 - m.e31 * m.e12;
		T coef11 = m.e11 * m.e22 - m.e21 * m.e12;

		T coef12 = m.e20 * m.e33 - m.e30 * m.e23;
		T coef14 = m.e10 * m.e33 - m.e30 * m.e13;
		T coef15 = m.e10 * m.e23 - m.e20 * m.e13;

		T coef16 = m.e20 * m.e32 - m.e30 * m.e22;
		T coef18 = m.e10 * m.e32 - m.e30 * m.e12;
		T coef19 = m.e10 * m.e22 - m.e20 * m.e12;

		T coef20 = m.e20 * m.e31 - m.e30 * m.e21;
		T coef22 = m.e10 * m.e31 - m.e30 * m.e11;
		T coef23 = m.e10 * m.e21 - m.e20 * m.e11;

		TVec4<T> fac0(coef00, coef00, coef02, coef03);
		TVec4<T> fac1(coef04, coef04, coef06, coef07);
		TVec4<T> fac2(coef08, coef08, coef10, coef11);
		TVec4<T> fac3(coef12, coef12, coef14, coef15);
		TVec4<T> fac4(coef16, coef16, coef18, coef19);
		TVec4<T> fac5(coef20, coef20, coef22, coef23);

		TVec4<T> vec0(m.e10, m.e00, m.e00, m.e00);
		TVec4<T> vec1(m.e11, m.e01, m.e01, m.e01);
		TVec4<T> vec2(m.e12, m.e02, m.e02, m.e02);
		TVec4<T> vec3(m.e13, m.e03, m.e03, m.e03);

		TVec4<T> inv0(vec1 * fac0 - vec2 * fac1 + vec3 * fac2);
		TVec4<T> inv1(vec0 * fac0 - vec2 * fac3 + vec3 * fac4);
		TVec4<T> inv2(vec0 * fac1 - vec1 * fac3 + vec3 * fac5);
		TVec4<T> inv3(vec0 * fac2 - vec1 * fac4 + vec2 * fac5);

		TVec4<T> signA(+static_cast<T>(1), -static_cast<T>(1), +static_cast<T>(1), -static_cast<T>(1));
		TVec4<T> signB(-static_cast<T>(1), +static_cast<T>(1), -static_cast<T>(1), +static_cast<T>(1));

		TVec4<T> col0 = (inv0 * signA) * oneOverDeterminant;
		TVec4<T> col1 = (inv1 * signB) * oneOverDeterminant;
		TVec4<T> col2 = (inv2 * signA) * oneOverDeterminant;
		TVec4<T> col3 = (inv3 * signB) * oneOverDeterminant;

		return TMat4x4<T>(
			col0.x, col0.y, col0.z, col0.w,
			col1.x, col1.y, col1.z, col1.w,
			col2.x, col2.y, col2.z, col2.w,
			col3.x, col3.y, col3.z, col3.w,
			);
	}


	/**
	 * @brief 4x4 행렬의 원소입니다.
	 */
	union
	{
		struct
		{
			T e00; T e01; T e02; T e03;
			T e10; T e11; T e12; T e13;
			T e20; T e21; T e22; T e23;
			T e30; T e31; T e32; T e33;
		};
		T data[16];
	};
};


/**
 * @brief int32_t 타입의 4x4 행렬입니다.
 */
using Mat4x4i = TMat4x4<int32_t>;


/**
 * @brief float 타입의 4x4 행렬입니다.
 */
using Mat4x4f = TMat4x4<float>;