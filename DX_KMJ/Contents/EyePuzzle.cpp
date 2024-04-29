#include "PreCompile.h"
#include "EyePuzzle.h"

AEyePuzzle::AEyePuzzle()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(30.0f, 30.0f, 30.0f));
	Collision->AddPosition(FVector(0.0f, -10.0f, 0.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision->SetCollisionGroup(ECollisionOrder::PosCheck);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);


}

AEyePuzzle::~AEyePuzzle()
{
}

void AEyePuzzle::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("EyePuzzle_1", "eyepuzzle", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("EyePuzzle_2", "eyepuzzle", 0.0f, false, 1, 1);
	Renderer->CreateAnimation("EyePuzzle_3", "eyepuzzle", 0.0f, false, 2, 2);

	//Renderer->ChangeAnimation("EyePuzzle_1");

	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->SetAutoSize(2.0f, true);

	
}

void AEyePuzzle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
