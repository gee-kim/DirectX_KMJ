#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Player.h"
#include "BackGround.h"
#include <EngineCore/Camera.h>

APlayGameMode::APlayGameMode()
{
}

APlayGameMode::~APlayGameMode()
{
}

void APlayGameMode::BeginPlay()
{
	Super::BeginPlay();

	UContentsConstValue::MapTex = UEngineTexture::FindRes("bg_torhouse_bg_ch1_0.png");
	UContentsConstValue::MapTexScale = UContentsConstValue::MapTex->GetScale();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	GetWorld()->SpawnActor<APlayer>("Player");

	std::shared_ptr<ABackGround> Back = GetWorld()->SpawnActor<ABackGround>("PlayBackGround");

	float TileSize = UContentsConstValue::TileSize;
	float4 TeXScale = UContentsConstValue::MapTexScale;
	float4 ImageScale = { TeXScale.X * TileSize, TeXScale.Y * TileSize, 0.0f };

	Back->SetActorScale3D(ImageScale);
	Back->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });


}


void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}