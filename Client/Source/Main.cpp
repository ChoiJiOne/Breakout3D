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
		std::wstring shaderPath = rootPath_ + L"Client/Shader/";
		std::wstring resourcePath = rootPath_ + L"Client/Resource/";

		std::vector<Vertex> vertices;
		std::vector<uint32_t> indices;
		GeometryGenerator::CreateSphere(1.0f, 30, vertices, indices);

		StaticMesh* mesh = ResourceManager::Get().CreateResource<StaticMesh>("Sphere");
		mesh->Initialize(vertices, indices);

		Texture2D* albedoMap = ResourceManager::Get().CreateResource<Texture2D>("AlbedoMap");
		albedoMap->Initialize(resourcePath + L"Texture/AlbedoMap.png");

		Texture2D* normalMap = ResourceManager::Get().CreateResource<Texture2D>("NormalMap");
		normalMap->Initialize(resourcePath + L"Texture/NormalMap.png");

		Texture2D* heightMap = ResourceManager::Get().CreateResource<Texture2D>("HeightMap");
		heightMap->Initialize(resourcePath + L"Texture/HeightMap.png");

		Shader* shader = ResourceManager::Get().CreateResource<Shader>("Shader");
		shader->Initialize(shaderPath + L"Shader.vert", shaderPath + L"Shader.frag");

		Camera3D* camera = ObjectManager::Get().CreateObject<Camera3D>("Camera");
		camera->Initialize(
			Vector3f(5.0f, 5.0f, 5.0f),
			Vector3f(-1.0f, -1.0f, -1.0f), 
			Vector3f(0.0f, 1.0f, 0.0f),
			MathUtils::ToRadian(45.0f), 
			window_->GetAspectSize(), 
			0.1f, 
			100.0f
		);

		while (!bIsDoneLoop_)
		{
			InputManager::Get().Tick();

			RenderManager::Get().BeginFrame(0.0f, 0.0f, 0.0f, 1.0f);

			Matrix4x4f world = Matrix4x4f::GetIdentity();

			shader->Bind();
			{
				albedoMap->Active(0);

				shader->SetUniform("world", world);
				shader->SetUniform("view", camera->GetViewMatrix());
				shader->SetUniform("projection", camera->GetProjectionMatrix());

				glBindVertexArray(mesh->GetVertexArrayObject());
				glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
				glBindVertexArray(0);

			}
			shader->Unbind();

			RenderManager::Get().RenderGrid3D(camera, -5.0f, 5.0f, 1.0f, -5.0f, 5.0f, 1.0f, Vector4f(1.0f, 1.0f, 1.0f, 0.5f));
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