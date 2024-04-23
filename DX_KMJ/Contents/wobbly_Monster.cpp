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
}

void AWobbly_Monster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}