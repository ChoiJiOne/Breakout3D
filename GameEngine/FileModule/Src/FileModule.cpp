#include "FileModule.h"

#include <shlwapi.h>

const uint32_t MAX_BUFFER_SIZE = 1024;
char errorMessageBuffer[MAX_BUFFER_SIZE];

const char* FileModule::GetErrorMessage()
{
	return &errorMessageBuffer[0];
}

bool FileModule::ReadBufferFromFile(const std::string& path, std::vector<uint8_t>& outBuffer)
{
	HANDLE fileHandle = CreateFileA(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		uint32_t size = FormatMessageA
		(
			FORMAT_MESSAGE_FROM_SYSTEM,
			nullptr,
			static_cast<DWORD>(GetLastError()),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			errorMessageBuffer,
			MAX_BUFFER_SIZE,
			nullptr
		);

		if (size == 0)
		{
			strncpy_s(errorMessageBuffer, MAX_BUFFER_SIZE, "failed to open file", MAX_BUFFER_SIZE);
		}

		return false;
	}

	DWORD fileSize = GetFileSize(fileHandle, nullptr);
	outBuffer.resize(fileSize);

	DWORD bytesRead;
	if (!ReadFile(fileHandle, &outBuffer[0], fileSize, &bytesRead, nullptr))
	{
		uint32_t size = FormatMessageA
		(
			FORMAT_MESSAGE_FROM_SYSTEM,
			nullptr,
			static_cast<DWORD>(GetLastError()),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			errorMessageBuffer,
			MAX_BUFFER_SIZE,
			nullptr
		);

		if (size == 0)
		{
			strncpy_s(errorMessageBuffer, MAX_BUFFER_SIZE, "failed to read file", MAX_BUFFER_SIZE);
		}

		return false;
	}

	if (!CloseHandle(fileHandle))
	{
		uint32_t size = FormatMessageA
		(
			FORMAT_MESSAGE_FROM_SYSTEM,
			nullptr,
			static_cast<DWORD>(GetLastError()),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			errorMessageBuffer,
			MAX_BUFFER_SIZE,
			nullptr
		);

		if (size == 0)
		{
			strncpy_s(errorMessageBuffer, MAX_BUFFER_SIZE, "failed to close file", MAX_BUFFER_SIZE);
		}

		return false;
	}

	return true;
}

bool FileModule::ReadBufferFromFile(const std::wstring& path, std::vector<uint8_t>& outBuffer)
{
	HANDLE fileHandle = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		uint32_t size = FormatMessageA
		(
			FORMAT_MESSAGE_FROM_SYSTEM,
			nullptr,
			static_cast<DWORD>(GetLastError()),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			errorMessageBuffer,
			MAX_BUFFER_SIZE,
			nullptr
		);

		if (size == 0)
		{
			strncpy_s(errorMessageBuffer, MAX_BUFFER_SIZE, "failed to open file", MAX_BUFFER_SIZE);
		}

		return false;
	}

	DWORD fileSize = GetFileSize(fileHandle, nullptr);
	outBuffer.resize(fileSize);

	DWORD bytesRead;
	if (!ReadFile(fileHandle, &outBuffer[0], fileSize, &bytesRead, nullptr))
	{
		uint32_t size = FormatMessageA
		(
			FORMAT_MESSAGE_FROM_SYSTEM,
			nullptr,
			static_cast<DWORD>(GetLastError()),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			errorMessageBuffer,
			MAX_BUFFER_SIZE,
			nullptr
		);

		if (size == 0)
		{
			strncpy_s(errorMessageBuffer, MAX_BUFFER_SIZE, "failed to open file", MAX_BUFFER_SIZE);
		}

		return false;
	}

	if (!CloseHandle(fileHandle))
	{
		uint32_t size = FormatMessageA
		(
			FORMAT_MESSAGE_FROM_SYSTEM,
			nullptr,
			static_cast<DWORD>(GetLastError()),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			errorMessageBuffer,
			MAX_BUFFER_SIZE,
			nullptr
		);

		if (size == 0)
		{
			strncpy_s(errorMessageBuffer, MAX_BUFFER_SIZE, "failed to open file", MAX_BUFFER_SIZE);
		}

		return false;
	}

	return true;
}
