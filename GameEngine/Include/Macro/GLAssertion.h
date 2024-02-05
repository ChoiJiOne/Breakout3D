#pragma once

#include "Utils/ErrorUtils.h"

#include <glad/glad_wgl.h>
#include <glad/glad.h>


/**
 * @brief OpenGL API 호출값을 검사합니다.
 *
 * @param X 검사할 호출값입니다.
 * @param ... 평가식을 만족하지 못할 경우 표시할 가변 인자 메시지입니다.
 *
 * @note
 * - Debug 모드와 Release 모드에서는 평가식을 검사하지만 Shipping 모드에서는 평가식을 검사하지 않습니다.
 * - 디버거가 존재하면 브레이크 포인트가 걸립니다.
 * - 디버거가 존재하지 않으면 크래시 덤프 파일을 생성합니다.
 */
#if defined(DEBUG_MODE)
#ifndef GL_ASSERT
#define GL_ASSERT(X, ...)\
X;\
{\
	GLenum glError = glGetError();\
	if (glError != GL_NO_ERROR)\
	{\
		ErrorUtils::DebugPrintF("\nOpenGL assertion check point failed!\nFile : %s\nLine : %d\nExpression : %s\nMessage : ", __FILE__, __LINE__, #X);\
		ErrorUtils::DebugPrintF(__VA_ARGS__);\
		ErrorUtils::DebugPrintF(L"\nOpenGL error message : %s\n", ErrorUtils::GetGLErrorMessageW(glError).c_str());\
		__debugbreak();\
		ExitProcess(-1);\
	}\
}
#endif
#elif defined(RELEASE_MODE) || defined(REL_WITH_DEB_INFO_MODE)
#ifndef GL_ASSERT
#define GL_ASSERT(X, ...)\
X;\
{\
	GLenum glError = glGetError();\
	if (glError != GL_NO_ERROR)\
	{\
		ErrorUtils::DebugPrintF("\nOpenGL assertion check point failed!\nFile : %s\nLine : %d\nExpression : %s\nMessage : ", __FILE__, __LINE__, #X);\
		ErrorUtils::DebugPrintF(__VA_ARGS__);\
		ErrorUtils::DebugPrintF(L"\nOpenGL error message : %s\n", ErrorUtils::GetGLErrorMessageW(glError).c_str());\
		__debugbreak();\
	}\
}
#endif
#else // defined(MIN_SIZE_REL_MODE)
#ifndef GL_ASSERT
#define GL_ASSERT(X, ...)\
X;
#endif
#endif