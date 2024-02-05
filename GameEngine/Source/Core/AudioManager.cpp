#include "Macro/Assertion.h"

#include "Core/AudioManager.h"

AudioManager& AudioManager::Get()
{
	static AudioManager instance;
	return instance;
}

void AudioManager::Startup()
{
	ASSERT(!bIsStartup_, "already startup audio manager...");

	audioEngine_ = std::make_unique<ma_engine>();
	ASSERT(ma_engine_init(nullptr, audioEngine_.get()) == MA_SUCCESS, "failed to initialize miniaudio engine...");

	bIsStartup_ = true;
}

void AudioManager::Shutdown()
{
	ASSERT(bIsStartup_, "not startup before or has already been shutdowned...");

	ma_engine_uninit(audioEngine_.get());
	audioEngine_.reset();

	bIsStartup_ = false;
}