#include "PreCompile.h"
#include "DarkGameMode.h"
#include "DarkMap.h"
#include "Player.h"
#include "Wobbly.h"
#include "Wobbly_Monster.h"
#include "Wobbly_Bullet.h"
#include "EyePuzzle.h"
#include "DarkEye.h"
#include "MagicalGlass.h"
#include "DustPile.h"

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
	//Player->SetActorLocation(FVector(842.0f, -480.0f, 0.0f)); // start pos 
	//Player->SetActorLocation(FVector(3200.0f, -820.0f, 0.0f)); //wobbly pos
	//Player->SetActorLocation(FVector(6042.0f, -780.0f, 0.0f)); //gravity pos
	//Player->SetActorLocation(FVector(7370.0f, -1428.0f, 0.0f)); // monster
	Player->SetActorLocation(FVector(9111.0f, -1410.0f, 0.0f)); //eyepuzzle
	//Player->SetActorLocation(FVector(6520.0f, -1230.0f, 0.0f)); // monster

	

	// CameraSet
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector{Player->GetActorLocation().X, Player->GetActorLocation().Y, -100.0f});

	//우블리 배치
	{
		std::shared_ptr<AWobbly> Wobbly = GetWorld()->SpawnActor<AWobbly>("Monster");
		Wobbly->SetActorLocation(FVector(3200.0f, -620.0f, 0.0f));
	}

	{
		std::shared_ptr<AWobbly> Wobbly = GetWorld()->SpawnActor<AWobbly>("Monster");
		Wobbly->SetActorLocation(FVector(3465.0f, -580.0f, 0.0f));

	}

	{
		std::shared_ptr<AWobbly> Wobbly = GetWorld()->SpawnActor<AWobbly>("Monster");
		Wobbly->SetActorLocation(FVector(4692.0f, -485.0f, 0.0f));
	}

	{
		std::shared_ptr<AWobbly> Wobbly = GetWorld()->SpawnActor<AWobbly>("Monster");
		Wobbly->SetActorLocation(FVector(4950.0f, -505.0f, 0.0f));
	}

	{
		std::shared_ptr<AWobbly> Wobbly = GetWorld()->SpawnActor<AWobbly>("Monster");
		Wobbly->SetActorLocation(FVector(5211.0f, -510.0f, 0.0f));

	}

	{
		std::shared_ptr<AWobbly> Wobbly = GetWorld()->SpawnActor<AWobbly>("Monster");
		Wobbly->SetActorLocation(FVector(5626.0f, -475.0f, 0.0f));

	}

	//우블리 공격용 배치
	{
		std::shared_ptr<AWobbly_Monster> Wobbly = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
		Wobbly->SetActorLocation(FVector(7558.0f, -1188.0f, 0.0f));
	}

	{
		std::shared_ptr<AWobbly_Monster> Wobbly = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
		Wobbly->SetActorLocation(FVector(7999.0f, -1188.0f, 0.0f));
	}

	{
		std::shared_ptr<AWobbly_Monster> Wobbly = GetWorld()->SpawnActor<AWobbly_Monster>("Monster");
		Wobbly->SetActorLocation(FVector(8438.0f, -1188.0f, 0.0f));
	}

	// 다크아이 배치
	{
		std::shared_ptr<ADarkEye> DarkEye = GetWorld()->SpawnActor<ADarkEye>("Monster");
		DarkEye->SetActorLocation(FVector(9117.0f, -1240.0f, 0.0f));
	}
	{
		std::shared_ptr<ADarkEye> DarkEye = GetWorld()->SpawnActor<ADarkEye>("Monster");
		DarkEye->SetActorLocation(FVector(9247.0f, -1240.0f, 0.0f));
	}
	{
		std::shared_ptr<ADarkEye> DarkEye = GetWorld()->SpawnActor<ADarkEye>("Monster");
		DarkEye->SetActorLocation(FVector(9377.0f, -1240.0f, 0.0f));
	}

	// 아이퍼즐 배치
	{
		std::shared_ptr<AEyePuzzle> EyePuzzle = GetWorld()->SpawnActor<AEyePuzzle>("Monster");
		EyePuzzle->SetActorLocation(FVector(9117.0f, -1295.0f, 0.0f));
		EyePuzzle->ChangeAnimation("EyePuzzle_1");
	}
	{
		std::shared_ptr<AEyePuzzle> EyePuzzle = GetWorld()->SpawnActor<AEyePuzzle>("Monster");
		EyePuzzle->SetActorLocation(FVector(9247.5f, -1295.0f, 0.0f));
		EyePuzzle->ChangeAnimation("EyePuzzle_2");
	}
	{
		std::shared_ptr<AEyePuzzle> EyePuzzle = GetWorld()->SpawnActor<AEyePuzzle>("Monster");
		EyePuzzle->SetActorLocation(FVector(9377.0f, -1295.0f, 0.0f));
		EyePuzzle->ChangeAnimation("EyePuzzle_3");
	}

	// 매직유리 배치
	{
		std::shared_ptr<AMagicalGlass> MagicGlass = GetWorld()->SpawnActor<AMagicalGlass>("Monster");
		MagicGlass->SetActorLocation(FVector(9642.5f, -1422.0f, 0.0f));

	}

	// 먼지구름 배치
	{
		std::shared_ptr<ADustPile> DustPile = GetWorld()->SpawnActor<ADustPile>("Monster");
		DustPile->SetActorLocation(FVector(6520.0f, -1435.0f, 0.0f));
	}
	
}


void ADarkGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	
}
