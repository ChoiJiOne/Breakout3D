#pragma once

#include <cstdint>
#include <vector>

#include "IResource.h"


/**
 * @brief ���������� ���� �� ������ ������ ������ �����Դϴ�.
 */
class FrameBuffer : public IResource
{
public:
	/**
	 * @brief ������ ������ ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	FrameBuffer() = default;


	/**
	 * @brief ������ ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~FrameBuffer();


	/**
	 * @brief ������ ������ ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(FrameBuffer);


	/**
	 * @brief ������ ���۸� �����մϴ�.
	 *
	 * @param bufferWidth ������ ������ ���� ũ���Դϴ�.
	 * @param bufferHeight ������ ������ ���� ũ���Դϴ�.
	 * @param countColorBuffer ������ ������ ���� ���� ���Դϴ�.
	 * @param bIsEnableDeptnStencilBuffer ������ ���ۿ� ���� ���ٽ� ���۸� ����� �� �����Դϴ�.
	 */
	void Initialize(int32_t bufferWidth, int32_t bufferHeight, uint32_t countColorBuffer, bool bIsEnableDeptnStencilBuffer);


	/**
	 * @brief ������ ���� ������ ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ������ ���۸� �ʱ�ȭ�մϴ�.
	 *
	 * @param red ���� ������ R ���Դϴ�.
	 * @param green ���� ������ G ���Դϴ�.
	 * @param blue ���� ������ B ���Դϴ�.
	 * @param alpha ���� ������ A ���Դϴ�.
	 * @param depth ���� ������ �ʱ�ȭ ���Դϴ�.
	 * @param stencil ���ٽ� ������ �ʱ�ȭ ���Դϴ�.
	 */
	void Clear(float red, float green, float blue, float alpha, float depth = 1.0f, uint8_t stencil = 0);


	/**
	 * @brief ������ ���۸� ���ε��մϴ�.
	 */
	void Bind();


	/**
	 * @brief ������ ������ ���ε��� �����մϴ�.
	 */
	void Unbind();


	/**
	 * @brief ������ ������ �÷� ���� �ؽ�ó�� Ȱ��ȭ�մϴ�.
	 *
	 * @param index Ȱ��ȭ �� �÷� ������ �ε����Դϴ�.
	 * @param unit Ȱ��ȭ �� �ؽ�ó �����Դϴ�.
	 */
	void Active(uint32_t inedx, uint32_t unit);


private:
	/**
	 * @brief ������ ������ �ִ� �÷� ���� ���Դϴ�.
	 */
	static const uint32_t MAX_COLOR_BUFFER = 2;

	
private:
	/**
	 * @brief ���ε� �Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsBind_ = false;


	/**
	 * @brief ���� ���ٽ� ���۰� Ȱ��ȭ�Ǿ����� Ȯ���մϴ�.
	 */
	bool bIsEnableDeptnStencilBuffer_ = false;
	

	/**
	 * @brief ������ ���� ������Ʈ�� ID�Դϴ�.
	 */
	uint32_t framebufferID_ = 0;


	/**
	 * @brief �÷� ���� ������Ʈ�� ID�Դϴ�.
	 */
	std::vector<uint32_t> colorBufferID_;


	/**
	 * @brief ���� ���ٽ� ���� ������Ʈ�� ID�Դϴ�.
	 */
	uint32_t depthStencilBufferID_ = 0;
};