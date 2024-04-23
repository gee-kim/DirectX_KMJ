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
	
	// DarkMap 
	std::shared_ptr<ADarkMap> DarkMap = GetWorld()->SpawnActor<ADarkMap>("DarkMap");
	
	// ÇÈ¼¿Ãæµ¹map
	UContentsConstValue::MapTex = UEngineTexture::FindRes("dark_colmap0.png");
	UContentsConstValue::MapTexScale = UContentsConstValue::MapTex->GetScale();
	
	float4 TexScale = UContentsConstValue::MapTexScale;
	float4 ImageScale = { TexScale.X , TexScale.Y, 0.0f };

	DarkMap->SetActorScale3D(ImageScale);
	DarkMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 0.0f });
	

	// PlayerSet
	std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
	//Player->SetActorLocation(FVector(842.0f, -480.0f, 0.0f));
	Player->SetActorLocation(FVector(6042.0f, -780.0f, 0.0f));

	// CameraSet
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector{Player->GetActorLocation().X, Player->GetActorLocation().Y, -100.0f});

}


void ADarkGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	
}
