#include "Core/ObjectManager.h"

#include "Macro/Assertion.h"

ObjectManager& ObjectManager::Get()
{
	static ObjectManager instance;
	return instance;
}

void ObjectManager::Startup()
{
	ASSERT(!bIsStartup_, "already startup object manager...");

	objectCache_ = std::unordered_map<std::string, std::unique_ptr<IObject>>();

	bIsStartup_ = true;
}

void ObjectManager::Shutdown()
{
	ASSERT(bIsStartup_, "not startup before or has already been shutdowned...");

	for (auto& object : objectCache_)
	{
		object.second->Release();
		object.second.reset();
	}

	bIsStartup_ = false;
}

void ObjectManager::DestroyObject(const std::string& signature)
{
	if (IsValidKey(signature))
	{
		IObject* object = objectCache_.at(signature).get();
		if (object && object->IsInitialized())
		{
			object->Release();
		}

		objectCache_.erase(signature);
	}
}

bool ObjectManager::IsValidKey(const std::string& key)
{
	return objectCache_.find(key) != objectCache_.end();
}