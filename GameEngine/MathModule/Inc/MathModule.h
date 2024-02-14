#pragma once

#include <cstdint>
#include <chrono>
#include <random>


/**
 * @brief ���ø� ����� 2���� �����Դϴ�.
 */
template <typename T>
struct Vector2
{
	/**
	 * @brief 2���� ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector2() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
	}


	/**
	 * @brief 2���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	Vector2(T&& xx, T&& yy) noexcept
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 2���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 */
	Vector2(const T& xx, const T& yy) noexcept
	{
		x = xx;
		y = yy;
	}


	/**
	 * @brief 2���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector2(T&& e) noexcept
	{
		x = e;
		y = e;
	}


	/**
	 * @brief 2���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector2(const T& e) noexcept
	{
		x = e;
		y = e;
	}


	/**
	 * @brief 2���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector2(Vector2<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
	}


	/**
	 * @brief 2���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector2(const Vector2<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
	}


	/**
	 * @brief 2���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator=(Vector2<T>&& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;

		return *this;
	}


	/**
	 * @brief 2���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator=(const Vector2<T>& v) noexcept
	{
		if (this == &v) return *this;

		x = v.x;
		y = v.y;

		return *this;
	}


	/**
	 * @brief 2���� ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return 2���� ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-() const
	{
		return Vector2<T>(-x, -y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator+(Vector2<T>&& v) const
	{
		return Vector2<T>(x + v.x, y + v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator+(const Vector2<T>& v) const
	{
		return Vector2<T>(x + v.x, y + v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-(Vector2<T>&& v) const
	{
		return Vector2<T>(x - v.x, y - v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator-(const Vector2<T>& v) const
	{
		return Vector2<T>(x - v.x, y - v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator*(Vector2<T>&& v) const
	{
		return Vector2<T>(x * v.x, y * v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector2<T> operator*(const Vector2<T>& v) const
	{
		return Vector2<T>(x * v.x, y * v.y);
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator+=(Vector2<T>&& v) noexcept
	{
		x += v.x;
		y += v.y;

		return *this;
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator+=(const Vector2<T>& v) noexcept
	{
		x += v.x;
		y += v.y;

		return *this;
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator-=(Vector2<T>&& v) noexcept
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}


	/**
	 * @brief �� 2���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector2<T>& operator-=(const Vector2<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;

		return *this;
	}


	/**
	 * @brief 2���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 2���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 2���� ������ �پ��� ���� �����Դϴ�.
	 *
	 * @note
	 * - x, y�� �ַ� ��ǥ ���� ��ǥ�� ��Ÿ�� �� ����մϴ�.
	 * - r, g�� �ַ� ������ ��Ÿ�� �� ����մϴ�.
	 * - s, t�� �ַ� �ؽ�ó ��ǥ�� ��Ÿ�� �� ����մϴ�(OpenGL ����).
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
 * @brief ���ø� ����� 3���� �����Դϴ�.
 */
template <typename T>
struct Vector3
{
	/**
	 * @brief 3���� ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector3() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
	}


	/**
	 * @brief 3���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 */
	Vector3(T&& xx, T&& yy, T&& zz) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 3���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 */
	Vector3(const T& xx, const T& yy, const T& zz) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
	}


	/**
	 * @brief 3���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector3(T&& e) noexcept
	{
		x = e;
		y = e;
		z = e;
	}


	/**
	 * @brief 3���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector3(const T& e) noexcept
	{
		x = e;
		y = e;
		z = e;
	}


	/**
	 * @brief 3���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector3(Vector3<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}


	/**
	 * @brief 3���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector3(const Vector3<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}


	/**
	 * @brief 3���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 3���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 3���� ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return 3���� ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator+(Vector3<T>&& v) const
	{
		return Vector3<T>(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator+(const Vector3<T>& v) const
	{
		return Vector3<T>(x + v.x, y + v.y, z + v.z);
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-(Vector3<T>&& v) const
	{
		return Vector3<T>(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator-(const Vector3<T>& v) const
	{
		return Vector3<T>(x - v.x, y - v.y, z - v.z);
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator*(Vector3<T>&& v) const
	{
		return Vector3<T>(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector3<T> operator*(const Vector3<T>& v) const
	{
		return Vector3<T>(x * v.x, y * v.y, z * v.z);
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator+=(Vector3<T>&& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator+=(const Vector3<T>& v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;

		return *this;
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator-=(Vector3<T>&& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief �� 3���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
	 */
	Vector3<T>& operator-=(const Vector3<T>& v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;

		return *this;
	}


