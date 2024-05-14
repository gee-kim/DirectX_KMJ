#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Collision.h>
#include "HpWidget.h"

APlayer::APlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	HeartRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	HeartRenderer->SetupAttachment(Root);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(30.0f, 80.0f, 10.0f));
	Collision->AddPosition(FVector(0.0f, 40.0f, 0.0f));
	Collision->SetCollisionGroup(ECollisionOrder::Player);
	Collision->SetCollisionType(ECollisionType::Rect);


	InputOn();

}

APlayer::~APlayer()
{

}

void APlayer::BeginPlay()
{
	Super::BeginPlay();
	// 랜더가 이때 들어간간다.

	// Renderer->ChangeAnimation("Kris_Idle_Down");
	Renderer->SetOrder(ERenderOrder::Player);
	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetPivot(EPivot::BOT);


	HeartRenderer->SetOrder(ERenderOrder::Heart);
	HeartRenderer->SetAutoSize(0.8f, true);
	HeartRenderer->AddPosition(FVector{ 0.0f, 30.0f });
	//하트랜더러는 공격받는게 시작되면 SetActive ture 해줘야함.
	HeartRenderer->SetActive(false);

	StateInit();
}

void APlayer::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);

	//플레이어가 무브 중 PosCheck콜리전 체크
	Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			//PosCheck콜리젼과 만나면 bullet이랑 랜더러가 attack상태가 되도록 만들려면
			State.ChangeState("Player_Escape_Move");
			HeartRenderer->SetActive(true);

		}
	);

	Collision->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			State.ChangeState("Player_Escape_Move");
			HeartRenderer->SetActive(true);
		}
	);
	Collision->CollisionExit(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{


			if (2 <= UContentsConstValue::Count)
			{
				HpWidget->SetActive(false);
				
				State.ChangeState("Player_Idle");
				HeartRenderer->SetActive(false);

				//HpWidget->SetHpWidgetOff();

				int a = 0;
				UContentsConstValue::Count = 0;
				return;

			}
			++UContentsConstValue::Count;
		}
	);


	//플레이어가 무브 중 Bullet콜리전 체크 후 위젯 띄우기
	Collision->CollisionEnter(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{
			//Bullet콜리젼과 만나면 플레이어 떨림?, Hpbar위젯 on
			// 위젯 on은 최초 한번만 되고 hp down Count 세서 hp애니메이션 체인지 해줘야함.
			
				Renderer->AddPosition(FVector(5.f, 0.f));

				ShakeTime -= _DeltaTime;
				if (0.0f >= ShakeTime)
				{
					Renderer->AddPosition(FVector(-5.f, 0.f));
				}
			
				HpWidget = CreateWidget<AHpWidget>(GetWorld(),"HpWidget");

				HpWidget->SetActive(true);
				//HpWidget->SetHpWidgetOn();

		}
	);

	Collision->CollisionStay(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{
			//State.ChangeState("Player_Escape_Move");
			//HeartRenderer->SetActive(true);
		}
	);
	Collision->CollisionExit(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{

			//if (2 <= UContentsConstValue::Count)
			//{
			//	State.ChangeState("Player_Idle");
			//	HeartRenderer->SetActive(false);

			//	int a = 0;
			//	UContentsConstValue::Count = 0;
			//	return;

			//}
			//++UContentsConstValue::Count;
		}
	);



	DebugMessageFunction();
}

void APlayer::DebugMessageFunction()
{
	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("CameraPos : {}\n", GetWorld()->GetMainCamera()->GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}