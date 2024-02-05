#include "Macro/Assertion.h"
#include "Macro/WindowsAssertion.h"

#include "Core/Window.h"

#include "Utils/WindowClassUtils.h"


Window::~Window()
{
	Destroy();
}

void Window::Create(const WindowConstructParam& windowConstructParam)
{
	Create(
		windowConstructParam.title,
		windowConstructParam.x,
		windowConstructParam.y,
		windowConstructParam.w,
		windowConstructParam.h,
		windowConstructParam.bIsResizable,
		windowConstructParam.bIsFullscreenMode
	);
}

void Window::Create(const std::wstring& title, int32_t x, int32_t y, int32_t w, int32_t h, bool bIsResizable, bool bIsFullscreenMode)
{
	ASSERT(windowHandle_ == nullptr, "already create window...");

	int32_t windowPosX = 0;
	int32_t windowPosY = 0;
	int32_t windowWidth = 0;
	int32_t windowHeight = 0;
	uint32_t windowStyle = WS_VISIBLE;

	if (bIsFullscreenMode)
	{
		bIsResizable_ = false;
		bIsFullscreenMode_ = true;

		windowPosX = 0;
		windowPosY = 0;
		windowWidth = static_cast<int32_t>(GetSystemMetrics(SM_CXSCREEN));
		windowHeight = static_cast<int32_t>(GetSystemMetrics(SM_CYSCREEN));
		windowStyle |= WS_POPUP;

		DEVMODEW devMode = {};
		devMode.dmSize = sizeof(DEVMODEW);
		devMode.dmPelsWidth = static_cast<uint32_t>(windowWidth);
		devMode.dmPelsHeight = static_cast<uint32_t>(windowHeight);
		devMode.dmBitsPerPel = 32;
		devMode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		WINDOWS_ASSERT(ChangeDisplaySettingsW(&devMode, CDS_FULLSCREEN) == DISP_CHANGE_SUCCESSFUL, "failed to set fullscreen mode...");
	}
	else
	{
		bIsResizable_ = bIsResizable;
		bIsFullscreenMode_ = false;

		RECT windowRect = { 0, 0, w, h };
		WINDOWS_ASSERT(AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE), "failed to calculate window size...");

		windowPosX = x;
		windowPosY = y;
		windowWidth = windowRect.right - windowRect.left;
		windowHeight = windowRect.bottom - windowRect.top;
		windowStyle |= bIsResizable ? WS_OVERLAPPEDWINDOW : (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);
	}

	windowHandle_ = CreateWindowExW(
		WS_EX_APPWINDOW,
		WindowClassUtils::GetWindowClassName(),
		title.c_str(),
		static_cast<DWORD>(windowStyle),
		windowPosX,
		windowPosY,
		windowWidth,
		windowHeight,
		nullptr,
		nullptr,
		WindowClassUtils::GetWindowClassInstance(),
		nullptr
	);
	WINDOWS_ASSERT(windowHandle_ != nullptr, "failed to create window...");
}

void Window::Destroy()
{
	if (windowHandle_ == nullptr)
	{
		return;
	}

	if (bIsFullscreenMode_)
	{
		WINDOWS_ASSERT(ChangeDisplaySettingsW(nullptr, 0) == DISP_CHANGE_SUCCESSFUL, "failed to set default mode...");
	}

	if (IsWindow(windowHandle_))
	{
		WINDOWS_ASSERT(DestroyWindow(windowHandle_), "failed to destroy window...");
	}

	windowHandle_ = nullptr;
}

void Window::GetSize(int32_t& outWidth, int32_t& outHeight) const
{
	RECT windowRect;
	WINDOWS_ASSERT(GetClientRect(windowHandle_, &windowRect), "failed to calculate window size...");

	outWidth = static_cast<int32_t>(windowRect.right - windowRect.left);
	outHeight = static_cast<int32_t>(windowRect.bottom - windowRect.top);
}

float Window::GetAspectSize() const
{
	int32_t windowWidth = 0;
	int32_t windowHeight = 0;
	GetSize(windowWidth, windowHeight);

	return static_cast<float>(windowWidth) / static_cast<float>(windowHeight);
}

void Window::GetPosition(int32_t& outPosX, int32_t& outPosY)
{
	RECT windowRect;
	WINDOWS_ASSERT(GetClientRect(windowHandle_, &windowRect), "failed to calculate window size...");

	outPosX = static_cast<int32_t>(windowRect.left);
	outPosY = static_cast<int32_t>(windowRect.top);
}