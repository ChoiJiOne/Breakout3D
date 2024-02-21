#pragma once

#include "Shader.h"

class FrameBuffer; // ������ ���� ���ҽ��� ����ϱ� ���� ���� �����Դϴ�.


/**
 * @brief ��ó�� ȿ���� �����ϴ� ���̴��Դϴ�.
 */
class PostEffectPass : public Shader
{
public:
	/**
	 * @brief ��ó�� ȿ�� ���̴��� ����Ʈ �������Դϴ�.
	 *
	 * @note ������ �̿��� �޼��忡�� ������ �ʱ�ȭ�� �����ؾ� �մϴ�.
	 */
	PostEffectPass() = default;


	/**
	 * @brief ��ó�� ȿ�� ���̴��� ���� �Ҹ����Դϴ�.
	 *
	 * @note ��ó�� ȿ�� ���̴��� ���ο��� �Ҵ�� ��Ҹ� �����ϱ� ���ؼ��� �ݵ�� Release�� ȣ���ؾ� �մϴ�.
	 */
	virtual ~PostEffectPass();


	/**
	 * @brief ��ó�� ȿ�� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(PostEffectPass);


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
	 */
	void Blit();

	
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