#pragma once

#include <string>

#include "IResource.h"


/**
 * @brief 큐브맵 이미지 파일들을 로딩하고 OpenGL 파이프라인에 바인딩 가능한 큐브맵 리소스를 생성합니다.
 */
class Skybox : public IResource
{
public:
	/**
	 * @brief 스카이 박스의 디폴트 생성자입니다.
	 *
	 * @note 생성자 이외의 메서드에서 적절한 초기화를 수행해야 합니다.
	 */
	Skybox() = default;


	/**
	 * @brief 스카이 박스의 가상 소멸자입니다.
	 *
	 * @note 큐브맵 내부에서 할당된 요소를 해제하기 위해서는 반드시 Release를 호출해야 합니다.
	 */
	virtual ~Skybox();


	/**
	 * @brief 스카이 박스의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Skybox);


	/**
	 * @brief 큐브맵 이미지 파일을 읽고 스카이 맵 리소스를 생성합니다.
	 *
	 * @param rightPath 큐브맵 RIGHT(+X) 부분의 텍스처 리소스 경로입니다.
	 * @param leftPath 큐브맵 LEFT(-X) 부분의 텍스처 리소스 경로입니다.
	 * @param topPath 큐브맵 TOP(+Y) 부분의 텍스처 리소스 경로입니다.
	 * @param bottomPath 큐브맵 BOTTOM(-Y) 부분의 텍스처 리소스 경로입니다.
	 * @param frontPath 큐브맵 FRONT(+Z) 부분의 텍스처 리소스 경로입니다.
	 * @param backPath 큐브맵 BACK(-Z) 부분의 텍스처 리소스 경로입니다.
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
	 * @brief 스카이 박스 내부 리소스를 할당 해제합니다.
	 */
	virtual void Release() override;


	/**
	 * @brief 스카이 박스의 큐브맵을 활성화합니다.
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
	 * @brief 큐브맵 텍스처의 ID입니다.
	 */
	uint32_t cubeMapID_ = 0;
};