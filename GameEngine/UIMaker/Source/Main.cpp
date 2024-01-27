#include "IApplication.h"

#include "Config.h"

#include <imgui.h>


/**
 * @brief UI 생성 애플리케이션입니다.
 */
class UIMakerApp : public IApplication
{
public:
	/**
	 * @brief UI 생성 애플리케이션의 디폴트 생성자입니다.
	 */
	UIMakerApp() = default;


	/**
	 * @brief UI 생성 애플리케이션의 가상 소멸자입니다.
	 */
	virtual ~UIMakerApp()
	{
		Shutdown();
	}


	/**
	 * @brief UI 생성 애플리케이션의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(UIMakerApp);


	/**
	 * @brief UI 생성 애플리케이션를 초기화합니다.
	 */
	virtual void Setup() override
	{
		IApplication::SetProperties(WINDOW_TITLE, WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H, WINDOW_RESIZE, WINDOW_FULLSCREEN, WINDOW_VSYNC, WINDOW_IMGUI);
		IApplication::Setup();
	}


	/**
	 * @brief UI 생성 애플리케이션 사용을 종료합니다.
	 */
	virtual void Shutdown() override
	{
		IApplication::Shutdown();
	}


	/**
	 * @brief UI 생성 애플리케이션를 실행합니다.
	 */
	virtual void Run() override
	{
		while (!bIsDoneLoop_)
		{
			InputManager::Get().Tick();

			ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
			ImGui::SetNextWindowSize(ImVec2(800.0f, 800.0f));
			ImGui::Begin("Layout", false, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
			ImGui::End();

			ImGui::SetNextWindowPos(ImVec2(800.0f, 0.0f));
			ImGui::SetNextWindowSize(ImVec2(200.0f, 800.0f));
			ImGui::Begin("Properties", false, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
			ImGui::End();

			RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

			RenderManager::Get().EndFrame();
		}
	}
};

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	std::unique_ptr<IApplication> uiMaker = std::make_unique<UIMakerApp>();
	uiMaker->Setup();
	uiMaker->Run();
	uiMaker->Shutdown();
	return 0;
}