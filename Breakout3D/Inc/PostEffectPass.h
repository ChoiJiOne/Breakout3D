#pragma once

#include "Shader.h"

class FrameBuffer; // ������ ���� ���ҽ��� ����ϱ� ���� ���� �����Դϴ�.


/**
 * @brief ��ó�� ȿ���� �����ϴ� ���̴��Դϴ�.
 */
class PostEffectShader : public Shader
{
public:
	/**
	 * @brief ��ó�� ȿ�� ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	PostEffectShader() = default;


	/**
	 * @brief ��ó�� ȿ�� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ��ó�� ȿ�� ���̴��� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~PostEffectShader();


	/**
	 * @brief ��ó�� ȿ�� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PostEffectShader);


	/**
	 * @brief ��ó�� ���� �����ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 * 
	 * @param fsFile �����׸�Ʈ ���̴��� ����Դϴ�.
	 */
	void Initialize(const std::string& fsPath);


	/**
	 * @brief ��ó�� ȿ�� ���̴��� ���� ���ҽ��� �Ҵ� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ��ó�� ȿ���� ������ �� ���ε��� ������ ���ۿ� �����մϴ�.
	 *
	 * @param framebuffer ��ó�� ȿ���� ������ ������ �����Դϴ�.
	 */
	void Blit(FrameBuffer* framebuffer);

	
private:
	/**
	 * @brief ���� ������ ������Ʈ�Դϴ�.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief ���� ���� ����� ������Ʈ�Դϴ�.
	 */
	uint32_t vertexArrayObject_ = 0;
};