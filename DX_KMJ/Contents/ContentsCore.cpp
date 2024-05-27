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
	UEngineFont::Load("�ü�");
	UEngineFont::Load("����");
	UEngineFont::Load("����");

	{
		// ������ ���
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
	// ���� �ε�
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
	//Ÿ��Ʋ�� ����
	{
		
	}

	GEngine->CreateLevel<AOpeningGameMode>("OpeningLevel");
	GEngine->CreateLevel<ADarkGameMode>("DarkLevel");
	GEngine->ChangeLevel("DarkLevel");

	


	int a = 0;
}