	/**
	 * @brief 3���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 3���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 3���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 3���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 3���� ������ �پ��� ���� �����Դϴ�.
	 *
	 * @note
	 * - x, y, z�� �ַ� ���� ���� ��ǥ�� ��Ÿ�� �� ����մϴ�.
	 * - r, g, b�� �ַ� ������ ��Ÿ�� �� ����մϴ�.
	 * - s, t, r�� �ַ� �ؽ�ó ��ǥ�� ��Ÿ�� �� ����մϴ�(OpenGL ����).
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
 * @brief ���ø� ����� 4���� �����Դϴ�.
 */
template <typename T>
struct Vector4
{
	/**
	 * @brief 4���� ������ �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Vector4() noexcept
	{
		x = static_cast<T>(0);
		y = static_cast<T>(0);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}


	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vector4(T&& xx, T&& yy, T&& zz, T&& ww) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 4���� ������ �������Դϴ�.
	 *
	 * @param xx ������ x �����Դϴ�.
	 * @param yy ������ y �����Դϴ�.
	 * @param zz ������ z �����Դϴ�.
	 * @param ww ������ w �����Դϴ�.
	 */
	Vector4(const T& xx, const T& yy, const T& zz, const T& ww) noexcept
	{
		x = xx;
		y = yy;
		z = zz;
		w = ww;
	}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector4(T&& e) noexcept
	{
		x = e;
		y = e;
		z = e;
		w = e;
	}


	/**
	 * @brief 4���� ������ ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Vector4(const T& e) noexcept
	{
		x = e;
		y = e;
		z = e;
		w = e;
	}


	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Vector4(Vector4<T>&& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}


	/**
	 * @brief 4���� ������ ���� �������Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ������ �ν��Ͻ��Դϴ�.
	 */
	Vector4(const Vector4<T>& v) noexcept
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}


