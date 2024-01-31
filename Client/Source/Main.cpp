#include "IApplication.h"

#include "Config.h"


/**
 * @brief 게임 애플리케이션입니다.
 */
class GameApplication : public IApplication
{
public:
	/**
	 * @brief 게임 애플리케이션의 디폴트 생성자입니다.
	 */
	GameApplication() = default;


	/**
	 * @brief 게임 애플리케이션의 가상 소멸자입니다.
	 */
	virtual ~GameApplication()
	{
		Shutdown();
	}


	/**
	 * @brief 게임 애플리케이션의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(GameApplication);


	/**
	 * @brief 게임 애플리케이션를 초기화합니다.
	 */
	virtual void Setup() override
	{
		IApplication::SetProperties(WINDOW_TITLE, WINDOW_X, WINDOW_Y, WINDOW_W, WINDOW_H, WINDOW_RESIZE, WINDOW_FULLSCREEN, WINDOW_VSYNC, WINDOW_IMGUI);
		IApplication::Setup();
	}


	/**
	 * @brief 게임 애플리케이션 사용을 종료합니다.
	 */
	virtual void Shutdown() override
	{
		IApplication::Shutdown();
	}


	/**
	 * @brief 게임 애플리케이션를 실행합니다.
	 */
	virtual void Run() override
	{
		while (!bIsDoneLoop_)
		{
			InputManager::Get().Tick();

			RenderManager::Get().BeginFrame(0.0f, 1.0f, 0.0f, 1.0f);
			RenderManager::Get().EndFrame();
		}
	}
};

int32_t WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int32_t nCmdShow)
{
	std::unique_ptr<IApplication> game = std::make_unique<GameApplication>();
	game->Setup();
	game->Run();
	game->Shutdown();
	return 0;
}