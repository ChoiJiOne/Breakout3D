#pragma once

#include "Shader.h"

class FrameBuffer; // 프레임 버퍼 리소스를 사용하기 위한 전방 선언입니다.


/**
 * @brief 후처리 효과를 적용하는 셰이더입니다.
 */
class PostEffectPass : public Shader
{
public:
	/**
	 * @brief 후처리 효과 셰이더의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	PostEffectPass() = default;


	/**
	 * @brief 후처리 효과 셰이더의 가상 소멸자입니다.
	 *
	 * @note 후처리 효과 셰이더의 내부에서 할당된 요소를 해제하기 위해서는 반드시 Release를 호출해야 합니다.
	 */
	virtual ~PostEffectPass();


	/**
	 * @brief 후처리 효과 셰이더의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(PostEffectPass);


	/**
	 * @brief 후처리 적용 수행하는 셰이더를 초기화합니다.
	 * 
	 * @param fsFile 프레그먼트 셰이더의 경로입니다.
	 */
	void Initialize(const std::string& fsPath);


	/**
	 * @brief 후처리 효과 셰이더의 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 후처리 효과를 적용한 뒤 바인딩된 프레임 버퍼에 전송합니다.
	 */
	void Blit();

	
private:
	/**
	 * @brief 정점 버퍼의 오브젝트입니다.
	 */
	uint32_t vertexBufferObject_ = 0;


	/**
	 * @brief 정점 버퍼 목록의 오브젝트입니다.
	 */
	uint32_t vertexArrayObject_ = 0;
};