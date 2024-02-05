#pragma once

#include <string>
#include <windows.h>


/**
 * @brief 에러에 대한 확장 기능을 제공합니다.
 */
namespace ErrorUtils
{
	/**
	 * @brief 디버그 창에 형식화된 문자열을 출력합니다.
	 *
	 * @param format 형식 문자열입니다.
	 * @param .. 문자열 내의 형식에 대응하는 가변인자입니다.
	 *
	 * @note
	 * - Debug와 Release모드에서만 디버그 창에 문자열이 출력됩니다.
	 * - Shipping 모드에서는 디버그 창에 문자열이 출력되지 않습니다.
	 */
	void DebugPrintF(const char* format, ...);


	/**
	 * @brief 디버그 창에 형식화된 문자열을 출력합니다.
	 *
	 * @param format 형식 문자열입니다.
	 * @param .. 문자열 내의 형식에 대응하는 가변인자입니다.
	 *
	 * @note
	 * - Debug와 Release모드에서만 디버그 창에 문자열이 출력됩니다.
	 * - Shipping 모드에서는 디버그 창에 문자열이 출력되지 않습니다.
	 */
	void DebugPrintF(const wchar_t* format, ...);


	/**
	 * @brief 에러 코드에 대응하는 메시지를 얻습니다.
	 *
	 * @param errorCode 확인할 에러 코드입니다.
	 *
	 * @return 에러 코드에 대응하는 메시지를 반환합니다.
	 */
	std::string GetWindowsErrorMessageA(const uint32_t& errorCode);


	/**
	 * @brief 에러 코드에 대응하는 메시지를 얻습니다.
	 *
	 * @param errorCode 확인할 에러 코드입니다.
	 *
	 * @return 에러 코드에 대응하는 메시지를 반환합니다.
	 */
	std::wstring GetWindowsErrorMessageW(const uint32_t& errorCode);


	/**
	 * @brief 에러 코드에 대응하는 메시지를 얻습니다.
	 *
	 * @param errorCode 확인할 에러 코드입니다.
	 *
	 * @return 에러 코드에 대응하는 메시지를 반환합니다.
	 *
	 * @note
	 * - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetError.xhtml
	 * - https://www.khronos.org/opengl/wiki/OpenGL_Error
	 */
	std::string GetGLErrorMessageA(const uint32_t& errorCode);


	/**
	 * @brief 에러 코드에 대응하는 메시지를 얻습니다.
	 *
	 * @param errorCode 확인할 에러 코드입니다.
	 *
	 * @return 에러 코드에 대응하는 메시지를 반환합니다.
	 *
	 * @note
	 * - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetError.xhtml
	 * - https://www.khronos.org/opengl/wiki/OpenGL_Error
	 */
	std::wstring GetGLErrorMessageW(const uint32_t& errorCode);
}