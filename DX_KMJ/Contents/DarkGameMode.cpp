#include "PreCompile.h"
#include "DarkGameMode.h"
#include "DarkMap.h"
#include "Player.h"
#include "DarkMap_Col.h"

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
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -200.0f));

	// DarkMap 
	std::shared_ptr<ADarkMap> DarkMap = GetWorld()->SpawnActor<ADarkMap>("DarkMap");
	
	UContentsConstValue::MapTex = UEngineTexture::FindRes("Dark_Map.png");
	UContentsConstValue::MapTexScale = UContentsConstValue::MapTex->GetScale();
	
	float TileSize = 1.0f;

	float4 TexScale = UContentsConstValue::MapTexScale;
	float4 ImageScale = { TexScale.X * TileSize, TexScale.Y * TileSize, 0.0f };

	DarkMap->SetActorScale3D(ImageScale);
	DarkMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 0.0f });
	
	// ÇÈ¼¿Ãæµ¹map
	std::shared_ptr<ADarkMap_Col> DarkColMap = GetWorld()->SpawnActor<ADarkMap_Col>("DarkMap_Col");

	DarkColMap->SetActorScale3D(ImageScale);
	DarkColMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 100.0f });

	// PlayerSet

}

void ADarkGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
