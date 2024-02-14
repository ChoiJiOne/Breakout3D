#pragma once

#include <cstdint>
#include <string>
#include <vector>


/**
 * @brief 파일 및 디렉토리 관련 기능을 제공합니다.
 */
namespace FileModule
{
	/**
	 * @brief 파일 모듈의 에러 메시지를 얻습니다.
	 * 
	 * @return 파일 모듈의 C스타일 에러 메시지를 반환합니다.
	 */
	const char* GetErrorMessage();


	/**
	 * @brief 파일을 읽고 버퍼에 저장합니다.
	 *
	 * @param path 파일의 경로입니다.
	 * @param outBuffer 파일의 내용을 저장할 버퍼입니다.
	 *
	 * @return 파일을 읽어 버퍼에 저장하는 데 성공하면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-readfile
	 */
	bool ReadBufferFromFile(const std::string& path, std::vector<uint8_t>& outBuffer);


	/**
	 * @brief 파일을 읽고 버퍼에 저장합니다.
	 *
	 * @param path 파일의 경로입니다.
	 * @param outBuffer 파일의 내용을 저장할 버퍼입니다.
	 *
	 * @return 파일을 읽어 버퍼에 저장하는 데 성공하면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-readfile
	 */
	bool ReadBufferFromFile(const std::wstring& path, std::vector<uint8_t>& outBuffer);


	/**
	 * @brief 버퍼를 파일에 씁니다.
	 *
	 * @param path 버퍼를 쓸 파일의 경로입니다.
	 * @param buffer 파일에 쓸 버퍼입니다.
	 * 
	 * @return 버퍼를 파일에 쓰는 데 성공하면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-writefile
	 */
	bool WriteBufferToFile(const std::string& path, const std::vector<uint8_t>& buffer);


	/**
	 * @brief 버퍼를 파일에 씁니다.
	 *
	 * @param path 버퍼를 쓸 파일의 경로입니다.
	 * @param buffer 파일에 쓸 버퍼입니다.
	 * 
	 * @return 버퍼를 파일에 쓰는 데 성공하면 true, 그렇지 않으면 false를 반환합니다.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilew
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-writefile
	 */
	bool WriteBufferToFile(const std::wstring& path, const std::vector<uint8_t>& buffer);


	/**
	 * @brief 파일 혹은 디렉토리가 유효한지 확인합니다.
	 *
	 * @param path 유효한지 확인할 파일 혹은 디렉토리 경로입니다.
	 *
	 * @return 파일 혹은 디렉토리가 유효하다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsValidPath(const std::string& path);


	/**
	 * @brief 파일 혹은 디렉토리가 유효한지 확인합니다.
	 *
	 * @param path 유효한지 확인할 파일 혹은 디렉토리 경로입니다.
	 *
	 * @return 파일 혹은 디렉토리가 유효하다면 true, 그렇지 않다면 false를 반환합니다.
	 */
	bool IsValidPath(const std::wstring& path);
}