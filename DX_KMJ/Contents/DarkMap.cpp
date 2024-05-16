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

	Renderer->SetSprite("Dark_Map0.png");

	// Renderer->SetAutoSize(1.0f, true);

	Back_Renderer->SetSprite("dark_colmap0.png");

	Renderer->SetOrder(ERenderOrder::Back);


}

void ADarkMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (UEngineInput::IsDown('O'))
	{
		SwitchDebug();
	}

}
