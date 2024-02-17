#pragma once

#include "Shader.h"

class Skybox; //��ī�� �ڽ� ���ҽ� ����� ���� ���漱���Դϴ�.


/**
 * @brief ��ī�� �ڽ� �������� �����մϴ�.
 */
class SkyboxPass : public Shader
{
public:
	/**
	 * @brief ��ī�� �ڽ� �������� �����ϴ� ���̴��� ����Ʈ �������Դϴ�.
	 */
	SkyboxPass() = default;


	/**
	 * @brief ��ī�� �ڽ� �������� �����ϴ� ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~SkyboxPass();


	/**
	 * @brief ��ī�� �ڽ� �������� �����ϴ� ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(SkyboxPass);


	/**
	 * @brief ��ī�� �ڽ� �������� �����ϴ� ���̴��� �ʱ�ȭ�մϴ�.
	 */
	void Initialize();


	/**
	 * @brief ���̴� ���ο��� �Ҵ�� ���ҽ��� �Ҵ��� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ��ī�� �ڽ� �׸��⸦ �����մϴ�.
	 * 
	 * @param view ���ε��� ������ ���ۿ� �׸� �� ������ �þ� ����Դϴ�.
	 * @param projection ���ε��� ������ ���ۿ� �׸� �� ������ ���� ����Դϴ�.
	 * @param skybox ���ε��� ������ ���ۿ� �׸� ��ī�� �ڽ��Դϴ�.
	 */
	void Draw(const Matrix4x4f& view, const Matrix4x4f& projection, const Skybox* skybox);


private:
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