	/**
	 * @brief 4���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 4���� ������ ���� ������ �Դϴ�.
	 *
	 * @param v ���Ҹ� ������ ���� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 4���� ������ ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return 4���� ������ ���ҿ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-() const
	{
		return Vector4<T>(-x, -y, -z, -w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator+(Vector4<T>&& v) const
	{
		return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator+(const Vector4<T>& v) const
	{
		return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-(Vector4<T>&& v) const
	{
		return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator-(const Vector4<T>& v) const
	{
		return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator*(Vector4<T>&& v) const
	{
		return Vector4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���� ���մϴ�.
	 *
	 * @note �� ������ ������ ���� ����(Dot Product)�ʹ� �ٸ��ϴ�.
	 *
	 * @param v ������ ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���Ϳ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Vector4<T> operator*(const Vector4<T>& v) const
	{
		return Vector4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
	}


	/**
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief �� 4���� ���Ϳ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param v ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ������ �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &data[0]; }


	/**
	 * @brief 4���� ���� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4���� ���� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &data[0]; }


	/**
	 * @brief 4���� ������ �پ��� ���� �����Դϴ�.
	 *
	 * @note
	 * - x, y, z, w�� �ַ� ���� ���� ��ǥ�� ��Ÿ�� �� ����մϴ�.
	 * - r, g, b, a�� �ַ� ������ ��Ÿ�� �� ����մϴ�.
	 * - s, t, r, q�� �ַ� �ؽ�ó ��ǥ�� ��Ÿ�� �� ����մϴ�(OpenGL ����).
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
 * @brief ���ø� ����� 2x2 ����Դϴ�.
 */
template <typename T>
struct Matrix2x2
{
	/**
	 * @brief 2x2 ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix2x2() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0);
	}


	/**
	 * @brief 2x2 ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
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
	 * @brief 2x2 ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
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
	 * @brief 2x2 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix2x2(T&& e) noexcept
	{
		m[0][0] = e; m[0][1] = e;
		m[1][0] = e; m[1][1] = e;
	}


	/**
	 * @brief 2x2 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix2x2(const T& e) noexcept
	{
		m[0][0] = e; m[0][1] = e;
		m[1][0] = e; m[1][1] = e;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix2x2(Matrix2x2<T>&& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix2x2(const Matrix2x2<T>& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator=(Matrix2x2<T>&& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 2x2 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator=(const Matrix2x2<T>& matrix) noexcept
	{
		if (this == &matrix) return *this;

		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 2x2 ����� ��� ���ҿ� - ��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� -��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-() const
	{
		return Matrix2x2<T>(
			-m[0][0], -m[0][1],
			-m[1][0], -m[1][1]
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator+(Matrix2x2<T>&& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1]
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator+(const Matrix2x2<T>& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] + matrix.m[0][0], m[0][1] + matrix.m[0][1],
			m[1][0] + matrix.m[1][0], m[1][1] + matrix.m[1][1]
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-(Matrix2x2<T>&& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1]
			);
	}


	/**
	 * @brief �� 2x2 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Matrix2x2<T> operator-(const Matrix2x2<T>& matrix) const
	{
		return Matrix2x2<T>(
			m[0][0] - matrix.m[0][0], m[0][1] - matrix.m[0][1],
			m[1][0] - matrix.m[1][0], m[1][1] - matrix.m[1][1]
			);
	}


	/**
	 * @brief �� 2x2 ����� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 2x2 ����� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator+=(Matrix2x2<T>&& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator+=(const Matrix2x2<T>& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator-=(Matrix2x2<T>&& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief �� 2x2 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix2x2<T>& operator-=(const Matrix2x2<T>& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1];

		return *this;
	}


	/**
	 * @brief 2x2 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2x2 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &m[0][0]; }


	/**
	 * @brief 2x2 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 2x2 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &m[0][0]; }


	/**
	 * @brief 2x2 ����� ���� ����� ����ϴ�.
	 *
	 * @return 2x2 ����� ���� ��ĸ� ��ȯ�մϴ�.
	 */
	static Matrix2x2<T> Identity()
	{
		return Matrix2x2(
			static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 2x2 ����� �����Դϴ�.
	 */
	T m[2][2];
};


/**
 * @brief ���ø� ����� 3x3 ����Դϴ�.
 */
template <typename T>
struct Matrix3x3
{
	/**
	 * @brief 3x3 ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix3x3() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0);
	}


	/**
	 * @brief 3x3 ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
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
	 * @brief 3x3 ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
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
	 * @brief 3x3 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix3x3(T&& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e;
	}


	/**
	 * @brief 3x3 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix3x3(const T& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e;
	}


	/**
	 * @brief 3x3 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix3x3(Matrix3x3<T>&& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2];
	}


	/**
	 * @brief 3x3 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix3x3(const Matrix3x3<T>& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2];
	}


	/**
	 * @brief 3x3 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 3x3 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 3x3 ����� ��� ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� -��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
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
	 * @brief �� 3x3 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 3x3 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 3x3 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
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
	 * @brief �� 3x3 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
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
	 * @brief �� 3x3 ����� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 3x3 ����� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 3x3 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator+=(Matrix3x3<T>&& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1]; m[0][2] += matrix.m[0][2];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1]; m[1][2] += matrix.m[1][2];
		m[2][0] += matrix.m[2][0]; m[2][1] += matrix.m[2][1]; m[2][2] += matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief �� 3x3 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator+=(const Matrix3x3<T>& matrix) noexcept
	{
		m[0][0] += matrix.m[0][0]; m[0][1] += matrix.m[0][1]; m[0][2] += matrix.m[0][2];
		m[1][0] += matrix.m[1][0]; m[1][1] += matrix.m[1][1]; m[1][2] += matrix.m[1][2];
		m[2][0] += matrix.m[2][0]; m[2][1] += matrix.m[2][1]; m[2][2] += matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief �� 3x3 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator-=(Matrix3x3<T>&& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1]; m[0][2] -= matrix.m[0][2];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1]; m[1][2] -= matrix.m[1][2];
		m[2][0] -= matrix.m[2][0]; m[2][1] -= matrix.m[2][1]; m[2][2] -= matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief �� 3x3 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
	 */
	Matrix3x3<T>& operator-=(const Matrix3x3<T>& matrix) noexcept
	{
		m[0][0] -= matrix.m[0][0]; m[0][1] -= matrix.m[0][1]; m[0][2] -= matrix.m[0][2];
		m[1][0] -= matrix.m[1][0]; m[1][1] -= matrix.m[1][1]; m[1][2] -= matrix.m[1][2];
		m[2][0] -= matrix.m[2][0]; m[2][1] -= matrix.m[2][1]; m[2][2] -= matrix.m[2][2];

		return *this;
	}


	/**
	 * @brief 3x3 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 3x3 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &m[0][0]; }


	/**
	 * @brief 3x3 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 3x3 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &m[0][0]; }


	/**
	 * @brief 3x3 ����� ���� ����� ����ϴ�.
	 *
	 * @return 3x3 ����� ���� ��ĸ� ��ȯ�մϴ�.
	 */
	static Matrix3x3<T> Identity()
	{
		return Matrix3x3(
			static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 3x3 ����� �����Դϴ�.
	 */
	T m[3][3];
};


/**
 * @brief ���ø� ����� 4x4 ����Դϴ�.
 */
template <typename T>
struct Matrix4x4
{
	/**
	 * @brief 4x4 ����� �⺻ �������Դϴ�.
	 *
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Matrix4x4() noexcept
	{
		m[0][0] = static_cast<T>(0); m[0][1] = static_cast<T>(0); m[0][2] = static_cast<T>(0); m[0][3] = static_cast<T>(0);
		m[1][0] = static_cast<T>(0); m[1][1] = static_cast<T>(0); m[1][2] = static_cast<T>(0); m[1][3] = static_cast<T>(0);
		m[2][0] = static_cast<T>(0); m[2][1] = static_cast<T>(0); m[2][2] = static_cast<T>(0); m[2][3] = static_cast<T>(0);
		m[3][0] = static_cast<T>(0); m[3][1] = static_cast<T>(0); m[3][2] = static_cast<T>(0); m[3][3] = static_cast<T>(0);
	}


	/**
	 * @brief 4x4 ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m03 ����� (0, 3) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m13 ����� (1, 3) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 * @param m23 ����� (2, 3) �����Դϴ�.
	 * @param m30 ����� (3, 0) �����Դϴ�.
	 * @param m31 ����� (3, 1) �����Դϴ�.
	 * @param m32 ����� (3, 2) �����Դϴ�.
	 * @param m33 ����� (3, 3) �����Դϴ�.
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
	 * @brief 4x4 ����� �������Դϴ�.
	 *
	 * @param m00 ����� (0, 0) �����Դϴ�.
	 * @param m01 ����� (0, 1) �����Դϴ�.
	 * @param m02 ����� (0, 2) �����Դϴ�.
	 * @param m03 ����� (0, 3) �����Դϴ�.
	 * @param m10 ����� (1, 0) �����Դϴ�.
	 * @param m11 ����� (1, 1) �����Դϴ�.
	 * @param m12 ����� (1, 2) �����Դϴ�.
	 * @param m13 ����� (1, 3) �����Դϴ�.
	 * @param m20 ����� (2, 0) �����Դϴ�.
	 * @param m21 ����� (2, 1) �����Դϴ�.
	 * @param m22 ����� (2, 2) �����Դϴ�.
	 * @param m23 ����� (2, 3) �����Դϴ�.
	 * @param m30 ����� (3, 0) �����Դϴ�.
	 * @param m31 ����� (3, 1) �����Դϴ�.
	 * @param m32 ����� (3, 2) �����Դϴ�.
	 * @param m33 ����� (3, 3) �����Դϴ�.
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
	 * @brief 4x4 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix4x4(T&& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e; m[0][3] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e; m[1][3] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e; m[2][3] = e;
		m[3][0] = e; m[3][1] = e; m[3][2] = e; m[3][3] = e;
	}


	/**
	 * @brief 4x4 ����� ���Ҹ� �ϳ��� ������ �ʱ�ȭ�մϴ�.
	 *
	 * @param e ��� ���Ҹ� �ʱ�ȭ �� ���Դϴ�.
	 */
	Matrix4x4(const T& e) noexcept
	{
		m[0][0] = e; m[0][1] = e; m[0][2] = e; m[0][3] = e;
		m[1][0] = e; m[1][1] = e; m[1][2] = e; m[1][3] = e;
		m[2][0] = e; m[2][1] = e; m[2][2] = e; m[2][3] = e;
		m[3][0] = e; m[3][1] = e; m[3][2] = e; m[3][3] = e;
	}


	/**
	 * @brief 4x4 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix4x4(Matrix4x4<T>&& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2]; m[0][3] = matrix.m[0][3];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2]; m[1][3] = matrix.m[1][3];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2]; m[2][3] = matrix.m[2][3];
		m[3][0] = matrix.m[3][0]; m[3][1] = matrix.m[3][1]; m[3][2] = matrix.m[3][2]; m[3][3] = matrix.m[3][3];
	}


	/**
	 * @brief 4x4 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 */
	Matrix4x4(const Matrix4x4<T>& matrix) noexcept
	{
		m[0][0] = matrix.m[0][0]; m[0][1] = matrix.m[0][1]; m[0][2] = matrix.m[0][2]; m[0][3] = matrix.m[0][3];
		m[1][0] = matrix.m[1][0]; m[1][1] = matrix.m[1][1]; m[1][2] = matrix.m[1][2]; m[1][3] = matrix.m[1][3];
		m[2][0] = matrix.m[2][0]; m[2][1] = matrix.m[2][1]; m[2][2] = matrix.m[2][2]; m[2][3] = matrix.m[2][3];
		m[3][0] = matrix.m[3][0]; m[3][1] = matrix.m[3][1]; m[3][2] = matrix.m[3][2]; m[3][3] = matrix.m[3][3];
	}


	/**
	 * @brief 4x4 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 4x4 ����� ���� �������Դϴ�.
	 *
	 * @param matrix ���Ҹ� ������ ����� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 4x4 ����� ��� ���ҿ� -��ȣ�� ���մϴ�.
	 *
	 * @return ��� ���ҿ� -��ȣ�� ���� ���ο� ����� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ����� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ����� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ����� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ����� ���մϴ�.
	 *
	 * @param matrix ����� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ����� ���� ����� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ��Ŀ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief �� 4x4 ��Ŀ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param matrix ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ����� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief 4x4 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4x4 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	const T* GetPtr() const { return &m[0][0]; }


	/**
	 * @brief 4x4 ��� ���� �迭�� �����͸� ����ϴ�.
	 *
	 * @return 4x4 ��� ���� �迭�� �����͸� ��ȯ�մϴ�.
	 */
	T* GetPtr() { return &m[0][0]; }


	/**
	 * @brief 4x4 ����� ���� ����� ����ϴ�.
	 *
	 * @return 4x4 ����� ���� ��ĸ� ��ȯ�մϴ�.
	 */
	static Matrix4x4<T> Identity()
	{
		return Matrix4x4(
			static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)
		);
	}


	/**
	 * @brief 4x4 ����� �����Դϴ�.
	 */
	T m[4][4];
};


/**
 * @brief int32_t Ÿ���� 2���� �����Դϴ�.
 */
using Vector2i = Vector2<int32_t>;


/**
 * @brief float Ÿ���� 2���� �����Դϴ�.
 */
using Vector2f = Vector2<float>;


/**
 * @brief int32_t Ÿ���� 3���� �����Դϴ�.
 */
using Vector3i = Vector3<int32_t>;


/**
 * @brief float Ÿ���� 3���� �����Դϴ�.
 */
using Vector3f = Vector3<float>;


/**
 * @brief int32_t Ÿ���� 4���� �����Դϴ�.
 */
using Vector4i = Vector4<int32_t>;


/**
 * @brief float Ÿ���� 4���� �����Դϴ�.
 */
using Vector4f = Vector4<float>;


/**
 * @brief int32_t Ÿ���� 2x2 ����Դϴ�.
 */
using Matrix2x2i = Matrix2x2<int32_t>;


/**
 * @brief float Ÿ���� 2x2 ����Դϴ�.
 */
using Matrix2x2f = Matrix2x2<float>;


/**
 * @brief int32_t Ÿ���� 3x3 ����Դϴ�.
 */
using Matrix3x3i = Matrix3x3<int32_t>;


/**
 * @brief float Ÿ���� 3x3 ����Դϴ�.
 */
using Matrix3x3f = Matrix3x3<float>;


/**
 * @brief int32_t Ÿ���� 4x4 ����Դϴ�.
 */
using Matrix4x4i = Matrix4x4<int32_t>;


/**
 * @brief float Ÿ���� 4x4 ����Դϴ�.
 */
using Matrix4x4f = Matrix4x4<float>;


/**
 * ���� ���� ����� �����մϴ�.
 */
namespace MathModule
{
	/**
	 * @brief ����(��) ���Դϴ�.
	 */
	const float Pi = 3.141592654f;


	/**
	 * @brief 2����(2��) ���Դϴ�.
	 */
	const float TwoPi = 6.283185307f;


	/**
	 * @brief ����(��) �� ���� ���Դϴ�.
	 */
	const float OneDivPi = 0.318309886f;


	/**
	 * @brief 2����(2��) �� ���� ���Դϴ�.
	 */
	const float OneDivTwoPi = 0.159154943f;


	/**
	 * @brief ����(��) �� �ݰ�(��/2)�Դϴ�.
	 */
	const float PiDiv2 = 1.570796327f;


	/**
	 * @brief ����(��) �� ���� �� ��(��/4)�Դϴ�.
	 */
	const float PiDiv4 = 0.785398163f;


	/**
	 * @brief ���Ƿ�(��) ���Դϴ�.
	 */
	const float Epsilon = 1.192092896e-07F;


	/**
	 * @brief ���� ���� ���ʺй� ������ ��ȯ�մϴ�.
	 *
	 * @param radian ��ȯ�� ���� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���ʺй� ���Դϴ�.
	 */
	inline float ToDegree(float radian)
	{
		return (radian * 180.0f) / Pi;
	}


	/**
	 * @brief ���ʺй� ���� ���� ������ ��ȯ�մϴ�.
	 *
	 * @param degree ��ȯ�� ���ʺй� ���Դϴ�.
	 *
	 * @return ��ȯ�� ���� ���Դϴ�.
	 */
	inline float ToRadian(float degree)
	{
		return (degree * Pi) / 180.0f;
	}


	/**
	 * @brief �ε� �Ҽ��� ���� 0�� ������� Ȯ���մϴ�.
	 *
	 * @param value 0�� ������� Ȯ���� ���Դϴ�.
	 * @param epsilon �� Ȯ���� ���� ���Ƿ� ���Դϴ�.
	 *
	 * @return �ε� �Ҽ��� ���� 0�� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	inline bool NearZero(float value, float epsilon = Epsilon)
	{
		return (std::fabs(value) <= epsilon);
	}


	/**
	 * @brief �� ���� ū ���� ��ȯ�մϴ�.
	 *
	 * @param lhs ũ�⸦ ���� �� �� ���� ���Դϴ�.
	 * @param rhs ũ�⸦ ���� �� �� ������ ���Դϴ�.
	 *
	 * @return �� �� �� ū ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T Max(const T& lhs, const T& rhs)
	{
		return (lhs < rhs ? rhs : lhs);
	}


	/**
	 * @brief �� ���� ���� ���� ��ȯ�մϴ�.
	 *
	 * @param lhs ũ�⸦ ���� �� �� ���� ���Դϴ�.
	 * @param rhs ũ�⸦ ���� �� �� ������ ���Դϴ�.
	 *
	 * @return �� �� �� ���� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T Min(const T& lhs, const T& rhs)
	{
		return (lhs < rhs ? lhs : rhs);
	}


	/**
	 * @brief ���� ������ �����ϴ� ���� ���� ����ϴ�.
	 * 
	 * @param radian ���� ���� ���� ���� �����Դϴ�.
	 * 
	 * @return ���� ������ �����ϴ� ���ΰ��� ��ȯ�մϴ�.
	 * 
	 * @note
	 * - DirectXMath�� XMScalarSin ����
	 * - �˰����� 11���� �̴ϸƽ�(Minimax) �ٻ�ġ(1th-degree Minimax approximation) ���
	 * - https://gist.github.com/publik-void/067f7f2fef32dbe5c27d6e215f824c91
	 */
	inline float Sin(float radian)
	{
		float quotient = OneDivTwoPi * radian;
		if (radian >= 0.0f)
		{
			quotient = static_cast<float>(static_cast<int>(quotient + 0.5f));
		}
		else
		{
			quotient = static_cast<float>(static_cast<int>(quotient - 0.5f));
		}

		float y = radian - TwoPi * quotient;

		if (y > PiDiv2)
		{
			y = Pi - y;
		}
		else if (y < -PiDiv2)
		{
			y = -Pi - y;
		}

		float y2 = y * y;
		return (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;
	}


	/**
	 * @brief ���� ������ �����ϴ� �ڻ��� ���� ��ȯ�մϴ�.
	 *
	 * @param radian �ڻ��� ���� ���� ���� �����Դϴ�.
	 *
	 * @return ���� ������ �����ϴ� �ڻ��ΰ��� ��ȯ�մϴ�.
	 *
	 * @note
	 * - DirectXMath�� XMScalarCos ����
	 * - �˰����� 10���� �̴ϸƽ�(Minimax) �ٻ�ġ(1th-degree Minimax approximation) ���
	 * - https://gist.github.com/publik-void/067f7f2fef32dbe5c27d6e215f824c91
	 */
	inline float Cos(float radian)
	{
		float quotient = OneDivTwoPi * radian;
		if (radian >= 0.0f)
		{
			quotient = static_cast<float>(static_cast<int>(quotient + 0.5f));
		}
		else
		{
			quotient = static_cast<float>(static_cast<int>(quotient - 0.5f));
		}

		float y = radian - TwoPi * quotient;
		float sign = 1.0f;

		if (y > PiDiv2)
		{
			y = Pi - y;
			sign = -1.0f;
		}
		else if (y < -PiDiv2)
		{
			y = -Pi - y;
			sign = -1.0f;
		}

		float y2 = y * y;
		float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;

		return sign * p;
	}


	/**
	 * @brief ���� [lower, upper] ������ �ڸ��ϴ�.
	 *
	 * @param value ������ �ڸ� ���Դϴ�.
	 * @param lower ������ �ּҰ��Դϴ�.
	 * @param upper ������ �ִ밪�Դϴ�.
	 *
	 * @return ������ �߷� ���� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T Clamp(const T& value, const T& lower, const T& upper)
	{
		return Min(upper, Max(lower, value));
	}


	/**
	 * @brief 2���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T DotProduct(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}


	/**
	 * @brief 3���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T DotProduct(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}


	/**
	 * @brief 4���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T DotProduct(const Vector4<T>& lhs, const Vector4<T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}


	/**
	 * @brief 2���� ������ ���� ������ �����մϴ�.
	 *
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 *
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 *
	 * @note �Ϲ����� 3���� ���� ����� �ٸ��ϴ�.
	 */
	template <typename T>
	inline T CrossProduct(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}


	/**
	 * @brief 3���� ������ ���� ������ �����մϴ�.
	 * 
	 * @param lhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * @param rhs ������ ���� ������ ������ ���� �ǿ������Դϴ�.
	 * 
	 * @return ���� ���� ����� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline Vector3<T> CrossProduct(const Vector3<T>& lhs, const Vector3<T>& rhs)
	{
		return Vector3<T>(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}


	/**
	 * @brief 2���� ������ ũ�� ���� ���� ����մϴ�.
	 *
	 * @param v ũ�� ������ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T LengthSquare(const Vector2<T>& v)
	{
		return v.x * v.x + v.y * v.y;
	}


	/**
	 * @brief 3���� ������ ũ�� ���� ���� ����մϴ�.
	 *
	 * @param v ũ�� ������ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T LengthSquare(const Vector3<T>& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}


	/**
	 * @brief 4���� ������ ũ�� ���� ���� ����մϴ�.
	 *
	 * @param v ũ�� ������ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline T LengthSquare(const Vector4<T>& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	}


	/**
	 * @brief 2���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param v ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline float Length(const Vector2<T>& v)
	{
		float lengthSquare = static_cast<float>(LengthSquare<T>(v));
		return std::sqrtf(lengthSquare);
	}


	/**
	 * @brief 3���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param v ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline float Length(const Vector3<T>& v)
	{
		float lengthSquare = static_cast<float>(LengthSquare<T>(v));
		return std::sqrtf(lengthSquare);
	}


	/**
	 * @brief 4���� ������ ũ�⸦ ����ϴ�.
	 *
	 * @param v ũ�⸦ ����� �����Դϴ�.
	 *
	 * @return ���� ũ�� ���� ��ȯ�մϴ�.
	 */
	template <typename T>
	inline float Length(const Vector4<T>& v)
	{
		float lengthSquare = static_cast<float>(LengthSquare<T>(v));
		return std::sqrtf(lengthSquare);
	}


	/**
	 * @brief 2���� ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ �� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	inline Vector2f Normalize(const Vector2f& v)
	{
		float length = Length(v);
		return Vector2f(v.x / length, v.y / length);
	}


	/**
	 * @brief 3���� ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ �� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	inline Vector3f Normalize(const Vector3f& v)
	{
		float length = Length(v);
		return Vector3f(v.x / length, v.y / length, v.z / length);
	}


	/**
	 * @brief 4���� ���͸� ����ȭ�մϴ�.
	 *
	 * @param v ����ȭ �� �����Դϴ�.
	 *
	 * @return ����ȭ�� ���͸� ��ȯ�մϴ�.
	 */
	inline Vector4f Normalize(const Vector4f& v)
	{
		float length = Length(v);
		return Vector4f(v.x / length, v.y / length, v.z / length, v.w / length);
	}


	/**
	 * @brief ������ ������ �����մϴ�.
	 *
	 * @param minValue ������ ���� ������ �ּڰ��Դϴ�.
	 * @param maxValue ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return ������ ������ ������ ��ȯ�մϴ�.
	 */
	inline int32_t GenerateRandomInt(int32_t minValue, int32_t maxValue)
	{
		std::random_device randomDevice;
		std::mt19937 generator(randomDevice());
		std::uniform_int_distribution<int32_t> distribution(Min<int32_t>(minValue, maxValue), Max<int32_t>(minValue, maxValue));

		return distribution(generator);
	}


	/**
	 * @brief ������ �Ǽ��� �����մϴ�.
	 *
	 * @param minValue ������ ���� ������ �ּڰ��Դϴ�.
	 * @param maxValue ������ ���� ������ �ִ��Դϴ�.
	 *
	 * @return ������ ������ �Ǽ��� ��ȯ�մϴ�.
	 */
	inline float GenerateRandomFloat(float minValue, float maxValue)
	{
		std::random_device randomDevice;
		std::mt19937 generator(randomDevice());
		std::uniform_real_distribution<float> distribution(Min<float>(minValue, maxValue), Max<float>(minValue, maxValue));

		return distribution(generator);
	}


	/**
	 * @brief �̵� ��ȯ ����� �����մϴ�.
	 *
	 * @param x �̵��� x ��ǥ���Դϴ�.
	 * @param y �̵��� y ��ǥ���Դϴ�.
	 * @param z �̵��� z ��ǥ���Դϴ�.
	 *
	 * @return ������ �̵� ��ȯ ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateTranslation(float x, float y, float z)
	{
		return Matrix4x4f(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			   x,    y,    z, 1.0f
		);
	}


	/**
	 * @brief �̵� ��ȯ ����� �����մϴ�.
	 *
	 * @param p �̵��� ��ġ ��ǥ�Դϴ�.
	 *
	 * @return ������ �̵� ��ȯ ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateTranslation(const Vector3f& p)
	{
		return Matrix4x4f(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			 p.x,  p.y,  p.z, 1.0f
		);
	}


	/**
	 * @brief ������ ��ȯ ����� �����մϴ�.
	 *
	 * @param xScale ��ȯ�� x�� ������ �������Դϴ�.
	 * @param yScale ��ȯ�� y�� ������ �������Դϴ�.
	 * @param zScale ��ȯ�� z�� ������ �������Դϴ�.
	 *
	 * @return ������ ������ ��ȯ ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateScale(float xScale, float yScale, float zScale)
	{
		return Matrix4x4f(
			xScale, 0.0f, 0.0f, 0.0f,
			0.0f, yScale, 0.0f, 0.0f,
			0.0f, 0.0f, zScale, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}


	/**
	 * @brief ������ ��ȯ ����� �����մϴ�.
	 *
	 * @param scale ��ȯ�� ������ �����Դϴ�.
	 *
	 * @return ������ ������ ��ȯ ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateScale(const Vector3f& scale)
	{
		return Matrix4x4f(
			scale.x, 0.0f, 0.0f, 0.0f,
			0.0f, scale.y, 0.0f, 0.0f,
			0.0f, 0.0f, scale.z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}


	/**
	 * @brief X������ ȸ����Ű�� ȸ�� ����� �����մϴ�.
	 *
	 * @param radian ȸ���� ���� �����Դϴ�.
	 *
	 * @return ������ ȸ�� ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateRotateX(float radian)
	{
		float s = Sin(radian);
		float c = Cos(radian);

		return Matrix4x4f(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f,    c,    s, 0.0f,
			0.0f,   -s,    c, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}


	/**
	 * @brief Y������ ȸ����Ű�� ȸ�� ����� �����մϴ�.
	 *
	 * @param radian ȸ���� ���� �����Դϴ�.
	 *
	 * @return ������ ȸ�� ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateRotateY(float radian)
	{
		float s = Sin(radian);
		float c = Cos(radian);

		return Matrix4x4f(
			   c, 0.0f,   -s, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			   s, 0.0f,    c, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}


	/**
	 * @brief Z������ ȸ����Ű�� ȸ�� ����� �����մϴ�.
	 *
	 * @param radian ȸ���� ���� �����Դϴ�.
	 *
	 * @return ������ ȸ�� ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateRotateZ(float radian)
	{
		float s = Sin(radian);
		float c = Cos(radian);

		return Matrix4x4f(
			   c,    s, 0.0f, 0.0f,
			  -s,    c, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}


	/**
	 * @brief ������ ���͸� �������� ȸ�� ����� �����մϴ�.
	 * 
	 * @param radian ȸ���� ȸ�� �����Դϴ�.
	 * @param axis ȸ�����Դϴ�.
	 * 
	 * @return ������ ȸ�� ����� ��ȯ�մϴ�.
	 * 
	 * @see 
	 * - �ε帮�Խ� ȸ�� ���� ����
	 * - https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
	 */
	inline Matrix4x4f CreateRotate(float radian, const Vector3f& axis)
	{
		float s = Sin(radian);
		float c = Cos(radian);
		Vector3f r = Normalize(axis);

		return Matrix4x4f(
		  	      c + r.x * r.x * (1.0f - c), r.y * r.x * (1.0f - c) + r.z * s, r.z * r.x * (1.0f - c) - r.y * s, 0.0f,
			r.x * r.y * (1.0f - c) - r.z * s,       c + r.y * r.y * (1.0f - c), r.z * r.y * (1.0f - c) + r.x * s, 0.0f,
			r.x * r.z * (1.0f - c) + r.y * s, r.y * r.z * (1.0f - c) - r.x * s,       c + r.z * r.z * (1.0f - c), 0.0f,
			                            0.0f,                             0.0f,                             0.0f, 1.0f
		);
	}


	/**
	 * @brief ���� ���� ����� �����մϴ�.
	 *
	 * @param left   ���� ������ ���� ��� ��� ��
	 * @param right  ���� ������ ���� ��� ��� ��
	 * @param bottom ���� ������ �ϴ� ��� ��� ��
	 * @param top    ���� ������ ��� ��� ��� ��
	 * @param zNear  ���� ������ ���� ��� ��� ��
	 * @param zFar   ���� ������ �Ĺ� ��� ��� ��
	 *
	 * @return ������ ���� ���� ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		float width = (right - left);
		float sumLR = (right + left);
		float height = (top - bottom);
		float sumTB = (top + bottom);
		float depth = (zFar - zNear);
		float sumNF = (zFar + zNear);

		return Matrix4x4f(
			  2.0f / width,            0.0f,           0.0f, 0.0f,
			          0.0f,   2.0f / height,           0.0f, 0.0f,
			          0.0f,            0.0f,  -2.0f / depth, 0.0f,
			-sumLR / width, -sumTB / height, -sumNF / depth, 1.0f
		);
	}


	/**
	 * @brief ���� ���� ����� �����մϴ�.
	 * 
	 * @param fov ���� ������ �þ� �����Դϴ�.
	 * @param aspect �� ������ ����/���� �����Դϴ�.
	 * @param nearZ ����� Ŭ���� ��� ������ �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * @param farZ ���Ÿ� Ŭ���� ��� ������ �Ÿ��Դϴ�. 0���� Ŀ�� �մϴ�.
	 * 
	 * @return ������ ���� ���� ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreatePerspective(float fov, float aspect, float nearZ, float farZ)
	{
		float halfFov = fov / 2.0f;
		float tanHalfFovy = Sin(halfFov) / Cos(halfFov);
		
		return Matrix4x4f(
			1.0f / (aspect * tanHalfFovy),                 0.0f,                                    0.0f,  0.0f,
			                         0.0f, 1.0f / (tanHalfFovy),                                    0.0f,  0.0f,
			                         0.0f,                 0.0f,        -(farZ + nearZ) / (farZ - nearZ), -1.0f,
			                         0.0f,                 0.0f, -(2.0f * farZ * nearZ) / (farZ - nearZ),  1.0f
		);
	}


	/**
	 * @brief �þ� ����� �����մϴ�.
	 * 
	 * @param eyePosition ī�޶��� ��ġ�Դϴ�.
	 * @param focusPosition ������ ��ġ�Դϴ�.
	 * @param upDirection ī�޶��� ���� �����Դϴ�. �Ϲ������� <0.0f, 1.0f, 0.0f> �Դϴ�.
	 * 
	 * @return ������ �þ� ����� ��ȯ�մϴ�.
	 */
	inline Matrix4x4f CreateLookAt(const Vector3f& eyePosition, const Vector3f& focusPosition, const Vector3f& upDirection)
	{
		Vector3f f = Normalize(focusPosition - eyePosition);
		Vector3f s = Normalize(CrossProduct(f, upDirection));
		Vector3f u = CrossProduct(s, f);

		return Matrix4x4f(
			                        s.x,                         u.x,                       -f.x, 0.0f,
			                        s.y,                         u.y,                       -f.y, 0.0f,
			                        s.z,                         u.z,                       -f.z, 0.0f,
			-DotProduct(s, eyePosition), -DotProduct(u, eyePosition), DotProduct(f, eyePosition), 1.0f
		);
	}
}