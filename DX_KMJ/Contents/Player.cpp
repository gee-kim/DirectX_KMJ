#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

APlayer::APlayer()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);

	InputOn();

}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	Super::BeginPlay();
	// 랜더가 이때 들어간간다.

	Renderer->CreateAnimation("Attack0", "krisb_act", 0.1f);
	Renderer->CreateAnimation("Move_Down", "kris_down", 0.1f);
	Renderer->CreateAnimation("Move_Right", "kris_right", 0.1f);
	Renderer->CreateAnimation("Move_Left", "kris_Left", 0.1f);
	Renderer->CreateAnimation("Hug", "kris_hug", 0.1f);

	Renderer->ChangeAnimation("Attack0");
	Renderer->SetOrder(ERenderOrder::Player);
	Renderer->SetAutoSize(2.0f, true);
	//FVector ImageScale = Renderer->GetWorldScale();
	//Renderer->SetScale(FVector(63.0f, 44.0f, 100.0f));
	int a = 0;
}

void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	
}