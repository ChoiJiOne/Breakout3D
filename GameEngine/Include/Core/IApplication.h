#pragma once

#include "Core/AudioManager.h"
#include "Core/GameTimer.h"
#include "Core/IManager.h"
#include "Core/InputManager.h"
#include "Core/ObjectManager.h"
#include "Core/RenderManager.h"
#include "Core/ResourceManager.h"
#include "Core/Vertex.h"
#include "Core/Window.h"

#include "Macro/Assertion.h"
#include "Macro/GLAssertion.h"
#include "Macro/Macro.h"
#include "Macro/WindowsAssertion.h"

#include "Matrix/Matrix2x2.h"
#include "Matrix/Matrix3x3.h"
#include "Matrix/Matrix4x4.h"

#include "Object/Camera3D.h"
#include "Object/IObject.h"

#include "Resource/IResource.h"
#include "Resource/Sound.h"
#include "Resource/TTFont.h"

#include "Shader/Shader.h"

#include "Utils/CommandLineUtils.h"
#include "Utils/ErrorUtils.h"
#include "Utils/FileUtils.h"
#include "Utils/GeometryGenerateUtils.h"
#include "Utils/MathUtils.h"
#include "Utils/StringUtils.h"
#include "Utils/WindowClassUtils.h"
#include "Utils/WindowsCrashUtils.h"


/**
 * @brief 애플리케이션 인터페이스입니다.
 *
 * @note 애플리케이션을 초기화 및 실행하는 클래스는 반드시 이 클래스를 상속받아야 합니다.
 */
class IApplication
{
public:
	/**
	 * @brief 애플리케이션 인터페이스의 생성자입니다.
	 */
	IApplication();


	/**
	 * @brief 애플리케이션 인터페이스의 가상 소멸자입니다.
	 */
	virtual ~IApplication();


	/**
	 * @brief 애플리케이션 인터페이스의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(IApplication);


	/**
	 * @brief 애플리케이션 인터페이스를 초기화합니다.
	 *
	 * @note 하위 클래스에서는 초기화 전에 이 메서드를 반드시 호출해야 합니다.
	 */
	virtual void Setup();


	/**
	 * @brief 애플리케이션 인터페이스의 사용을 종료합니다.
	 */
	virtual void Shutdown();


	/**
	 * @brief 애플리케이션을 실행합니다.
	 */
	virtual void Run() = 0;


	/**
	 * @brief 애플리케이션의 루트 경로를 얻습니다.
	 *
	 * @return 애플리케이션의 루트 경로를 반환합니다.
	 */
	static const std::wstring& GetRootPath() { return rootPath_; }


	/**
	 * @brief 애플리케이션의 엔진 경로를 얻습니다.
	 *
	 * @return 애플리케이션의 엔진 경로를 반환합니다.
	 */
	static const std::wstring& GetEnginePath() { return enginePath_; }


protected:
	/**
	 * @brief 애플리케이션의 속성을 설정합니다.
	 *
	 * @param windowTitle 애플리케이션의 윈도우 타이틀입니다.
	 * @param windowPosX 애플리케이션의 화면 상 윈도우의 X 위치입니다.
	 * @param windowPosY 애플리케이션의 화면 상 윈도우의 X 위치입니다.
	 * @param windowWidth 애플리케이션의 윈도우 가로 크기입니다.
	 * @param windowHeight 애플리케이션의 윈도우 세로 크기입니다.
	 * @param bIsResize 애플리케이션의 윈도우 크기 변경 여부입니다.
	 * @param bIsFullscreen 애플리케이션의 윈도우 풀 스크린 여부입니다.
	 * @param bIsVsync 애플리케이션의 수직 동기화 여부입니다.
	 * @param bIsImGui ImGui 라이브러리 사용 여부입니다.
	 */
	void SetProperties(
		const std::wstring& windowTitle,
		int32_t windowPosX,
		int32_t windowPosY,
		int32_t windowWidth,
		int32_t windowHeight,
		bool bIsResize,
		bool bIsFullscreen,
		bool bIsVsync,
		bool bIsImGui
	);


	/**
	 * @brief 기본 윈도우 이벤트를 추가합니다.
	 */
	void AddDefaultWindowEvents();


protected:
	/**
	 * @brief 게임 프레임워크를 초기화했는지 확인합니다.
	 */
	bool bIsSetup_ = false;


	/**
	 * @brief 속성 설정에 성공했는지 확인합니다.
	 */
	bool bIsPropertiesSet_ = false;


	/**
	 * @brief 개발 모드인지 확인합니다.
	 */
	bool bIsDevMode_ = false;


	/**
	 * @brief 애플리케이션 윈도우 타이틀입니다.
	 */
	std::wstring windowTitle_;


	/**
	 * @brief 애플리케이션의 화면 상 (x, y) 좌표입니다.
	 */
	Vector2i windowPosition_;


	/**
	 * @brief 애플리케이션의 화면 상의 가로 크기입니다.
	 */
	int32_t windowWidth_ = 0;


	/**
	 * @brief 애플리케이션의 화면 상의 세로 크기입니다.
	 */
	int32_t windowHeight_ = 0;


	/**
	 * @brief 애플리케이션의 윈도우 크기 변경 여부입니다.
	 */
	bool bIsResize_ = false;


	/**
	 * @brief 애플리케이션의 윈도우 풀 스크린 여부입니다.
	 */
	bool bIsFullscreen_ = false;


	/**
	 * @brief 애플리케이션의 수직 동기화 여부입니다.
	 */
	bool bIsVsync_ = true;


	/**
	 * @brief ImGui 라이브러리 사용 여부입니다.
	 */
	bool bIsImGui_ = false;


	/**
	 * @brief 게임 루프 종료가 감지되었는지 확인합니다.
	 */
	bool bIsDoneLoop_ = false;


	/**
	 * @brief 루트 경로입니다.
	 */
	static std::wstring rootPath_;


	/**
	 * @brief 게임 엔진 경로입니다.
	 */
	static std::wstring enginePath_;


	/**
	 * @brief 게임 윈도우입니다.
	 */
	std::unique_ptr<Window> window_ = nullptr;
};