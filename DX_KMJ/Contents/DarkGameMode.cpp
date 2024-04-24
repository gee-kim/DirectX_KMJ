#include "PreCompile.h"
#include "DarkGameMode.h"
#include "DarkMap.h"
#include "Player.h"
#include "Wobbly_Monster.h"

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
	
	// 픽셀충돌map
	UContentsConstValue::MapTex = UEngineTexture::FindRes("dark_colmap0.png");
	UContentsConstValue::MapTexScale = UContentsConstValue::MapTex->GetScale();
	
	float4 TexScale = UContentsConstValue::MapTexScale;
	float4 ImageScale = { TexScale.X , TexScale.Y, 0.0f };

	DarkMap->SetActorScale3D(ImageScale);
	DarkMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 0.0f });
	

	// PlayerSet
	std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
	Player->SetActorLocation(FVector(842.0f, -480.0f, 0.0f)); // start pos 
	//Player->SetActorLocation(FVector(6042.0f, -780.0f, 0.0f)); //gravity pos
	//Player->SetActorLocation(FVector(3195.0f, -635.0f, 0.0f)); // monster
	

	// CameraSet
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector{Player->GetActorLocation().X, Player->GetActorLocation().Y, -100.0f});

	//우블리 몬스터 배치

	std::shared_ptr<AWobbly_Monster> Wobbly0 = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
	Wobbly0->SetActorLocation(FVector(3200.0f, -620.0f, 0.0f));

	std::shared_ptr<AWobbly_Monster> Wobbly1 = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
	Wobbly1->SetActorLocation(FVector(3465.0f, -580.0f, 0.0f));
	//Wobbly1->DelayCallBack(0.5f,);

	std::shared_ptr<AWobbly_Monster> Wobbly2 = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
	Wobbly2->SetActorLocation(FVector(4692.0f, -485.0f, 0.0f));

	std::shared_ptr<AWobbly_Monster> Wobbly3 = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
	Wobbly3->SetActorLocation(FVector(4950.0f, -505.0f, 0.0f));

	std::shared_ptr<AWobbly_Monster> Wobbly4 = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
	Wobbly4->SetActorLocation(FVector(5211.0f, -443.0f, 0.0f));

	std::shared_ptr<AWobbly_Monster> Wobbly5 = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
	Wobbly5->SetActorLocation(FVector(5626.0f, -475.0f, 0.0f));

}


void ADarkGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	
}
