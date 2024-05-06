#include "PreCompile.h"
#include "ContentsCore.h"
#include "PlayGameMode.h"
#include "DarkGameMode.h"
#include <EngineCore/EngineSprite.h>

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::Initialize()
{
	UEngineFont::Load("궁서");

	{
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("Resources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSprite::Load(File.GetFullPath());
		}
	
		std::vector<UEngineDirectory> Directories = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directories.size(); i++)
		{
			std::string Name = Directories[i].GetFolderName();
			UEngineSprite::LoadFolder(Directories[i].GetFullPath());
		}

	}


	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->CreateLevel<ADarkGameMode>("DarkLevel");
	GEngine->ChangeLevel("DarkLevel");

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