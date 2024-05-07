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
#include "Susie.h"

#include <EngineCore/Camera.h>
#include "MyWidget.h"
#include <EngineCore/StateManager.h>

void GameEvent::Next()
{
	++CurState;
	std::string Text = std::to_string(CurState);
	State.ChangeState(Text);
}

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
	
	// 위젯 셋팅
	MyWidget* Widget = CreateWidget<MyWidget>(GetWorld(), "GameWidget");
	//Widget->SetText("오호호 텍스트 변경 테스트라네\n텍스트 변경 테스트라네");

	
	// PlayerSet
	std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
	//Player->SetActorLocation(FVector(842.0f, -480.0f, 0.0f)); // start pos 
	//Player->SetActorLocation(FVector(3200.0f, -820.0f, 0.0f)); //wobbly pos
	//Player->SetActorLocation(FVector(6042.0f, -780.0f, 0.0f)); //gravity pos
	//Player->SetActorLocation(FVector(7370.0f, -1428.0f, 0.0f)); // monster
	//Player->SetActorLocation(FVector(6520.0f, -1230.0f, 0.0f)); // monster
	//Player->SetActorLocation(FVector(9111.0f, -1410.0f, 0.0f)); //eyepuzzle
	Player->SetActorLocation(FVector(11250.0f, -1950.0f, 0.0f)); //susie


	

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
	//{
	//	std::shared_ptr<ADarkEye> DarkEye = GetWorld()->SpawnActor<ADarkEye>("Monster");
	//	DarkEye->SetActorLocation(FVector(9247.0f, -1240.0f, 0.0f));
	//}
	//{
	//	std::shared_ptr<ADarkEye> DarkEye = GetWorld()->SpawnActor<ADarkEye>("Monster");
	//	DarkEye->SetActorLocation(FVector(9377.0f, -1240.0f, 0.0f));
	//}

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
		//std::shared_ptr<AMagicalGlass> MagicGlass = GetWorld()->SpawnActor<AMagicalGlass>("Monster");
		//MagicGlass->SetActorLocation(FVector(9642.5f, -1422.0f, 0.0f));

	}

	// 먼지구름 배치
	{
		std::shared_ptr<ADustPile> DustPile = GetWorld()->SpawnActor<ADustPile>("Monster");
		DustPile->SetActorLocation(FVector(6520.0f, -1435.0f, 0.0f));
	}
	
	// susie 등장 씬
	std::shared_ptr<ASusie> Susie;
	{
		//std::shared_ptr<ADustPile> DustPile = GetWorld()->SpawnActor<ADustPile>("Monster");
		//DustPile->SetActorLocation(FVector(11360.0f, -1965.0f, 0.0f));
		//DustPile->SetEventMode();

		Susie = GetWorld()->SpawnActor<ASusie>("SubChar");
		Susie->SetActorLocation(FVector(11360.0f, -1963.0f, 0.0f));
	}

	{
		// 이벤트 생성
		std::shared_ptr<GameEvent> NewEvent = std::make_shared<GameEvent>();

		// 이벤트 어떻게 시작되는지 체크 함수 만들기
		NewEvent->EventStartCheck = std::bind([=]()
			{
				static bool EventStart = false;

				Player->Collision->CollisionEnter(ECollisionOrder::SubChar, [&](std::shared_ptr<UCollision> _Collison)
					{
						EventStart = true;
					});

				return EventStart;
			});

		// 플레이어와 수지가 처음 만났을때 하고 싶은일
		NewEvent->State.CreateState("0");
		NewEvent->State.SetUpdateFunction("0", [=](float _Delta)
			{
				Player->State.ChangeState("Player_Event");
				Susie->Renderer->SetOrder(ERenderOrder::Susie_Bubble);
				Susie->Renderer->ChangeAnimation("Susie_shock");
				Susie->DustPile->SetEventMode();
				NewEvent->State.ChangeState("1");
			}
		);

		NewEvent->State.CreateState("1");
		NewEvent->State.SetUpdateFunction("1", [=](float _Delta)
			{
				int a = 0;

				//static float WaitTime = 0.0f;
				//WaitTime += _Delta;
				//if (1.0f >= WaitTime)
				//{
				//	NewEvent->State.ChangeState("2");
				//}

				// 텍스트창 킨다
			}
		);

		NewEvent->State.CreateState("2");
		NewEvent->State.SetUpdateFunction("2", [=](float _Delta)
			{
				// 텍스트에 대사 친다.
			}
		);


		Events.push_back(NewEvent);
	}
}


void ADarkGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	
	if (nullptr != CurEvent)
	{
		// 현재 실행중인 이벤트가 있다.
		CurEvent->State.Update(_DeltaTime);
	}
	else
	{
		// 현재 실행중인 이벤트가 없다.

		for (std::shared_ptr<GameEvent> Event : Events)
		{
			if (true == Event->EventStartCheck())
			{
				Event->Next();
				CurEvent = Event;
				break;
			}
			
		}
	}

}

// SusieEvent로 들어오는 조건은?
// 플레이어가 버블콜리젼과 닿을때 ? 수지콜리젼과 닿을 때?
void ADarkGameMode::SusieEvent(float _DeltaTime)
{
	Script.push_back("* 야! 무.. 물러서!\n* 더 가까이 왔다간 확...!");
	Script.push_back("* ...크...\n* ..크리스?\n* 뭐 뭐냣, 너였냐...!");
	Script.push_back("* ...무섭게 하지 말라고,\n*멍청아!");
	Script.push_back("* 확 얼굴을\n*뭉개버릴라.");
	Script.push_back("* 어쨋든..\n*밍기적 거리는건 여기까지 하고,");
	Script.push_back("* ...여기 도대체 뭐냐?\n* 우리 어딨는건데?..!");



}