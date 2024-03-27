#include "PreCompile.h"
#include "ContentsCore.h"

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::Initialize()
{
	// GEngine->CreateLevel();
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("Resources");
	
	std::list<UEngineFile> Files = Dir.AllFile({ ".wav" });
	for (UEngineFile& File : Files)
	{
		UEngineSound::Load(File.GetFullPath());
	}

	UEngineSound::SoundPlay("anipang_ingame.wav");

	int a = 0;
}