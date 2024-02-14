#pragma once

#include <cstdint>
#include <string>
#include <vector>


/**
 * @brief ���� �� ���丮 ���� ����� �����մϴ�.
 */
namespace FileModule
{
	/**
	 * @brief ���� ����� ���� �޽����� ����ϴ�.
	 * 
	 * @return ���� ����� C��Ÿ�� ���� �޽����� ��ȯ�մϴ�.
	 */
	const char* GetErrorMessage();


	/**
	 * @brief ������ �а� ���ۿ� �����մϴ�.
	 *
	 * @param path ������ ����Դϴ�.
	 * @param outBuffer ������ ������ ������ �����Դϴ�.
	 *
	 * @return ������ �о� ���ۿ� �����ϴ� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-readfile
	 */
	bool ReadBufferFromFile(const std::string& path, std::vector<uint8_t>& outBuffer);


	/**
	 * @brief ������ �а� ���ۿ� �����մϴ�.
	 *
	 * @param path ������ ����Դϴ�.
	 * @param outBuffer ������ ������ ������ �����Դϴ�.
	 *
	 * @return ������ �о� ���ۿ� �����ϴ� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-readfile
	 */
	bool ReadBufferFromFile(const std::wstring& path, std::vector<uint8_t>& outBuffer);


	/**
	 * @brief ���۸� ���Ͽ� ���ϴ�.
	 *
	 * @param path ���۸� �� ������ ����Դϴ�.
	 * @param buffer ���Ͽ� �� �����Դϴ�.
	 * 
	 * @return ���۸� ���Ͽ� ���� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilea
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-writefile
	 */
	bool WriteBufferToFile(const std::string& path, const std::vector<uint8_t>& buffer);


	/**
	 * @brief ���۸� ���Ͽ� ���ϴ�.
	 *
	 * @param path ���۸� �� ������ ����Դϴ�.
	 * @param buffer ���Ͽ� �� �����Դϴ�.
	 * 
	 * @return ���۸� ���Ͽ� ���� �� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 * @see
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-createfilew
	 * - https://learn.microsoft.com/ko-kr/windows/win32/api/fileapi/nf-fileapi-writefile
	 */
	bool WriteBufferToFile(const std::wstring& path, const std::vector<uint8_t>& buffer);
}