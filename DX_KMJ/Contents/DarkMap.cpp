#include "PreCompile.h"
#include "DarkMap.h"
#include "BackGround.h"

ADarkMap::ADarkMap()
{

}

ADarkMap::~ADarkMap()
{
}

void ADarkMap::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Dark_Map.png");

	Renderer->SetAutoSize(1.0f, true);

	Renderer->SetOrder(ERenderOrder::Back);

}

void ADarkMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
