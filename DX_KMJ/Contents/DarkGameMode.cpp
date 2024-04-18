#include "PreCompile.h"
#include "DarkGameMode.h"
#include "DarkMap.h"
#include "Player.h"

#include <EngineCore/Camera.h>


ADarkGameMode::ADarkGameMode()
{
}

ADarkGameMode::~ADarkGameMode()
{
}

void ADarkGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// CameraSet
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -100.0f));

	// DarkMap 
	std::shared_ptr<ADarkMap> DarkMap = GetWorld()->SpawnActor<ADarkMap>("DarkMap");
	
	UContentsConstValue::MapTex = UEngineTexture::FindRes("deltarune_map0.png");
	UContentsConstValue::MapTexScale = UContentsConstValue::MapTex->GetScale();
	
	float TileSize = 1.0f;

	float4 TexScale = UContentsConstValue::MapTexScale;
	float4 ImageScale = { TexScale.X * TileSize, TexScale.Y * TileSize, 0.0f };

	DarkMap->SetActorScale3D(ImageScale);
	DarkMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 0.0f });
	
	// PlayerSet

}

void ADarkGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
