#include "BackGround.h"
#include "PreCompile.h"


ABackGround::ABackGround()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);

	Back_Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
		
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
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);
}