#include "BackGround.h"
#include "PreCompile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

ABackGround::ABackGround()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

ABackGround::~ABackGround()
{
}


void ABackGround::BeginPlay()
{
	Super::BeginPlay();
	
	Renderer->SetSprite("bg_torhouse_bg_ch1_0");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void ABackGround::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
}