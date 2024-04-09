#include "PreCompile.h"
#include "ContentsCore.h"
#include "PlayGameMode.h"

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::Initialize()
{
	// GEngine->CreateLevel();

	{
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("Resources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineTexture::Load(File.GetFullPath());
		}
	
	}

	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

	//UEngineDirectory Dir;
	//Dir.MoveToSearchChild("Resources");
	//
	//std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
	//for (UEngineFile& File : Files)
	//{
	//	UEngineSound::Load(File.GetFullPath());
	//}

	//UEngineSound::SoundPlay("anipang_ingame.wav");



	int a = 0;
}