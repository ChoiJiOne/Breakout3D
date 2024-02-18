#pragma once

#include "MathModule.h"


/**
 * @brief ����(Vertex)�Դϴ�.
 */
class Vertex
{
public:
	/**
	 * @brief ����(Vertex)�� ����Ʈ �������Դϴ�.
	 */
	Vertex() noexcept
		: position_(0.0f, 0.0f, 0.0f)
		, normal_(0.0f, 0.0f, 0.0f)
		, uv_(0.0f, 0.0f) {}


	/**
	 * @brief ����(Vertex)�� �������Դϴ�.
	 * 
	 * @param position ������ ��ġ�Դϴ�.
	 * @param normal ������ ���� �����Դϴ�.
	 * @param uv ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	Vertex(Vec3f&& position, Vec3f&& normal, Vec2f&& uv) noexcept
		: position_(position)
		, normal_(normal)
		, uv_(uv) {}


	/**
	 * @brief ����(Vertex)�� �������Դϴ�.
	 *
	 * @param position ������ ��ġ�Դϴ�.
	 * @param normal ������ ���� �����Դϴ�.
	 * @param uv ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	Vertex(const Vec3f& position, const Vec3f& normal, const Vec2f& uv) noexcept
		: position_(position)
		, normal_(normal)
		, uv_(uv) {}


	/**
	 * @brief ����(Vertex)�� �������Դϴ�.
	 * 
	 * @param px ���� ��ġ�� X��ǥ�Դϴ�.
	 * @param py ���� ��ġ�� Y��ǥ�Դϴ�.
	 * @param pz ���� ��ġ�� Z��ǥ�Դϴ�.
	 * @param nx ���� ���� ������ X�����Դϴ�.
	 * @param ny ���� ���� ������ Y�����Դϴ�.
	 * @param nz ���� ���� ������ Z�����Դϴ�.
	 * @param u ���� �ؽ�ó ��ǥ�� U�����Դϴ�.
	 * @param v ���� �ؽ�ó ��ǥ�� V�����Դϴ�.
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
	 * @brief ����(Vertex)�� ���� �������Դϴ�.
	 * 
	 * @param instance ���縦 ������ ����(Vertex) �ν��Ͻ��Դϴ�.
	 */
	Vertex(Vertex&& instance) noexcept
		: position_(instance.position_)
		, normal_(instance.normal_)
		, uv_(instance.uv_) {}


	/**
	 * @brief ����(Vertex)�� ���� �������Դϴ�.
	 *
	 * @param instance ���縦 ������ ����(Vertex) �ν��Ͻ��Դϴ�.
	 */
	Vertex(const Vertex& instance) noexcept
		: position_(instance.position_)
		, normal_(instance.normal_)
		, uv_(instance.uv_) {}


	/**
	 * @brief ����(Vertex)�� ���� �������Դϴ�.
	 * 
	 * @param instance ���縦 ������ ����(Vertex) �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ����(Vertex)�� ���� �������Դϴ�.
	 *
	 * @param instance ���縦 ������ ����(Vertex) �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
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
	 * @brief ������ ��ġ�� ����ϴ�.
	 * 
	 * @return ������ ��ġ�� ��ȯ�մϴ�.
	 */
	Vec3f GetPosition() { return position_; }


	/**
	 * @brief ������ ��ġ�� ����ϴ�.
	 *
	 * @return ������ ��ġ�� ��ȯ�մϴ�.
	 */
	const Vec3f& GetPosition() const { return position_; }


	/**
	 * @brief ������ ���� ���͸� ����ϴ�.
	 * 
	 * @return ������ ���� ���͸� ��ȯ�մϴ�.
	 */
	Vec3f GetNormal() { return normal_; }


	/**
	 * @brief ������ ���� ���͸� ����ϴ�.
	 *
	 * @return ������ ���� ���͸� ��ȯ�մϴ�.
	 */
	const Vec3f& GetNormal() const { return normal_; }


	/**
	 * @brief ������ �ؽ�ó ��ǥ�� ����ϴ�.
	 * 
	 * @return ������ �ؽ�ó ��ǥ�� ��ȯ�մϴ�.
	 */
	Vec2f GetUV() { return uv_; }


	/**
	 * @brief ������ �ؽ�ó ��ǥ�� ����ϴ�.
	 *
	 * @return ������ �ؽ�ó ��ǥ�� ��ȯ�մϴ�.
	 */
	const Vec2f& GetUV() const { return uv_; }

	
	/**
	 * @brief ������ ��ġ ������ �����͸� ����ϴ�.
	 * 
	 * @return ������ ��ġ ������ �����͸� ��ȯ�մϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/offsetof-macro?view=msvc-170
	 */
	static void* GetOffsetOfPosition()
	{
		return (void*)(offsetof(Vertex, position_));
	}


	/**
	 * @brief ������ ���� ���� ������ �����͸� ����ϴ�.
	 * 
	 * @return ������ ���� ���� ������ �����͸� ��ȯ�մϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/offsetof-macro?view=msvc-170
	 */
	static void* GetOffsetOfNormal()
	{
		return (void*)(offsetof(Vertex, normal_));
	}


	/**
	 * @brief ������ �ؽ�ó ��ǥ ������ �����͸� ����ϴ�.
	 * 
	 * @return ������ �ؽ�ó ��ǥ ������ �����͸� ��ȯ�մϴ�.
	 * 
	 * @see https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/offsetof-macro?view=msvc-170
	 */
	static void* GetOffsetOfUV()
	{
		return (void*)(offsetof(Vertex, uv_));
	}


	/**
	 * @brief ������ ����Ʈ ���� ���� ����ϴ�.
	 *
	 * @return ������ ����Ʈ ����(Stride) ���� ��ȯ�մϴ�.
	 */
	static uint32_t GetStride()
	{
		return sizeof(Vertex);
	}


private:
	/**
	 * @brief ������ ��ġ�Դϴ�.
	 */
	Vec3f position_;


	/**
	 * @brief ������ ���� �����Դϴ�.
	 */
	Vec3f normal_;


	/**
	 * @brief ������ �ؽ�ó ��ǥ�Դϴ�.
	 */
	Vec2f uv_;
};