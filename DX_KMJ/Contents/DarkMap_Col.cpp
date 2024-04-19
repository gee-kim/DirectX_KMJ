#include "PreCompile.h"
#include "DarkMap_Col.h"

ADarkMap_Col::ADarkMap_Col()
{
}

ADarkMap_Col::~ADarkMap_Col()
{
}

void ADarkMap_Col::BeginPlay()
{
	Super::BeginPlay();
	
	Renderer->SetSprite("Dark_ColMap.png");
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::ColBack);



}

void ADarkMap_Col::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}