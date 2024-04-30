#include "PreCompile.h"
#include "EyePuzzle.h"

AEyePuzzle::AEyePuzzle()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	ChildRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	ChildRenderer->SetupAttachment(Root);
	ChildRenderer->AddPosition(FVector(-2.0f, -40.0f, 0.0f));

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

	ChildRenderer->CreateAnimation("Light_Fairy", "lightfairy", 0.4f, true);

	ChildRenderer->ChangeAnimation("Light_Fairy");

	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->SetAutoSize(2.0f, true);

	ChildRenderer->SetOrder(ERenderOrder::Monster);
	ChildRenderer->SetAutoSize(1.0f, true);
	
}

void AEyePuzzle::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
