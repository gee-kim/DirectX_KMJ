#include "PreCompile.h"
#include "DarkMap.h"

ADarkMap::ADarkMap()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
	InputOn();
}

ADarkMap::~ADarkMap()
{
}

void ADarkMap::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("deltarune_map0.png");

	Renderer->SetAutoSize(1.0f, true);

	Renderer->SetOrder(ERenderOrder::Back);

}

void ADarkMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
