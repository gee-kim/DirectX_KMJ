#include "PreCompile.h"
#include "Susie.h"
#include "DustPile.h"
#include "Player.h"

ASusie::ASusie()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(140.0f, 100.0f, 10.0f));
	Collision->AddPosition(FVector(0.0f, 40.0f, 0.0f));
	Collision->SetCollisionGroup(ECollisionOrder::SubChar);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);
}

ASusie::~ASusie()
{
}

void ASusie::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetOrder(ERenderOrder::SubChar);
	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetPivot(EPivot::BOT);

	StateInit();

}

void ASusie::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
}

void ASusie::StateInit()
{
	InputOn();

	Renderer->CreateAnimation("Susie_shock", "susie_buble", 0.0f, false);

	Renderer->CreateAnimation("Susie_Move_Down", "susie_down", 0.2f, true); //일반이동
	Renderer->CreateAnimation("Susie_Move_Right", "susie_right", 0.2f, true);
	Renderer->CreateAnimation("Susie_Move_Left", "susie_left", 0.2f, true);
	Renderer->CreateAnimation("Susie_Move_UP", "susie_up", 0.2f, true);

	Renderer->CreateAnimation("Susie_Idle_Down", "susie_down", 0.0f, false, 0, 0); // 정지 시
	Renderer->CreateAnimation("Susie_Idle_Right", "susie_right", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Susie_Idle_Left", "susie_left", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Susie_Idle_UP", "susie_up", 0.0f, false, 0, 0);

	//Renderer->ChangeAnimation("Susie_shock");

	State.CreateState("Susie_Idle");
	State.CreateState("Susie_Move");
	State.CreateState("Susie_EventMode");


	USpriteRenderer* StateRenderer = Renderer;

	State.SetUpdateFunction("Susie_Idle", std::bind(&ASusie::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Susie_Idle", [=]()
		{
			//DirAnimationChange("Kris_Idle");
		}
	);


	State.SetUpdateFunction("Susie_Move", std::bind(&ASusie::Move, this, std::placeholders::_1));
	State.SetStartFunction("Susie_Move", [=]()
		{
			//DirAnimationChange("Kris_Move");
		}
	);

	State.SetUpdateFunction("Susie_EventMode", std::bind(&ASusie::EventMode, this, std::placeholders::_1));
	State.SetStartFunction("Susie_EventMode", [=]()
		{
			
		}
	);

	State.ChangeState("Susie_EventMode");
}


void ASusie::Idle(float _DeltaTime)
{

	Collision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
			{

			AActor* Owner = _Col->GetActor();

			Player = dynamic_cast<APlayer*>(Owner);

			if (nullptr == Player)
			{
				MsgBoxAssert("플레이어가 아닙니다.");
			}
			SetActorLocation(Player->GetActorLocation());
		}
		);

	//if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	//{
	//	State.ChangeState("Susie_Move");
	//	return;
	//}
}

void ASusie::Move(float _DeltaTime)
{

}

void ASusie::EventMode(float _DeltaTime)
{
	InputOff();

	//Renderer->SetOrder(ERenderOrder::Susie_Bubble);

	//// 수지의 콜리젼과 플레이어가 만나게 되면 
	//Collision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
	//	{
	//		Renderer->ChangeAnimation("Susie_shock");
	//		DustPile->SetEventMode();
	//	}
	//);

	//// 키입력 체크해서 이벤트 단계 하나씩 진행
	//Collision->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
	//	{
	//		// 플레이어 조작 안되게 하고싶음
	//		AActor* Owner = _Col->GetActor();

	//		Player = dynamic_cast<APlayer*>(Owner);

	//		if (nullptr == Player)
	//		{
	//			MsgBoxAssert("플레이어가 아닙니다.");
	//		}

	//		Player->State.ChangeState("Player_Event");

	//		//_Col->GetActor()->AddActorLocation(FVector::Zero);

	//		if (true == UEngineInput::IsDown(VK_SPACE))
	//		{
	//			DustPile->SetActive(false);
	//			Renderer->ChangeAnimation("Susie_Idle_Left");

	//		}
	//		//DustPile->SetEventMode();
	//	}
	//);

	////
	//Collision->CollisionExit(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
	//	{

	//		Renderer->ChangeAnimation("Susie_Move_Right");
	//		//State.ChangeState("Susie_Idle");
	//	});

}
