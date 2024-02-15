#pragma once

#include <map>
#include <string>

#include "IResource.h"


/**
 * @brief GLSL ���̴��� �������ϰ� ���̴� ���α׷��� �����մϴ�.
 */
class Shader : public IResource
{
public:
	/**
	 * @brief ���̴��� ����Ʈ �������Դϴ�.
	 */
	Shader() = default;


	/**
	 * @brief ���̴��� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Shader();


	/**
	 * @brief ���̴��� ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader);


	/**
	 * @brief ���̴� ������ �о� ���̴� ���α׷��� �����մϴ�.
	 *
	 * @param vsPath ���ؽ� ���̴�(Vertex Shader)�� ����Դϴ�.
	 * @param fsPath �����׸�Ʈ ���̴�(Fragment Shader)�� ����Դϴ�.
	 */
	virtual void Initialize(const std::string& vsPath, const std::string& fsPath);


	/**
	 * @brief ���̴� ������ �о� ���̴� ���α׷��� �����մϴ�.
	 *
	 * @param vsPath ���ؽ� ���̴�(Vertex Shader)�� ����Դϴ�.
	 * @param gsFile ������Ʈ�� ���̴��� Ȯ����(.geom)�� ������ ����Դϴ�.
	 * @param fsPath �����׸�Ʈ ���̴�(Fragment Shader)�� ����Դϴ�.
	 */
	virtual void Initialize(const std::string& vsPath, const std::string& gsPath, const std::string& fsPath);


	/**
	 * @brief ���̴� ���ο��� �Ҵ�� ���ҽ��� �Ҵ��� �����մϴ�.
	 */
	virtual void Release() override;


	/**
	 * @brief ���̴��� ���������ο� ���ε��մϴ�.
	 */
	void Bind();


	/**
	 * @brief ���̴��� ���ε� �����մϴ�.
	 */
	void Unbind();
	

protected:
	/**
	 * @brief ���̴��� �����Դϴ�.
	 */
	enum class EType : int32_t
	{
		Vertex   = 0x00,
		Geometry = 0x01,
		Fragment = 0x02,
	};


	/**
	 * @brief ���̴� �� ������ ��ü�� ��ġ�� ����ϴ�.
	 *
	 * @param name ��ġ�� ã�� ���̴� �� ������ �̸��Դϴ�.
	 *
	 * @return ���̴� �� ������ ��ü�� ��ġ�� ��ȯ�մϴ�. ã�� ���ϸ� -1�� ��ȯ�մϴ�.
	 *
	 * @see https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml
	 */
	int32_t GetUniformLocation(const std::string& name);


	/**
	 * @brief ���̴� ������ �а� ������ ������ �ҽ��� ����ϴ�.
	 *
	 * @param path ���̴� ������ ����Դϴ�.
	 *
	 * @return ���̴� �ҽ� �ڵ��� ���ڿ��� ��ȯ�մϴ�. �����ϸ� �� ���ڿ��� ��ȯ�մϴ�.
	 */
	std::string ReadShaderFile(const std::string& path);


	/**
	 * @brief ���̴� ��ü�� �����ϰ� ���̴� �ҽ��� �������մϴ�.
	 *
	 * @note ���̴� ��ü ������ �����ϸ� 0�� �ƴ� ���� ��ȯ�մϴ�.
	 *
	 * @param type ���̴� Ÿ���Դϴ�.
	 * @param source ���̴� �ҽ��Դϴ�.
	 *
	 * @return �����ϵ� ���̴� ��ü�� ���̵� ��ȯ�մϴ�.
	 */
	uint32_t CreateAndCompileShader(const EType& type, const std::string& source);


protected:
	/**
	 * @brief ���̴� ���α׷��� ���̵��Դϴ�.
	 */
	uint32_t programID_ = 0;


	/**
	 * @brief ������ ������ ��ġ���Դϴ�.
	 */
	std::map<std::string, uint32_t> uniformLocationCache_;
};