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
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
}