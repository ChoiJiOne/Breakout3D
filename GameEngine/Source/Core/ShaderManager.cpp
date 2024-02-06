#include "Core/ShaderManager.h"

#include "Macro/Assertion.h"

ShaderManager& ShaderManager::Get()
{
	static ShaderManager instance;
	return instance;
}

void ShaderManager::Startup()
{
	ASSERT(!bIsStartup_, "already startup shader manager...");

	shaderCache_ = std::unordered_map<std::string, std::unique_ptr<Shader>>();

	bIsStartup_ = true;
}

void ShaderManager::Shutdown()
{
	ASSERT(bIsStartup_, "not startup before or has already been shutdowned...");

	for (auto& shader : shaderCache_)
	{
		shader.second->Release();
		shader.second.reset();
	}

	bIsStartup_ = false;
}

void ShaderManager::DestroyShader(const std::string& signature)
{
	if (IsValidKey(signature))
	{
		Shader* shader = shaderCache_.at(signature).get();
		if (shader && shader->IsInitialized())
		{
			shader->Release();
		}

		shaderCache_.erase(signature);
	}
}

bool ShaderManager::IsValidKey(const std::string& key)
{
	return shaderCache_.find(key) != shaderCache_.end();
}