#include "Wobbly_Monster.h"

AWobbly_Monster::AWobbly_Monster()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

AWobbly_Monster::~AWobbly_Monster()
{
}

void AWobbly_Monster::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Wobbly_Idle", "wobblything", 0.5f);
	Renderer->CreateAnimation("Wobbly_Drak", "wobblything_evil", 0.5f);

	// Renderer->ChangeAnimation("Wobbly_Idle");

	Renderer->SetOrder(ERenderOrder::Monster);

	Renderer->SetAutoSize(2.0f, true);


}

void AWobbly_Monster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}