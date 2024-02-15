#pragma once

#include <string>

#include "IResource.h"


/**
 * @brief 이미지 파일을 로딩하고 OpenGL 파이프라인에 바인딩 가능한 텍스처 리소스를 생성 및 관리합니다.
 */
class Texture2D : public IResource
{
public:
	/**
	 * @brief 텍스처의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Texture2D() = default;


	/**
	 * @brief 텍스처의 가상 소멸자입니다.
	 *
	 * @note 텍스처 내부에서 할당된 요소를 해제하기 위해서는 반드시 Release를 호출해야 합니다.
	 */
	virtual ~Texture2D();


	/**
	 * @brief 텍스처의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Texture2D);


	/**
	 * @brief 이미지 파일을 읽고 텍스처 리소스를 생성합니다.
	 *
	 * @param path 이미지 파일의 경로입니다.
	 */
	void Initialize(const std::string& path);


	/**
	 * @brief 텍스처의 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 텍스처를 활성화합니다.
	 *
	 * @param unit 활성화 할 텍스처 유닛입니다.
	 */
	void Active(uint32_t unit) const;


private:
	/**
	 * @brief 파일로부터 픽셀 버퍼를 읽습니다.
	 * 
	 * @param path 픽셀 버퍼 파일(이미지 파일)의 경로입니다.
	 * @param outWidth 버퍼의 가로 크기입니다.
	 * @param outHeight 버퍼의 세로 크기입니다.
	 * @param outChannels 픽셀의 체널(1~4)입니다.
	 * @param outPixelBuffer 픽셀 버퍼입니다.
	 */
	void ReadPixelBufferFromFile(const std::string& path, int32_t& outWidth, int32_t& outHeight, int32_t& outChannels, std::vector<uint8_t>& outPixelBuffer);


private:
	/**
	 * @brief 텍스처 리소스의 ID입니다.
	 */
	uint32_t textureID_ = 0;
};