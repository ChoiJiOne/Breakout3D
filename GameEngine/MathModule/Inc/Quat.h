#pragma once

#include "Vec3.h"


/**
 * @brief 쿼터니언입니다.
 */
struct Quat
{
	/**
	 * @brief 쿼터니언의 기본 생성자입니다.
	 * 
	 * @note 모든 원소의 값을 0으로 초기화합니다.
	 */
	Quat() noexcept : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}


	/**
	 * @brief 쿼터니언의 생성자입니다.
	 * 
	 * @param xx 쿼터니언의 x 성분입니다.
	 * @param yy 쿼터니언의 y 성분입니다.
	 * @param zz 쿼터니언의 z 성분입니다.
	 * @param ww 쿼터니언의 w 성분입니다.
	 */
	Quat(float&& xx, float&& yy, float&& zz, float&& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 쿼터니언의 생성자입니다.
	 *
	 * @param xx 쿼터니언의 x 성분입니다.
	 * @param yy 쿼터니언의 y 성분입니다.
	 * @param zz 쿼터니언의 z 성분입니다.
	 * @param ww 쿼터니언의 w 성분입니다.
	 */
	Quat(const float& xx, const float& yy, const float& zz, const float& ww) noexcept : x(xx), y(yy), z(zz), w(ww) {}


	/**
	 * @brief 쿼터니언의 생성자입니다.
	 *
	 * @param vv i,j,k 축의 벡터 요소입니다.
	 * @param ww 회전의 스케일을 조정하는 w 성분입니다.
	 */
	Quat(Vec3f&& vv, float&& ww) noexcept : v(vv), w(ww) {}


	/**
	 * @brief 쿼터니언의 생성자입니다.
	 * 
	 * @param vv i,j,k 축의 벡터 요소입니다.
	 * @param ww 회전의 스케일을 조정하는 w 성분입니다.
	 */
	Quat(const Vec3f& vv, const float& ww) noexcept : v(vv), w(ww) {}


	/**
	 * @brief 쿼터니언의 복사 생성자입니다.
	 * 
	 * @param q 원소를 복사할 쿼터니언 구조체의 인스턴스입니다.
	 */
	Quat(Quat&& q) noexcept  : x(q.x), y(q.y), z(q.z), w(q.w) {}


	/**
	 * @brief 쿼터니언의 복사 생성자입니다.
	 *
	 * @param q 원소를 복사할 쿼터니언 구조체의 인스턴스입니다.
	 */
	Quat(const Quat& q) noexcept : x(q.x), y(q.y), z(q.z), w(q.w) {}


	/**
	 * @brief 쿼터니언의 대입 연산자입니다.
	 * 
	 * @param q 원소를 복사할 쿼터니언 구조체의 인스턴스입니다.
	 * 
	 * @return 대입한 쿼터니언의 참조자를 반환합니다.
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
	 * @brief 쿼터니언의 대입 연산자입니다.
	 *
	 * @param q 원소를 복사할 쿼터니언 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 쿼터니언의 참조자를 반환합니다.
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
	 * @brief 쿼터니언에 -부호를 취합니다.
	 * 
	 * @return 쿼터니언에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Quat operator-() const
	{
		return Quat(-x, -y, -z, -w);
	}


	/**
	 * @brief 두 쿼터니언에 대응하는 원소를 더합니다.
	 * 
	 * @param q 쿼터니언의 덧셈을 수행할 피연산자입니다.
	 * 
	 * @return 두 쿼터니언에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Quat operator+(Quat&& q) const
	{
		return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
	}


	/**
	 * @brief 두 쿼터니언에 대응하는 원소를 더합니다.
	 *
	 * @param q 쿼터니언의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 쿼터니언에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Quat operator+(const Quat& q) const
	{
		return Quat(x + q.x, y + q.y, z + q.z, w + q.w);
	}


	/**
	 * @brief 두 쿼터니언에 대응하는 원소를 뺍니다.
	 *
	 * @param q 쿼터니언의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 쿼터니언에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Quat operator-(Quat&& q) const
	{
		return Quat(x - q.x, y - q.y, z - q.z, w - q.w);
	}


	/**
	 * @brief 두 쿼터니언에 대응하는 원소를 뺍니다.
	 *
	 * @param q 쿼터니언의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 쿼터니언에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Quat operator-(const Quat& q) const
	{
		return Quat(x - q.x, y - q.y, z - q.z, w - q.w);
	}


	/**
	 * @brief 쿼터니언의 스케일 연산을 수행합니다.
	 * 
	 * @param s 스케일 연산을 수행할 값입니다.
	 * 
	 * @return 스케일 연산을 수행한 결과를 반환합니다.
	 */
	Quat operator*(float s) const
	{
		return Quat(x * s, y * s, z * s, w * s);
	}


	/**
	 * @brief 두 쿼터니언에 대응하는 원소를 더합니다.
	 *
	 * @param q 쿼터니언의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 쿼터니언의 참조자를 반환합니다.
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
	 * @brief 두 쿼터니언에 대응하는 원소를 더합니다.
	 *
	 * @param q 쿼터니언의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 쿼터니언의 참조자를 반환합니다.
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
	 * @brief 두 쿼터니언에 대응하는 원소를 뺍니다.
	 *
	 * @param q 쿼터니언의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 쿼터니언의 참조자를 반환합니다.
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
	 * @brief 두 쿼터니언에 대응하는 원소를 뺍니다.
	 *
	 * @param q 쿼터니언의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 쿼터니언의 참조자를 반환합니다.
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
	 * @brief 쿼터니언의 스케일 연산을 수행합니다.
	 *
	 * @param s 스케일 연산을 수행할 값입니다.
	 *
	 * @return 연산을 수행한 쿼터니언의 참조자를 반환합니다.
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
	 * @brief 각도와 축을 이용해서 쿼터니언을 얻습니다.
	 *
	 * @parma axis 축 입니다.
	 * @param angle 육십분법 단위의 각도입니다.
	 */
	static inline Quat AxisAngle(const Vec3f& axis, float angle);


	/**
	 * @brief 각도와 축을 이용해서 쿼터니언을 얻습니다.
	 *
	 * @parma axis 축 입니다.
	 * @param radian 라디안 단위의 각도입니다.
	 */
	static inline Quat AxisRadian(const Vec3f& axis, float radian);


	/**
	 * @brief 쿼터니언의 축을 얻습니다.
	 * 
	 * @param q 축을 얻을 쿼터니언입니다.
	 * 
	 * @return 쿼터니언의 축을 반환합니다.
	 */
	static inline Vec3f Axis(const Quat& q);


	/**
	 * @brief 쿼터니언의 육십분법 각을 얻습니다.
	 *
	 * @param q 육십분법 각도를 얻을 쿼터니언입니다.
	 *
	 * @return 쿼터니언의 육십분법 각을 반환합니다.
	 */
	static inline float Angle(const Quat& q);


	/**
	 * @brief 쿼터니언의 라디안 각을 얻습니다.
	 * 
	 * @param q 라디안 각도를 얻을 쿼터니언입니다.
	 * 
	 * @return 쿼터니언의 라디안 각을 반환합니다.
	 */
	static inline float Radian(const Quat& q);


	/**
	 * @brief 두 쿼터니언의 내적 연산을 수행합니다.
	 * 
	 * @param lhs 쿼터니언의 내적 연산을 수행할 좌측 피연산자입니다.
	 * @param rhs 쿼터니언의 내적 연산을 수행할 우측 피연산자입니다.
	 *
	 * @return 내적 연산 결과를 반환합니다.
	 */
	static inline float Dot(const Quat& lhs, const Quat& rhs);


	/**
	 * @brief 쿼터니언의 크기 제곱 값을 계산합니다.
	 *
	 * @param q 크기 제곱을 계산할 쿼터니언입니다.
	 *
	 * @return 계산된 크기 제곱 값을 반환합니다.
	 */
	static inline float LengthSquare(const Quat& q);


	/**
	 * @brief 쿼터니언의 크기를 얻습니다.
	 *
	 * @param q 크기를 계산할 벡터입니다.
	 *
	 * @return 계산된 크기 값을 반환합니다.
	 */
	static inline float Length(const Quat& q);


	/**
	 * @brief 쿼터니언을 정규화합니다.
	 *
	 * @param q 정규화 할 쿼터니언입니다.
	 *
	 * @return 정규화된 쿼터니언을 반환합니다.
	 */
	static inline Quat Normalize(const Quat& q);


	/**
	 * @brief 켤레 쿼터니언을 얻습니다.
	 * 
	 * @param q 켤러 값을 계산할 쿼터니언입니다.
	 * 
	 * @return 켤레 쿼터니언을 반환합니다.
	 */
	static inline Quat Conjugate(const Quat& q);


	/**
	 * @brief 쿼터니언의 곱의 역원을 얻습니다.
	 * 
	 * @param 곱의 역원을 계산할 쿼터니언입니다.
	 * 
	 * @return 쿼터니언의 곱의 역원을 반환합니다.
	 */
	static inline Quat Inverse(const Quat& q);

	
	/**
	 * @brief 모든 원소가 0인 쿼터니언을 얻습니다.
	 * 
	 * @return 모든 원소가 0인 쿼터니언을 반환합니다.
	 */
	static inline Quat Zero();


	/**
	 * @brief w의 값이 1인 쿼터니언을 얻습니다.
	 * 
	 * @return w의 값이 1인 쿼터니언을 얻습니다.
	 */
	static inline Quat Identity();


	/**
	 * @brief 쿼터니언의 원소입니다.
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