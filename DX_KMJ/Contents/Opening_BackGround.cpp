#include "PreCompile.h"
#include "Opening_BackGround.h"
#include "BackGround.h"


AOpening_BackGround::AOpening_BackGround()
{
}

AOpening_BackGround::~AOpening_BackGround()
{
}


void AOpening_BackGround::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("bg_torhouse_bg_ch1_0.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::Back);
}

void AOpening_BackGround::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);
}