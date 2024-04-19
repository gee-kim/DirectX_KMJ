#include "PreCompile.h"
#include "PlayGameMode.h"
#include "Opening_BackGround.h"
#include <EngineCore/Camera.h>
#include "Player.h"

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

	std::shared_ptr<AOpening_BackGround> Back = GetWorld()->SpawnActor<AOpening_BackGround>("BackGround");

	float TileSize = UContentsConstValue::TileSize;
	float4 TeXScale = UContentsConstValue::MapTexScale;
	float4 ImageScale = { TeXScale.X * TileSize, TeXScale.Y * TileSize, 0.0f };

	Back->SetActorScale3D(ImageScale);
	Back->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 500.0f });

	std::shared_ptr<APlayer> Actor = GetWorld()->SpawnActor<APlayer>("Player");
	Actor->SetActorLocation({ 0.0f, 0.0f, 200.0f });



	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(ImageScale.hX(), -ImageScale.hY(), -100.0f));


}


void APlayGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}