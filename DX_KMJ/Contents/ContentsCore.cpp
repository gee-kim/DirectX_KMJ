#include "PreCompile.h"
#include "ContentsCore.h"
#include "OpeningGameMode.h"
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
	UEngineFont::Load("바탕");
	UEngineFont::Load("굴림");

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
	// 사운드 로드
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("Resources");
		Dir.Move("Sound");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".ogg", ".wav" }, true);
		for (UEngineFile& File : Files)
		{
			UEngineSound::Load(File.GetFullPath());
		}

	}
	//타이틀명 변경
	{
		
	}

	GEngine->CreateLevel<AOpeningGameMode>("OpeningLevel");
	GEngine->CreateLevel<ADarkGameMode>("DarkLevel");
	GEngine->ChangeLevel("DarkLevel");

	


	int a = 0;
}