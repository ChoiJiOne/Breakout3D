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
 * @brief 템플릿 기반의 2x2 행렬입니다.
 */
template <typename T>
struct Matrix2x2
{
	/**
	 * @brief 2x2 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Matrix2x2() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0);
	}


	/**
	 * @brief 2x2 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 */
	Matrix2x2(
		T&& m00, T&& m01,
		T&& m10, T&& m11
	) noexcept
	{
		m[0][0] = m00; m[0][1] = m01;
		m[1][0] = m10; m[1][1] = m11;
	}


	/**
	 * @brief 2x2 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 */
	Matrix2x2(
		const T& m00, const T& m01,
		const T& m10, const T& m11
	) noexcept
	{
		m[0][0] = m00; m[0][1] = m01;
		m[1][0] = m10; m[1][1] = m11;
	}


	/**
	 * @brief 2x2 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Matrix2x2(T&& e) noexcept
	{
		m[0][0] = e; m[0][1] = e;
		m[1][0] = e; m[1][1] = e;
	}


	/**
	 * @brief 2x2 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Matrix2x2(const T& e) noexcept
	{
		m[0][0] = e; m[0][1] = e;
		m[1][0] = e; m[1][1] = e;
	}


	/**
	 * @brief 2x2 행렬의 복사 생성자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix2x2(Matrix2x2<T>&& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];
	}


	/**
	 * @brief 2x2 행렬의 복사 생성자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix2x2(const Matrix2x2<T>& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];
	}


	/**
	 * @brief 2x2 행렬의 대입 연산자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator=(Matrix2x2<T>&& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 2x2 행렬의 대입 연산자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator=(const Matrix2x2<T>& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 2x2 행렬의 모든 원소에 - 부호를 취합니다.
	 *
	 * @return 모든 원소에 -부호를 취한 새로운 행렬을 반환합니다.
	 */
	Matrix2x2<T> operator-() const
	{
		return Matrix2x2<T>(
			-m[0][0], -m[0][1],
			-m[1][0], -m[1][1]
			);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param matrix 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix2x2<T> operator+(Matrix2x2<T>&& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1]
			);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param matrix 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix2x2<T> operator+(const Matrix2x2<T>& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1]
			);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix2x2<T> operator-(Matrix2x2<T>&& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1]
			);
	}


	/**
	 * @brief 두 2x2 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix2x2<T> operator-(const Matrix2x2<T>& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1]
			);
	}


	/**
	 * @brief 두 2x2 행렬을 곱합니다.
	 *
	 * @param matrix 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Matrix2x2<T> operator*(Matrix2x2<T>&& matrix) const
	{
		return Matrix2x2(
			m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0],
			m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1],
			m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0],
			m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1]
		);
	}


	/**
	 * @brief 두 2x2 행렬을 곱합니다.
	 *
	 * @param matrix 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Matrix2x2<T> operator*(const Matrix2x2<T>& matrix) const
	{
		return Matrix2x2(
			m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0],
			m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1],
			m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0],
			m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1]
		);
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator+=(Matrix2x2<T>&& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator+=(const Matrix2x2<T>& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator-=(Matrix2x2<T>&& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 두 2x2 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix2x2<T>& operator-=(const Matrix2x2<T>& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 2x2 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 2x2 행렬 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &m[0][0]; }


	/**
	 * @brief 2x2 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 2x2 행렬 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &m[0][0]; }


	/**
	 * @brief 2x2 행렬의 단위 행렬을 얻습니다.
	 *
	 * @return 2x2 행렬의 단위 행렬를 반환합니다.
	 */
	static Matrix2x2<T> GetIdentity()
	{
		return Matrix2x2(
			static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 2x2 행렬의 원소입니다.
	 */
	T m[2][2];
};


/**
 * @brief 템플릿 기반의 3x3 행렬입니다.
 */
template <typename T>
struct Matrix3x3
{
	/**
	 * @brief 3x3 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Matrix3x3() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0);
	}


	/**
	 * @brief 3x3 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
	 */
	Matrix3x3(
		T&& m00, T&& m01, T&& m02,
		T&& m10, T&& m11, T&& m12,
		T&& m20, T&& m21, T&& m22
	) noexcept
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}


	/**
	 * @brief 3x3 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
	 */
	Matrix3x3(
		const T& m00, const T& m01, const T& m02,
		const T& m10, const T& m11, const T& m12,
		const T& m20, const T& m21, const T& m22
	) noexcept
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
	}


	/**
	 * @brief 3x3 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Matrix3x3(T&& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e;
	}


	/**
	 * @brief 3x3 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Matrix3x3(const T& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e;
	}


	/**
	 * @brief 3x3 행렬의 복사 생성자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix3x3(Matrix3x3<T>&& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2];
	}


	/**
	 * @brief 3x3 행렬의 복사 생성자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix3x3(const Matrix3x3<T>& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2];
	}


	/**
	 * @brief 3x3 행렬의 대입 연산자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator=(Matrix3x3<T>&& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief 3x3 행렬의 대입 연산자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator=(const Matrix3x3<T>& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief 3x3 행렬의 모든 원소에 -부호를 취합니다.
	 *
	 * @return 모든 원소에 -부호를 취한 새로운 행렬을 반환합니다.
	 */
	Matrix3x3<T> operator-() const
	{
		return Matrix3x3<T>(
			-m[0][0], -m[0][1], -m[0][2],
			-m[1][0], -m[1][1], -m[1][2],
			-m[2][0], -m[2][1], -m[2][2]
			);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param matrix 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix3x3<T> operator+(Matrix3x3<T>&& matrix) const
	{
		return Matrix3x3<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1], m[0][2] + matrix.m[0][2],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1], m[1][2] + matrix.m[1][2],
			m[2][0] + matrix.m[2][0], m[2][1] + matrix.m[2][1], m[2][2] + matrix.m[2][2]
			);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param matrix 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix3x3<T> operator+(const Matrix3x3<T>& matrix) const
	{
		return Matrix3x3<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1], m[0][2] + matrix.m[0][2],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1], m[1][2] + matrix.m[1][2],
			m[2][0] + matrix.m[2][0], m[2][1] + matrix.m[2][1], m[2][2] + matrix.m[2][2]
			);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix3x3<T> operator-(Matrix3x3<T>&& matrix) const
	{
		return Matrix3x3<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1], m[0][2] - matrix.m[0][2],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1], m[1][2] - matrix.m[1][2],
			m[2][0] - matrix.m[2][0], m[2][1] - matrix.m[2][1], m[2][2] - matrix.m[2][2]
			);
	}


	/**
	 * @brief 두 3x3 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix3x3<T> operator-(const Matrix3x3<T>& matrix) const
	{
		return Matrix3x3<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1], m[0][2] - matrix.m[0][2],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1], m[1][2] - matrix.m[1][2],
			m[2][0] - matrix.m[2][0], m[2][1] - matrix.m[2][1], m[2][2] - matrix.m[2][2]
			);
	}


	/**
	 * @brief 두 3x3 행렬을 곱합니다.
	 *
	 * @param matrix 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Matrix3x3<T> operator*(Matrix3x3<T>&& matrix) const
	{
		return Matrix3x3(
			m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0] + m[0][2] * matrix.m[2][0],
			m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1] + m[0][2] * matrix.m[2][1],
			m[0][0] * matrix.m[0][2] + m[0][1] * matrix.m[1][2] + m[0][2] * matrix.m[2][2],
			m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0] + m[1][2] * matrix.m[2][0],
			m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1] + m[1][2] * matrix.m[2][1],
			m[1][0] * matrix.m[0][2] + m[1][1] * matrix.m[1][2] + m[1][2] * matrix.m[2][2],
			m[2][0] * matrix.m[0][0] + m[2][1] * matrix.m[1][0] + m[2][2] * matrix.m[2][0],
			m[2][0] * matrix.m[0][1] + m[2][1] * matrix.m[1][1] + m[2][2] * matrix.m[2][1],
			m[2][0] * matrix.m[0][2] + m[2][1] * matrix.m[1][2] + m[2][2] * matrix.m[2][2]
		);
	}


	/**
	 * @brief 두 3x3 행렬을 곱합니다.
	 *
	 * @param matrix 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Matrix3x3<T> operator*(const Matrix3x3<T>& matrix) const
	{
		return Matrix3x3(
			m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0] + m[0][2] * matrix.m[2][0],
			m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1] + m[0][2] * matrix.m[2][1],
			m[0][0] * matrix.m[0][2] + m[0][1] * matrix.m[1][2] + m[0][2] * matrix.m[2][2],
			m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0] + m[1][2] * matrix.m[2][0],
			m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1] + m[1][2] * matrix.m[2][1],
			m[1][0] * matrix.m[0][2] + m[1][1] * matrix.m[1][2] + m[1][2] * matrix.m[2][2],
			m[2][0] * matrix.m[0][0] + m[2][1] * matrix.m[1][0] + m[2][2] * matrix.m[2][0],
			m[2][0] * matrix.m[0][1] + m[2][1] * matrix.m[1][1] + m[2][2] * matrix.m[2][1],
			m[2][0] * matrix.m[0][2] + m[2][1] * matrix.m[1][2] + m[2][2] * matrix.m[2][2]
		);
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator+=(Matrix3x3<T>&& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1]; m[0][2] += matrix.m[0][2];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1]; m[1][2] += matrix.m[1][2];
		m[2][0] += matrix.m[2][0]; m[2][1] += matrix.m[2][1]; m[2][2] += matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator+=(const Matrix3x3<T>& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1]; m[0][2] += matrix.m[0][2];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1]; m[1][2] += matrix.m[1][2];
		m[2][0] += matrix.m[2][0]; m[2][1] += matrix.m[2][1]; m[2][2] += matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator-=(Matrix3x3<T>&& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1]; m[0][2] -= matrix.m[0][2];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1]; m[1][2] -= matrix.m[1][2];
		m[2][0] -= matrix.m[2][0]; m[2][1] -= matrix.m[2][1]; m[2][2] -= matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief 두 3x3 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix3x3<T>& operator-=(const Matrix3x3<T>& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1]; m[0][2] -= matrix.m[0][2];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1]; m[1][2] -= matrix.m[1][2];
		m[2][0] -= matrix.m[2][0]; m[2][1] -= matrix.m[2][1]; m[2][2] -= matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief 3x3 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3x3 행렬 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &m[0][0]; }


	/**
	 * @brief 3x3 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 3x3 행렬 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &m[0][0]; }


	/**
	 * @brief 3x3 행렬의 단위 행렬을 얻습니다.
	 *
	 * @return 3x3 행렬의 단위 행렬를 반환합니다.
	 */
	static Matrix3x3<T> GetIdentity()
	{
		return Matrix3x3(
			static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 3x3 행렬의 원소입니다.
	 */
	T m[3][3];
};


/**
 * @brief 템플릿 기반의 4x4 행렬입니다.
 */
template <typename T>
struct Matrix4x4
{
	/**
	 * @brief 4x4 행렬의 기본 생성자입니다.
	 *
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Matrix4x4() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0); m[0][3] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0); m[1][3] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0); m[2][3] = static_cast<T>(0);
		m[3][0] = static_cast<T>(0); m[3][1] = static_cast<T>(0); m[3][2] = static_cast<T>(0); m[3][3] = static_cast<T>(0);
	}


	/**
	 * @brief 4x4 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m03 행렬의 (0, 3) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m13 행렬의 (1, 3) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
	 * @param m23 행렬의 (2, 3) 성분입니다.
	 * @param m30 행렬의 (3, 0) 성분입니다.
	 * @param m31 행렬의 (3, 1) 성분입니다.
	 * @param m32 행렬의 (3, 2) 성분입니다.
	 * @param m33 행렬의 (3, 3) 성분입니다.
	 */
	Matrix4x4(
		T&& m00, T&& m01, T&& m02, T&& m03,
		T&& m10, T&& m11, T&& m12, T&& m13,
		T&& m20, T&& m21, T&& m22, T&& m23,
		T&& m30, T&& m31, T&& m32, T&& m33
	) noexcept
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}


	/**
	 * @brief 4x4 행렬의 생성자입니다.
	 *
	 * @param m00 행렬의 (0, 0) 성분입니다.
	 * @param m01 행렬의 (0, 1) 성분입니다.
	 * @param m02 행렬의 (0, 2) 성분입니다.
	 * @param m03 행렬의 (0, 3) 성분입니다.
	 * @param m10 행렬의 (1, 0) 성분입니다.
	 * @param m11 행렬의 (1, 1) 성분입니다.
	 * @param m12 행렬의 (1, 2) 성분입니다.
	 * @param m13 행렬의 (1, 3) 성분입니다.
	 * @param m20 행렬의 (2, 0) 성분입니다.
	 * @param m21 행렬의 (2, 1) 성분입니다.
	 * @param m22 행렬의 (2, 2) 성분입니다.
	 * @param m23 행렬의 (2, 3) 성분입니다.
	 * @param m30 행렬의 (3, 0) 성분입니다.
	 * @param m31 행렬의 (3, 1) 성분입니다.
	 * @param m32 행렬의 (3, 2) 성분입니다.
	 * @param m33 행렬의 (3, 3) 성분입니다.
	 */
	Matrix4x4(
		const T& m00, const T& m01, const T& m02, const T& m03,
		const T& m10, const T& m11, const T& m12, const T& m13,
		const T& m20, const T& m21, const T& m22, const T& m23,
		const T& m30, const T& m31, const T& m32, const T& m33
	) noexcept
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}


	/**
	 * @brief 4x4 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Matrix4x4(T&& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e; m[0][3] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e; m[1][3] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e; m[2][3] = e;
		m[3][0] = e; m[3][1] = e; m[3][2] = e; m[3][3] = e;
	}


	/**
	 * @brief 4x4 행렬의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param e 모든 원소를 초기화 할 값입니다.
	 */
	Matrix4x4(const T& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e; m[0][3] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e; m[1][3] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e; m[2][3] = e;
		m[3][0] = e; m[3][1] = e; m[3][2] = e; m[3][3] = e;
	}


	/**
	 * @brief 4x4 행렬의 복사 생성자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix4x4(Matrix4x4<T>&& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2]; m[0][3] = matrix.m[0][3];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2]; m[1][3] = matrix.m[1][3];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2]; m[2][3] = matrix.m[2][3];
		m[3][0] = matrix.m[3][0]; m[3][1] = matrix.m[3][1]; m[3][2] = matrix.m[3][2]; m[3][3] = matrix.m[3][3];
	}


	/**
	 * @brief 4x4 행렬의 복사 생성자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 */
	Matrix4x4(const Matrix4x4<T>& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2]; m[0][3] = matrix.m[0][3];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2]; m[1][3] = matrix.m[1][3];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2]; m[2][3] = matrix.m[2][3];
		m[3][0] = matrix.m[3][0]; m[3][1] = matrix.m[3][1]; m[3][2] = matrix.m[3][2]; m[3][3] = matrix.m[3][3];
	}


	/**
	 * @brief 4x4 행렬의 대입 연산자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix4x4<T>& operator=(Matrix4x4<T>&& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2]; m[0][3] = matrix.m[0][3];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2]; m[1][3] = matrix.m[1][3];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2]; m[2][3] = matrix.m[2][3];
		m[3][0] = matrix.m[3][0]; m[3][1] = matrix.m[3][1]; m[3][2] = matrix.m[3][2]; m[3][3] = matrix.m[3][3];

		return *this;
	}


	/**
	 * @brief 4x4 행렬의 대입 연산자입니다.
	 *
	 * @param matrix 원소를 복사할 행렬의 인스턴스입니다.
	 *
	 * @return 대입한 행렬의 참조자를 반환합니다.
	 */
	Matrix4x4<T>& operator=(const Matrix4x4<T>& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2]; m[0][3] = matrix.m[0][3];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2]; m[1][3] = matrix.m[1][3];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2]; m[2][3] = matrix.m[2][3];
		m[3][0] = matrix.m[3][0]; m[3][1] = matrix.m[3][1]; m[3][2] = matrix.m[3][2]; m[3][3] = matrix.m[3][3];

		return *this;
	}


	/**
	 * @brief 4x4 행렬의 모든 원소에 -부호를 취합니다.
	 *
	 * @return 모든 원소에 -부호를 취한 새로운 행렬을 반환합니다.
	 */
	Matrix4x4<T> operator-() const
	{
		return Matrix4x4<T>(
			-m[0][0], -m[0][1], -m[0][2], -m[0][3],
			-m[1][0], -m[1][1], -m[1][2], -m[1][3],
			-m[2][0], -m[2][1], -m[2][2], -m[2][3],
			-m[3][0], -m[3][1], -m[3][2], -m[3][3]
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param matrix 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix4x4<T> operator+(Matrix4x4<T>&& matrix) const
	{
		return Matrix4x4<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1], m[0][2] + matrix.m[0][2], m[0][3] + matrix.m[0][3],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1], m[1][2] + matrix.m[1][2], m[1][3] + matrix.m[1][3],
			m[2][0] + matrix.m[2][0], m[2][1] + matrix.m[2][1], m[2][2] + matrix.m[2][2], m[2][3] + matrix.m[2][3],
			m[3][0] + matrix.m[3][0], m[3][1] + matrix.m[3][1], m[3][2] + matrix.m[3][2], m[3][3] + matrix.m[3][3]
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 더합니다.
	 *
	 * @param matrix 행렬의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Matrix4x4<T> operator+(const Matrix4x4<T>& matrix) const
	{
		return Matrix4x4<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1], m[0][2] + matrix.m[0][2], m[0][3] + matrix.m[0][3],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1], m[1][2] + matrix.m[1][2], m[1][3] + matrix.m[1][3],
			m[2][0] + matrix.m[2][0], m[2][1] + matrix.m[2][1], m[2][2] + matrix.m[2][2], m[2][3] + matrix.m[2][3],
			m[3][0] + matrix.m[3][0], m[3][1] + matrix.m[3][1], m[3][2] + matrix.m[3][2], m[3][3] + matrix.m[3][3]
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix4x4<T> operator-(Matrix4x4<T>&& matrix) const
	{
		return Matrix4x4<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1], m[0][2] - matrix.m[0][2], m[0][3] - matrix.m[0][3],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1], m[1][2] - matrix.m[1][2], m[1][3] - matrix.m[1][3],
			m[2][0] - matrix.m[2][0], m[2][1] - matrix.m[2][1], m[2][2] - matrix.m[2][2], m[2][3] - matrix.m[2][3],
			m[3][0] - matrix.m[3][0], m[3][1] - matrix.m[3][1], m[3][2] - matrix.m[3][2], m[3][3] - matrix.m[3][3]
			);
	}


	/**
	 * @brief 두 4x4 행렬의 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 행렬의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬의 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Matrix4x4<T> operator-(const Matrix4x4<T>& matrix) const
	{
		return Matrix4x4<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1], m[0][2] - matrix.m[0][2], m[0][3] - matrix.m[0][3],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1], m[1][2] - matrix.m[1][2], m[1][3] - matrix.m[1][3],
			m[2][0] - matrix.m[2][0], m[2][1] - matrix.m[2][1], m[2][2] - matrix.m[2][2], m[2][3] - matrix.m[2][3],
			m[3][0] - matrix.m[3][0], m[3][1] - matrix.m[3][1], m[3][2] - matrix.m[3][2], m[3][3] - matrix.m[3][3]
			);
	}


	/**
	 * @brief 두 4x4 행렬을 곱합니다.
	 *
	 * @param matrix 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Matrix4x4<T> operator*(Matrix4x4<T>&& matrix) const
	{
		return Matrix4x4(
			m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0] + m[0][2] * matrix.m[2][0] + m[0][3] * matrix.m[3][0],
			m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1] + m[0][2] * matrix.m[2][1] + m[0][3] * matrix.m[3][1],
			m[0][0] * matrix.m[0][2] + m[0][1] * matrix.m[1][2] + m[0][2] * matrix.m[2][2] + m[0][3] * matrix.m[3][2],
			m[0][0] * matrix.m[0][3] + m[0][1] * matrix.m[1][3] + m[0][2] * matrix.m[2][3] + m[0][3] * matrix.m[3][3],
			m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0] + m[1][2] * matrix.m[2][0] + m[1][3] * matrix.m[3][0],
			m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1] + m[1][2] * matrix.m[2][1] + m[1][3] * matrix.m[3][1],
			m[1][0] * matrix.m[0][2] + m[1][1] * matrix.m[1][2] + m[1][2] * matrix.m[2][2] + m[1][3] * matrix.m[3][2],
			m[1][0] * matrix.m[0][3] + m[1][1] * matrix.m[1][3] + m[1][2] * matrix.m[2][3] + m[1][3] * matrix.m[3][3],
			m[2][0] * matrix.m[0][0] + m[2][1] * matrix.m[1][0] + m[2][2] * matrix.m[2][0] + m[2][3] * matrix.m[3][0],
			m[2][0] * matrix.m[0][1] + m[2][1] * matrix.m[1][1] + m[2][2] * matrix.m[2][1] + m[2][3] * matrix.m[3][1],
			m[2][0] * matrix.m[0][2] + m[2][1] * matrix.m[1][2] + m[2][2] * matrix.m[2][2] + m[2][3] * matrix.m[3][2],
			m[2][0] * matrix.m[0][3] + m[2][1] * matrix.m[1][3] + m[2][2] * matrix.m[2][3] + m[2][3] * matrix.m[3][3],
			m[3][0] * matrix.m[0][0] + m[3][1] * matrix.m[1][0] + m[3][2] * matrix.m[2][0] + m[3][3] * matrix.m[3][0],
			m[3][0] * matrix.m[0][1] + m[3][1] * matrix.m[1][1] + m[3][2] * matrix.m[2][1] + m[3][3] * matrix.m[3][1],
			m[3][0] * matrix.m[0][2] + m[3][1] * matrix.m[1][2] + m[3][2] * matrix.m[2][2] + m[3][3] * matrix.m[3][2],
			m[3][0] * matrix.m[0][3] + m[3][1] * matrix.m[1][3] + m[3][2] * matrix.m[2][3] + m[3][3] * matrix.m[3][3]
		);
	}


	/**
	 * @brief 두 4x4 행렬을 곱합니다.
	 *
	 * @param matrix 행렬의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 행렬을 곱한 결과를 반환합니다.
	 */
	Matrix4x4<T> operator*(const Matrix4x4<T>& matrix) const
	{
		return Matrix4x4(
			m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0] + m[0][2] * matrix.m[2][0] + m[0][3] * matrix.m[3][0],
			m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1] + m[0][2] * matrix.m[2][1] + m[0][3] * matrix.m[3][1],
			m[0][0] * matrix.m[0][2] + m[0][1] * matrix.m[1][2] + m[0][2] * matrix.m[2][2] + m[0][3] * matrix.m[3][2],
			m[0][0] * matrix.m[0][3] + m[0][1] * matrix.m[1][3] + m[0][2] * matrix.m[2][3] + m[0][3] * matrix.m[3][3],
			m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0] + m[1][2] * matrix.m[2][0] + m[1][3] * matrix.m[3][0],
			m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1] + m[1][2] * matrix.m[2][1] + m[1][3] * matrix.m[3][1],
			m[1][0] * matrix.m[0][2] + m[1][1] * matrix.m[1][2] + m[1][2] * matrix.m[2][2] + m[1][3] * matrix.m[3][2],
			m[1][0] * matrix.m[0][3] + m[1][1] * matrix.m[1][3] + m[1][2] * matrix.m[2][3] + m[1][3] * matrix.m[3][3],
			m[2][0] * matrix.m[0][0] + m[2][1] * matrix.m[1][0] + m[2][2] * matrix.m[2][0] + m[2][3] * matrix.m[3][0],
			m[2][0] * matrix.m[0][1] + m[2][1] * matrix.m[1][1] + m[2][2] * matrix.m[2][1] + m[2][3] * matrix.m[3][1],
			m[2][0] * matrix.m[0][2] + m[2][1] * matrix.m[1][2] + m[2][2] * matrix.m[2][2] + m[2][3] * matrix.m[3][2],
			m[2][0] * matrix.m[0][3] + m[2][1] * matrix.m[1][3] + m[2][2] * matrix.m[2][3] + m[2][3] * matrix.m[3][3],
			m[3][0] * matrix.m[0][0] + m[3][1] * matrix.m[1][0] + m[3][2] * matrix.m[2][0] + m[3][3] * matrix.m[3][0],
			m[3][0] * matrix.m[0][1] + m[3][1] * matrix.m[1][1] + m[3][2] * matrix.m[2][1] + m[3][3] * matrix.m[3][1],
			m[3][0] * matrix.m[0][2] + m[3][1] * matrix.m[1][2] + m[3][2] * matrix.m[2][2] + m[3][3] * matrix.m[3][2],
			m[3][0] * matrix.m[0][3] + m[3][1] * matrix.m[1][3] + m[3][2] * matrix.m[2][3] + m[3][3] * matrix.m[3][3]
		);
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix4x4<T>& operator+=(Matrix4x4<T>&& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1]; m[0][2] += matrix.m[0][2]; m[0][3] += matrix.m[0][3];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1]; m[1][2] += matrix.m[1][2]; m[1][3] += matrix.m[1][3];
		m[2][0] += matrix.m[2][0]; m[2][1] += matrix.m[2][1]; m[2][2] += matrix.m[2][2]; m[2][3] += matrix.m[2][3];
		m[3][0] += matrix.m[3][0]; m[3][1] += matrix.m[3][1]; m[3][2] += matrix.m[3][2]; m[3][3] += matrix.m[3][3];

		return *this;
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 더합니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix4x4<T>& operator+=(const Matrix4x4<T>& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1]; m[0][2] += matrix.m[0][2]; m[0][3] += matrix.m[0][3];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1]; m[1][2] += matrix.m[1][2]; m[1][3] += matrix.m[1][3];
		m[2][0] += matrix.m[2][0]; m[2][1] += matrix.m[2][1]; m[2][2] += matrix.m[2][2]; m[2][3] += matrix.m[2][3];
		m[3][0] += matrix.m[3][0]; m[3][1] += matrix.m[3][1]; m[3][2] += matrix.m[3][2]; m[3][3] += matrix.m[3][3];

		return *this;
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix4x4<T>& operator-=(Matrix4x4<T>&& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1]; m[0][2] -= matrix.m[0][2]; m[0][3] -= matrix.m[0][3];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1]; m[1][2] -= matrix.m[1][2]; m[1][3] -= matrix.m[1][3];
		m[2][0] -= matrix.m[2][0]; m[2][1] -= matrix.m[2][1]; m[2][2] -= matrix.m[2][2]; m[2][3] -= matrix.m[2][3];
		m[3][0] -= matrix.m[3][0]; m[3][1] -= matrix.m[3][1]; m[3][2] -= matrix.m[3][2]; m[3][3] -= matrix.m[3][3];

		return *this;
	}


	/**
	 * @brief 두 4x4 행렬에 대응하는 원소를 뺍니다.
	 *
	 * @param matrix 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 행렬의 참조자를 반환합니다.
	 */
	Matrix4x4<T>& operator-=(const Matrix4x4<T>& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1]; m[0][2] -= matrix.m[0][2]; m[0][3] -= matrix.m[0][3];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1]; m[1][2] -= matrix.m[1][2]; m[1][3] -= matrix.m[1][3];
		m[2][0] -= matrix.m[2][0]; m[2][1] -= matrix.m[2][1]; m[2][2] -= matrix.m[2][2]; m[2][3] -= matrix.m[2][3];
		m[3][0] -= matrix.m[3][0]; m[3][1] -= matrix.m[3][1]; m[3][2] -= matrix.m[3][2]; m[3][3] -= matrix.m[3][3];

		return *this;
	}


	/**
	 * @brief 4x4 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4x4 행렬 원소 배열의 포인터를 반환합니다.
	 */
	const T* GetPtr() const { return &m[0][0]; }


	/**
	 * @brief 4x4 행렬 원소 배열의 포인터를 얻습니다.
	 *
	 * @return 4x4 행렬 원소 배열의 포인터를 반환합니다.
	 */
	T* GetPtr() { return &m[0][0]; }


	/**
	 * @brief 4x4 행렬의 단위 행렬을 얻습니다.
	 *
	 * @return 4x4 행렬의 단위 행렬를 반환합니다.
	 */
	static Matrix4x4<T> GetIdentity()
	{
		return Matrix4x4(
			static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 4x4 행렬의 원소입니다.
	 */
	T m[4][4];
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


/**
 * @brief int32_t 타입의 2x2 행렬입니다.
 */
using Matrix2x2i = Matrix2x2<int32_t>;


/**
 * @brief float 타입의 2x2 행렬입니다.
 */
using Matrix2x2f = Matrix2x2<float>;


/**
 * @brief int32_t 타입의 3x3 행렬입니다.
 */
using Matrix3x3i = Matrix3x3<int32_t>;


/**
 * @brief float 타입의 3x3 행렬입니다.
 */
using Matrix3x3f = Matrix3x3<float>;


/**
 * @brief int32_t 타입의 4x4 행렬입니다.
 */
using Matrix4x4i = Matrix4x4<int32_t>;


/**
 * @brief float 타입의 4x4 행렬입니다.
 */
using Matrix4x4f = Matrix4x4<float>;