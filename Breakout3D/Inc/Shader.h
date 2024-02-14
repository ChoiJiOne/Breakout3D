#pragma once

#include <map>
#include <string>

#include "Macro.h"


/**
 * @brief GLSL 셰이더를 컴파일하고 셰이더 프로그램을 관리합니다.
 */
class Shader
{
public:
	/**
	 * @brief 셰이더의 디폴트 생성자입니다.
	 */
	Shader() = default;


	/**
	 * @brief 셰이더의 가상 소멸자입니다.
	 */
	virtual ~Shader();


	/**
	 * @brief 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Shader);


	/**
	 * @brief 셰이더 파일을 읽어 셰이더 프로그램을 생성합니다.
	 *
	 * @param vsPath 버텍스 셰이더(Vertex Shader)의 경로입니다.
	 * @param fsPath 프레그먼트 셰이더(Fragment Shader)의 경로입니다.
	 */
	void Initialize(const std::string& vsPath, const std::string& fsPath);


	/**
	 * @brief 셰이더 파일을 읽어 셰이더 프로그램을 생성합니다.
	 *
	 * @param vsPath 버텍스 셰이더(Vertex Shader)의 경로입니다.
	 * @param gsFile 지오메트리 셰이더의 확장자(.geom)를 포함한 경로입니다.
	 * @param fsPath 프레그먼트 셰이더(Fragment Shader)의 경로입니다.
	 */
	void Initialize(const std::string& vsPath, const std::string& gsPath, const std::string& fsPath);


	/**
	 * @brief 셰이더 내부에서 할당된 리소스의 할당을 해제합니다.
	 */
	virtual void Release();


	/**
	 * @brief 셰이더를 파이프라인에 바인딩합니다.
	 */
	void Bind();


	/**
	 * @brief 셰이더를 바인딩 해제합니다.
	 */
	void Unbind();


	/**
	 * @brief 셰이더가 초기화된 적이 있는지 확인합니다.
	 *
	 * @return 셰이더가 초기화된 적이 있다면 true, 그렇지 않으면 false를 반환합니다.
	 */
	bool IsInitialized() const { return bIsInitialized_; }


protected:
	/**
	 * @brief 셰이더의 종류입니다.
	 */
	enum class EType : int32_t
	{
		Vertex   = 0x00,
		Geometry = 0x01,
		Fragment = 0x02,
	};


	/**
	 * @brief 셰이더 내 유니폼 객체의 위치를 얻습니다.
	 *
	 * @param name 위치를 찾을 셰이더 내 유니폼 이름입니다.
	 *
	 * @return 셰이더 내 유니폼 객체의 위치를 반환합니다. 찾지 못하면 -1을 반환합니다.
	 *
	 * @see https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml
	 */
	int32_t GetUniformLocation(const std::string& name);


	/**
	 * @brief 셰이더 파일을 읽고 컴파일 가능한 소스를 얻습니다.
	 *
	 * @param path 셰이더 파일의 경로입니다.
	 *
	 * @return 셰이더 소스 코드의 문자열을 반환합니다. 실패하면 빈 문자열을 반환합니다.
	 */
	std::string ReadShaderFile(const std::string& path);


	/**
	 * @brief 셰이더 객체를 생성하고 셰이더 소스를 컴파일합니다.
	 *
	 * @note 셰이더 객체 생성에 성공하면 0이 아닌 값을 반환합니다.
	 *
	 * @param type 셰이더 타입입니다.
	 * @param source 셰이더 소스입니다.
	 *
	 * @return 컴파일된 셰이더 객체의 아이디를 반환합니다.
	 */
	uint32_t CreateAndCompileShader(const EType& type, const std::string& source);


protected:
	/**
	 * @brief 셰이더가 초기화되었는지 확인합니다.
	 */
	bool bIsInitialized_ = false;


	/**
	 * @brief 셰이더 프로그램의 아이디입니다.
	 */
	uint32_t programID_ = 0;


	/**
	 * @brief 유니폼 버퍼의 위치값입니다.
	 */
	std::map<std::string, uint32_t> uniformLocationCache_;
};