#include "PreCompile.h"
#include "Susie.h"

ASusie::ASusie()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ASusie::~ASusie()
{
}

void ASusie::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Susie_Bubble.png");
	Renderer->CreateAnimation("Wobbly_Move", "wobblything", 0.2f);

	Renderer->ChangeAnimation("Wobbly_Idle");

	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->SetAutoSize(2.0f, true);

}

void ASusie::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

