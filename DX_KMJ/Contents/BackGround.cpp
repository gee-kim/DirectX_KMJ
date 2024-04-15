#include "BackGround.h"
#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsEnum.h"
#include "ContentsConstValue.h"

ABackGround::ABackGround()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
	//InputOn();
}

ABackGround::~ABackGround()
{
}


void ABackGround::BeginPlay()
{
	Super::BeginPlay();
	
	Renderer->SetSprite("bg_torhouse_bg_ch1_0.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackGround::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);
}