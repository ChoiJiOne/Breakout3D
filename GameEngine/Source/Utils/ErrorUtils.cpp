#include "Utils/ErrorUtils.h"
#include "Utils/StringUtils.h"

#include <cstdarg>
#include <cstdio>

#include <glad/glad_wgl.h>
#include <glad/glad.h>

void ErrorUtils::DebugPrintF(const char* format, ...)
{
	char* bufferPtr = StringUtils::GetCharBufferPtr();
	std::size_t count = static_cast<std::size_t>(StringUtils::STRING_BUFFER_SIZE);

	va_list args;
	va_start(args, format);
	int32_t size = _vsnprintf_s(bufferPtr, count, count, format, args);
	va_end(args);

	OutputDebugStringA(bufferPtr);
}

void ErrorUtils::DebugPrintF(const wchar_t* format, ...)
{
	wchar_t* bufferPtr = StringUtils::GetWideCharBufferPtr();
	std::size_t count = static_cast<std::size_t>(StringUtils::STRING_BUFFER_SIZE);
	
	va_list args;
	va_start(args, format);
	int32_t size = _vsnwprintf_s(bufferPtr, count, count, format, args);
	va_end(args);

	OutputDebugStringW(bufferPtr);
}

std::string ErrorUtils::GetWindowsErrorMessageA(const uint32_t& errorCode)
{
	char* bufferPtr = StringUtils::GetCharBufferPtr();
	std::size_t count = static_cast<std::size_t>(StringUtils::STRING_BUFFER_SIZE);

	uint32_t size = FormatMessageA(
		FORMAT_MESSAGE_FROM_SYSTEM,
		nullptr,
		static_cast<DWORD>(errorCode),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		bufferPtr,
		count,
		nullptr
	);

	return std::string(bufferPtr, size);
}

std::wstring ErrorUtils::GetWindowsErrorMessageW(const uint32_t& errorCode)
{
	wchar_t* bufferPtr = StringUtils::GetWideCharBufferPtr();
	std::size_t count = static_cast<std::size_t>(StringUtils::STRING_BUFFER_SIZE);

	uint32_t size = FormatMessageW(
		FORMAT_MESSAGE_FROM_SYSTEM,
		nullptr,
		static_cast<DWORD>(errorCode),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		bufferPtr,
		count,
		nullptr
	);

	return std::wstring(bufferPtr, size);
}

std::string ErrorUtils::GetGLErrorMessageA(const uint32_t& errorCode)
{
	std::string errorMessage;

	switch (errorCode)
	{
	case GL_NO_ERROR:
		errorMessage = "No error has been recorded. (GL_NO_ERROR)";
		break;

	case GL_INVALID_ENUM:
		errorMessage = "An unacceptable value is specified for an enumerated argument. (GL_INVALID_ENUM)";
		break;

	case GL_INVALID_VALUE:
		errorMessage = "A numeric argument is out of range. (GL_INVALID_VALUE)";
		break;

	case GL_INVALID_OPERATION:
		errorMessage = "The specified operation is not allowed in the current state. (GL_INVALID_OPERATION)";
		break;

	case GL_INVALID_FRAMEBUFFER_OPERATION:
		errorMessage = "The framebuffer object is not complete. (GL_INVALID_FRAMEBUFFER_OPERATION)";
		break;

	case GL_OUT_OF_MEMORY:
		errorMessage = "There is not enough memory left to execute the command. (GL_OUT_OF_MEMORY)";
		break;

	case GL_STACK_UNDERFLOW:
		errorMessage = "An attempt has been made to perform an operation that would cause an internal stack to underflow. (GL_STACK_UNDERFLOW)";
		break;

	case GL_STACK_OVERFLOW:
		errorMessage = "An attempt has been made to perform an operation that would cause an internal stack to overflow. (GL_STACK_OVERFLOW)";
		break;

	case GL_CONTEXT_LOST:
		errorMessage = "This occurs when the OpenGL context becomes lost due to a graphics card reset. (GL_CONTEXT_LOST)";
		break;

	default:
		errorMessage = "Undefined error message.";
	}

	return errorMessage;
}

std::wstring ErrorUtils::GetGLErrorMessageW(const uint32_t& errorCode)
{
	std::wstring errorMessage;

	switch (errorCode)
	{
	case GL_NO_ERROR:
		errorMessage = L"No error has been recorded. (GL_NO_ERROR)";
		break;

	case GL_INVALID_ENUM:
		errorMessage = L"An unacceptable value is specified for an enumerated argument. (GL_INVALID_ENUM)";
		break;

	case GL_INVALID_VALUE:
		errorMessage = L"A numeric argument is out of range. (GL_INVALID_VALUE)";
		break;

	case GL_INVALID_OPERATION:
		errorMessage = L"The specified operation is not allowed in the current state. (GL_INVALID_OPERATION)";
		break;

	case GL_INVALID_FRAMEBUFFER_OPERATION:
		errorMessage = L"The framebuffer object is not complete. (GL_INVALID_FRAMEBUFFER_OPERATION)";
		break;

	case GL_OUT_OF_MEMORY:
		errorMessage = L"There is not enough memory left to execute the command. (GL_OUT_OF_MEMORY)";
		break;

	case GL_STACK_UNDERFLOW:
		errorMessage = L"An attempt has been made to perform an operation that would cause an internal stack to underflow. (GL_STACK_UNDERFLOW)";
		break;

	case GL_STACK_OVERFLOW:
		errorMessage = L"An attempt has been made to perform an operation that would cause an internal stack to overflow. (GL_STACK_OVERFLOW)";
		break;

	case GL_CONTEXT_LOST:
		errorMessage = L"This occurs when the OpenGL context becomes lost due to a graphics card reset. (GL_CONTEXT_LOST)";
		break;

	default:
		errorMessage = L"Undefined error message.";
	}

	return errorMessage;
}