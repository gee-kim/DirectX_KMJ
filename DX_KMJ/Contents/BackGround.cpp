#include "PreCompile.h"
#include "BackGround.h"
#include <EngineCore/DefaultSceneComponent.h>


ABackGround::ABackGround()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");


	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Back_Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Back_Renderer->SetupAttachment(Root);
		
	Logo_Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Logo_Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ABackGround::~ABackGround()
{
}


void ABackGround::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABackGround::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
	
}


void ABackGround::SwitchDebug()
{
	if (true == Renderer->IsActive())
	{
		Renderer->SetActive(false);
	}
	else
	{
		Renderer->SetActive(true);
	}

}
