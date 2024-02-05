#pragma once

#include <string>
#include <windows.h>


/**
 * @brief 윈도우 프로시저입니다.
 */
typedef LRESULT(CALLBACK* WINDOWPROC)(HWND, uint32_t, WPARAM, LPARAM);


/**
 * @brief 윈도우 클래스에 대한 확장 기능을 제공합니다.
 */
namespace WindowClassUtils
{
	/**
	 * @brief 윈도우 클래스를 등록합니다.
	 *
	 * @note 이 정적 메서드는 한 번만 호출할 수 있습니다.
	 *
	 * @param className 등록할 윈도우 클래스의 이름입니다.
	 * @param windowProc 등록할 윈도우 클래스의 프로시저입니다.
	 */
	void RegisterWindowClass(const std::wstring& className, WINDOWPROC windowProc);


	/**
	 * @brief 윈도우 클래스를 등록 해제합니다.
	 */
	void UnregisterWindowClass();


	/**
	 * @brief 윈도우 클래스의 이름을 얻습니다.
	 * 
	 * @return 윈도우 클래스의 이름 문자열 포인터를 반환합니다.
	 */
	const wchar_t* GetWindowClassName();


	/**
	 * @brief 윈도우 클래스의 인스턴스를 얻습니다.
	 * 
	 * @return 윈도우 클래스의 인스턴스 핸들값을 반환합니다.
	 */
	HINSTANCE GetWindowClassInstance();
}