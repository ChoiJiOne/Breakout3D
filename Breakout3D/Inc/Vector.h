#pragma once

#include <cstdint>


/**
 * @brief 템플릿 기반의 2차원 벡터입니다.
 */
template <typename T>
struct Vector2
{
	/**
	 * @brief 2차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vector2() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
	}


	/**
	 * @brief 2차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 */
	Vector2(T&& xx, T&& yy) noexcept
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 2차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 */
	Vector2(const T& xx, const T& yy) noexcept
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 2차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vector2(T&& e) noexcept
	{
		x = e;
		y = e;
	}


	/**
	 * @brief 2차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vector2(const T& e) noexcept
	{
		x = e;
		y = e;
	}


	/**
	 * @brief 2차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector2(Vector2<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
	}


	/**
	 * @brief 2차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector2(const Vector2<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
	}


	/**
	 * @brief 2차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator=(Vector2<T>&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;

		return *this;
	}


	/**
	 * @brief 2차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator=(const Vector2<T>& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;

		return *this;
	}


	/**
	 * @brief 2차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 2차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector2<T> operator-() const
	{
		return Vector2<T>(-x, -y);
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector2<T> operator+(Vector2<T>&& v) const
	{
		return Vector2<T>(x + v.x, y + v.y);
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector2<T> operator+(const Vector2<T>& v) const
	{
		return Vector2<T>(x + v.x, y + v.y);
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector2<T> operator-(Vector2<T>&& v) const
	{
		return Vector2<T>(x - v.x, y - v.y);
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector2<T> operator-(const Vector2<T>& v) const
	{
		return Vector2<T>(x - v.x, y - v.y);
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector2<T> operator*(Vector2<T>&& v) const
	{
		return Vector2<T>(x * v.x, y * v.y);
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector2<T> operator*(const Vector2<T>& v) const
	{
		return Vector2<T>(x * v.x, y * v.y);
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator+=(Vector2<T>&& v) noexcept
	{
		x += v.x;
		y += v.y;

		return *this;
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator+=(const Vector2<T>& v) noexcept
	{
		x += v.x;
		y += v.y;

		return *this;
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator-=(Vector2<T>&& v) noexcept
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}


	/**
	 * @brief 두 2차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector2<T>& operator-=(const Vector2<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}


	/**
	 * @brief 2차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 2차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 2차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 2차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 2차원 벡터의 다양한 원소 형식입니다.
	 *
	 * @note
	 * - x, y는 주로 좌표 상의 좌표를 나타낼 때 사용합니다.
	 * - r, g는 주로 색상을 나타낼 때 사용합니다.
	 * - s, t는 주로 텍스처 좌표를 나타낼 때 사용합니다(OpenGL 기준).
	 */
	union
	{
		struct
		{
			T x;
			T y;
		};
		struct
		{
			T r;
			T g;
		};
		struct
		{
			T s;
			T t;
		};
		T data[2];
	};
};


/**
 * @brief 템플릿 기반의 3차원 벡터입니다.
 */
template <typename T>
struct Vector3
{
	/**
	 * @brief 3차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vector3() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
	}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vector3(T&& xx, T&& yy, T&& zz) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 3차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 */
	Vector3(const T& xx, const T& yy, const T& zz) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vector3(T&& e) noexcept
	{
		x = e;
		y = e;
		z = e;
	}


	/**
	 * @brief 3차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vector3(const T& e) noexcept
	{
		x = e;
		y = e;
		z = e;
	}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector3(Vector3<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}


	/**
	 * @brief 3차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector3(const Vector3<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator=(Vector3<T>&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator=(const Vector3<T>& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 3차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector3<T> operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector3<T> operator+(Vector3<T>&& v) const
	{
		return Vector3<T>(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector3<T> operator+(const Vector3<T>& v) const
	{
		return Vector3<T>(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector3<T> operator-(Vector3<T>&& v) const
	{
		return Vector3<T>(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector3<T> operator-(const Vector3<T>& v) const
	{
		return Vector3<T>(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector3<T> operator*(Vector3<T>&& v) const
	{
		return Vector3<T>(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector3<T> operator*(const Vector3<T>& v) const
	{
		return Vector3<T>(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator+=(Vector3<T>&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator+=(const Vector3<T>& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator-=(Vector3<T>&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 두 3차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector3<T>& operator-=(const Vector3<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 3차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 3차원 벡터의 다양한 원소 형식입니다.
	 *
	 * @note
	 * - x, y, z는 주로 공간 상의 좌표를 나타낼 때 사용합니다.
	 * - r, g, b는 주로 색상을 나타낼 때 사용합니다.
	 * - s, t, r는 주로 텍스처 좌표를 나타낼 때 사용합니다(OpenGL 기준).
	 */
	union
	{
		struct
		{
			T x;
			T y;
			T z;
		};
		struct
		{
			T r;
			T g;
			T b;
		};
		struct
		{
			T s;
			T t;
			T r;
		};
		T data[3];
	};
};


