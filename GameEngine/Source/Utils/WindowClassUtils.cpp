#include "Macro/Assertion.h"
#include "Macro/WindowsAssertion.h"

#include "Utils/WindowClassUtils.h"

bool bIsRegisterWindowClass = false;
HINSTANCE hInstance = nullptr;
std::wstring windowClassName;

void WindowClassUtils::RegisterWindowClass(const std::wstring& className, WINDOWPROC windowProc)
{
	ASSERT(!bIsRegisterWindowClass, "already register window class...");
	ASSERT(windowProc != nullptr, "Window procedure is nullptr...");

	hInstance = GetModuleHandleW(nullptr);
	windowClassName = className;

	WNDCLASSEXW wcexw = {};
	wcexw.cbSize = sizeof(WNDCLASSEXW);
	wcexw.style = CS_HREDRAW | CS_VREDRAW;
	wcexw.lpfnWndProc = windowProc;
	wcexw.cbClsExtra = 0;
	wcexw.cbWndExtra = 0;
	wcexw.hInstance = hInstance;
	wcexw.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcexw.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wcexw.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wcexw.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcexw.lpszMenuName = nullptr;
	wcexw.lpszClassName = windowClassName.c_str();

	WINDOWS_ASSERT(RegisterClassExW(&wcexw) != 0, "failed to register window class...");
	bIsRegisterWindowClass = true;
}

void WindowClassUtils::UnregisterWindowClass()
{
	ASSERT(bIsRegisterWindowClass, "haven't registered before or have already unregistered...");

	UnregisterClassW(windowClassName.c_str(), hInstance);

	hInstance = nullptr;
	bIsRegisterWindowClass = false;
}

const wchar_t* WindowClassUtils::GetWindowClassName()
{
	return windowClassName.c_str();
}

HINSTANCE WindowClassUtils::GetWindowClassInstance()
{
	return hInstance;
}