#pragma once

#include <string>

#include "IResource.h"


/**
 * @brief ť��� �̹��� ���ϵ��� �ε��ϰ� OpenGL ���������ο� ���ε� ������ ť��� ���ҽ��� �����մϴ�.
 */
class Skybox : public IResource
{
public:
	/**
	 * @brief ��ī�� �ڽ��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Skybox() = default;


	/**
	 * @brief ��ī�� �ڽ��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ť��� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~Skybox();


	/**
	 * @brief ��ī�� �ڽ��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Skybox);


	/**
	 * @brief ť��� �̹��� ������ �а� ��ī�� �� ���ҽ��� �����մϴ�.
	 *
	 * @param rightPath ť��� RIGHT(+X) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param leftPath ť��� LEFT(-X) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param topPath ť��� TOP(+Y) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param bottomPath ť��� BOTTOM(-Y) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param frontPath ť��� FRONT(+Z) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 * @param backPath ť��� BACK(-Z) �κ��� �ؽ�ó ���ҽ� ����Դϴ�.
	 */
	void Initialize(
		const std::string& rightPath,
		const std::string& leftPath,
		const std::string& topPath,
		const std::string& bottomPath,
		const std::string& frontPath,
		const std::string& backPath
	);


	/**
	 * @brief ��ī�� �ڽ� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ��ī�� �ڽ��� ť����� Ȱ��ȭ�մϴ�.
	 *
	 * @param unit Ȱ��ȭ �� �ؽ�ó �����Դϴ�.
	 */
	void Active(uint32_t unit) const;


	/**
	 * @brief ��ī�� �ڽ��� ���� ���� ������Ʈ�� ����ϴ�.
	 *
	 * @return ��ī�� �ڽ��� ���� ���� ������Ʈ�� ID�� ��ȯ�մϴ�.
	 */
	uint32_t GetVertexArrayObject() const { return vertexArrayObject_; }


	/**
	 * @brief ��ī�� �ڽ��� ���� ������ ���� ����ϴ�.
	 *
	 * @return ��ī�� �ڽ��� ���� ������ ���� ��ȯ�մϴ�.
	 */
	uint32_t GetVertexCount() const { return vertexCount_; }


private:
	/**
	 * @brief ���Ϸκ��� �ȼ� ���۸� �н��ϴ�.
	 *
	 * @param path �ȼ� ���� ����(�̹��� ����)�� ����Դϴ�.
	 * @param outWidth ������ ���� ũ���Դϴ�.
	 * @param outHeight ������ ���� ũ���Դϴ�.
	 * @param outChannels �ȼ��� ü��(1~4)�Դϴ�.
	 * @param outPixelBuffer �ȼ� �����Դϴ�.
	 */
	void ReadPixelBufferFromFile(const std::string& path, int32_t& outWidth, int32_t& outHeight, int32_t& outChannels, std::vector<uint8_t>& outPixelBuffer);


private:
	/**
	 * @brief ť��� �ؽ�ó�� ID�Դϴ�.
	 */
	uint32_t cubeMapID_ = 0;


	/**
	 * @brief ��ī�� �ڽ��� ���� ����� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;


	/**
	 * @brief ��ī�� �ڽ��� ���� ���� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief ��ī�� �ڽ� ������ ���Դϴ�.
	 */
	uint32_t vertexCount_ = 0;
};