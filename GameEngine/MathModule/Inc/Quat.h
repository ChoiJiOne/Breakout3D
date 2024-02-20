#pragma once

#include "Vec3.h"


/**
 * @brief ���ʹϾ��Դϴ�.
 */
struct Quat
{
	/**
	 * @brief ���ʹϾ��� �⺻ �������Դϴ�.
	 * 
	 * @note ��� ������ ���� 0���� �ʱ�ȭ�մϴ�.
	 */
	Quat() noexcept : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 * 
	 * @param xx ���ʹϾ��� x �����Դϴ�.
	 * @param yy ���ʹϾ��� y �����Դϴ�.
	 * @param zz ���ʹϾ��� z �����Դϴ�.
	 * @param ww ���ʹϾ��� w �����Դϴ�.
	 */
	Quat(float&& xx, float&& yy, float&& zz, float&& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 *
	 * @param xx ���ʹϾ��� x �����Դϴ�.
	 * @param yy ���ʹϾ��� y �����Դϴ�.
	 * @param zz ���ʹϾ��� z �����Դϴ�.
	 * @param ww ���ʹϾ��� w �����Դϴ�.
	 */
	Quat(const float& xx, const float& yy, const float& zz, const float& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 *
	 * @param vv i,j,k ���� ���� ����Դϴ�.
	 * @param ww ȸ���� �������� �����ϴ� w �����Դϴ�.
	 */
	Quat(Vec3f&& vv, float&& ww) noexcept : v(vv), w(ww) {}


	/**
	 * @brief ���ʹϾ��� �������Դϴ�.
	 * 
	 * @param vv i,j,k ���� ���� ����Դϴ�.
	 * @param ww ȸ���� �������� �����ϴ� w �����Դϴ�.
	 */
	Quat(const Vec3f& vv, const float& ww) noexcept : v(vv), w(ww) {}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 * 
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Quat(Quat&& q) noexcept  : x(q.x), y(q.y), z(q.z), w(q.w) {}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 *
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 */
	Quat(const Quat& q) noexcept : x(q.x), y(q.y), z(q.z), w(q.w) {}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 * 
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator=(Quat&& q) noexcept
	{
		if (this == &q) return *this;

		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;

		return *this;
	}


	/**
	 * @brief ���ʹϾ��� ���� �������Դϴ�.
	 *
	 * @param q ���Ҹ� ������ ���ʹϾ� ����ü�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator=(const Quat& q) noexcept
	{
		if (this == &q) return *this;

		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;

		return *this;
	}


	/**
	 * @brief ���ʹϾ� -��ȣ�� ���մϴ�.
	 * 
	 * @return ���ʹϾ� -��ȣ�� ���� ���ο� ���͸� ��ȯ�մϴ�.
	 */
	Quat operator-() const
	{
		return Quat(-x, -y, -z, -w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 * 
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 * 
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Quat operator+(Quat&& q) const
	{
		return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� ���� ����� ��ȯ�մϴ�.
	 */
	Quat operator+(const Quat& q) const
	{
		return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Quat operator-(Quat&& q) const
	{
		return Quat(x - q.x, y - q.y, z - q.z, w - q.w);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return �� ���ʹϾ� �����ϴ� ���Ҹ� �� ����� ��ȯ�մϴ�.
	 */
	Quat operator-(const Quat& q) const
	{
		return Quat(x - q.x, y - q.y, z - q.z, w - q.w);
	}


	/**
	 * @brief ���ʹϾ��� ������ ������ �����մϴ�.
	 * 
	 * @param s ������ ������ ������ ���Դϴ�.
	 * 
	 * @return ������ ������ ������ ����� ��ȯ�մϴ�.
	 */
	Quat operator*(float s) const
	{
		return Quat(x * s, y * s, z * s, w * s);
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator+=(Quat&& q) noexcept
	{
		x += q.x;
		y += q.y;
		z += q.z;
		w += q.w;

		return *this;
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���մϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator+=(const Quat& q) noexcept
	{
		x += q.x;
		y += q.y;
		z += q.z;
		w += q.w;

		return *this;
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator-=(Quat&& q) noexcept
	{
		x -= q.x;
		y -= q.y;
		z -= q.z;
		w -= q.w;

		return *this;
	}


	/**
	 * @brief �� ���ʹϾ� �����ϴ� ���Ҹ� ���ϴ�.
	 *
	 * @param q ���ʹϾ��� ������ ������ �ǿ������Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator-=(const Quat& q) noexcept
	{
		x -= q.x;
		y -= q.y;
		z -= q.z;
		w -= q.w;

		return *this;
	}


	/**
	 * @brief ���ʹϾ��� ������ ������ �����մϴ�.
	 *
	 * @param s ������ ������ ������ ���Դϴ�.
	 *
	 * @return ������ ������ ���ʹϾ��� �����ڸ� ��ȯ�մϴ�.
	 */
	Quat& operator*=(float s) noexcept
	{
		x *= s;
		y *= s;
		z *= s;
		w *= s;

		return *this;
	}


	/**
	 * @brief ������ ���� �̿��ؼ� ���ʹϾ��� ����ϴ�.
	 *
	 * @parma axis �� �Դϴ�.
	 * @param angle ���ʺй� ������ �����Դϴ�.
	 */
	static inline Quat AxisAngle(const Vec3f& axis, float angle);


	/**
	 * @brief ������ ���� �̿��ؼ� ���ʹϾ��� ����ϴ�.
	 *
	 * @parma axis �� �Դϴ�.
	 * @param radian ���� ������ �����Դϴ�.
	 */
	static inline Quat AxisRadian(const Vec3f& axis, float radian);

	
	/**
	 * @brief ��� ���Ұ� 0�� ���ʹϾ��� ����ϴ�.
	 * 
	 * @return ��� ���Ұ� 0�� ���ʹϾ��� ��ȯ�մϴ�.
	 */
	static inline Quat Zero();


	/**
	 * @brief w�� ���� 1�� ���ʹϾ��� ����ϴ�.
	 * 
	 * @return w�� ���� 1�� ���ʹϾ��� ����ϴ�.
	 */
	static inline Quat Identity();


	/**
	 * @brief ���ʹϾ��� �����Դϴ�.
	 */
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		struct
		{
			Vec3f v; // (x, y, z)
			float w;
		};
		float data[4];
	};
};


#include "Quat.inl"