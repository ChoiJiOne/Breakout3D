#pragma once

#include <string>

#include "IResource.h"


/**
 * @brief �̹��� ������ �ε��ϰ� OpenGL ���������ο� ���ε� ������ �ؽ�ó ���ҽ��� ���� �� �����մϴ�.
 */
class Texture2D : public IResource
{
public:
	/**
	 * @brief �ؽ�ó�� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	Texture2D() = default;


	/**
	 * @brief �ؽ�ó�� ���� �Ҹ����Դϴ�.
	 *
	 * @note �ؽ�ó ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~Texture2D();


	/**
	 * @brief �ؽ�ó�� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Texture2D);


	/**
	 * @brief �̹��� ������ �а� �ؽ�ó ���ҽ��� �����մϴ�.
	 *
	 * @param path �̹��� ������ ����Դϴ�.
	 */
	void Initialize(const std::string& path);


	/**
	 * @brief �ؽ�ó�� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief �ؽ�ó�� Ȱ��ȭ�մϴ�.
	 *
	 * @param unit Ȱ��ȭ �� �ؽ�ó �����Դϴ�.
	 */
	void Active(uint32_t unit) const;


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
	 * @brief �ؽ�ó ���ҽ��� ID�Դϴ�.
	 */
	uint32_t textureID_ = 0;
};