/**
 * @brief 템플릿 기반의 4차원 벡터입니다.
 */
template <typename T>
struct Vector4
{
	/**
	 * @brief 4차원 벡터의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Vector4() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}


	/**
	 * @brief 4차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vector4(T&& xx, T&& yy, T&& zz, T&& ww) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 4차원 벡터의 생성자입니다.
	 *
	 * @param xx 벡터의 x 성분입니다.
	 * @param yy 벡터의 y 성분입니다.
	 * @param zz 벡터의 z 성분입니다.
	 * @param ww 벡터의 w 성분입니다.
	 */
	Vector4(const T& xx, const T& yy, const T& zz, const T& ww) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 4차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vector4(T&& e) noexcept
	{
		x = e;
		y = e;
		z = e;
		w = e;
	}


	/**
	 * @brief 4차원 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Vector4(const T& e) noexcept
	{
		x = e;
		y = e;
		z = e;
		w = e;
	}


	/**
	 * @brief 4차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector4(Vector4<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}


	/**
	 * @brief 4차원 벡터의 복사 생성자입니다.
	 *
	 * @param v 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector4(const Vector4<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}


	/**
	 * @brief 4차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector4<T>& operator=(Vector4<T>&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;

		return *this;
	}


	/**
	 * @brief 4차원 벡터의 대입 연산자 입니다.
	 *
	 * @param v 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector4<T>& operator=(const Vector4<T>& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;

		return *this;
	}


	/**
	 * @brief 4차원 벡터의 원소에 -부호를 취합니다.
	 *
	 * @return 4차원 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector4<T> operator-() const
	{
		return Vector4<T>(-x, -y, -z, -w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector4<T> operator+(Vector4<T>&& v) const
	{
		return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector4<T> operator+(const Vector4<T>& v) const
	{
		return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector4<T> operator-(Vector4<T>&& v) const
	{
		return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector4<T> operator-(const Vector4<T>& v) const
	{
		return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector4<T> operator*(Vector4<T>&& v) const
	{
		return Vector4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 각각 곱합니다.
	 *
	 * @note 이 연산은 벡터의 내적 연산(Dot Product)와는 다릅니다.
	 *
	 * @param v 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector4<T> operator*(const Vector4<T>& v) const
	{
		return Vector4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector4<T>& operator+=(Vector4<T>&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector4<T>& operator+=(const Vector4<T>& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;

		return *this;
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector4<T>& operator-=(Vector4<T>&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}


	/**
	 * @brief 두 4차원 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param v 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector4<T>& operator-=(const Vector4<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;

		return *this;
	}


	/**
	 * @brief 4차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 4차원 벡터 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4차원 벡터 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 4차원 벡터의 다양한 원소 형식입니다.
	 *
	 * @note
	 * - x, y, z, w는 주로 공간 상의 좌표를 나타낼 때 사용합니다.
	 * - r, g, b, a는 주로 색상을 나타낼 때 사용합니다.
	 * - s, t, r, q는 주로 텍스처 좌표를 나타낼 때 사용합니다(OpenGL 기준).
	 */
	union
	{
		struct
		{
			T x;
			T y;
			T z;
			T w;
		};
		struct
		{
			T r;
			T g;
			T b;
			T a;
		};
		struct
		{
			T s;
			T t;
			T r;
			T q;
		};
		T data[4];
	};
};


/**
 * @brief int32_t 타입의 2차원 벡터입니다.
 */
using Vector2i = Vector2<int32_t>;


/**
 * @brief float 타입의 2차원 벡터입니다.
 */
using Vector2f = Vector2<float>;


/**
 * @brief int32_t 타입의 3차원 벡터입니다.
 */
using Vector3i = Vector3<int32_t>;


/**
 * @brief float 타입의 3차원 벡터입니다.
 */
using Vector3f = Vector3<float>;

/**
 * @brief int32_t 타입의 4차원 벡터입니다.
 */
using Vector4i = Vector4<int32_t>;


/**
 * @brief float 타입의 4차원 벡터입니다.
 */
using Vector4f = Vector4<float>;