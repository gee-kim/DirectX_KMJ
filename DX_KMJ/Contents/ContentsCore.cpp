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
		// ������ ���
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("Resources");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			//File.Open(EIOOpenMode::Read, EIODataType::Binary);

			//char Arr[100];
			//File.Read(Arr, 100);

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