#include "PreCompile.h"
#include "Player.h"
#include <EngineCore/Collision.h>

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
	Collision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	Collision->SetCollisionGroup(ECollisionOrder::Player);
	Collision->SetCollisionType(ECollisionType::CirCle);


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
	HeartRenderer->SetAutoSize(1.0f, true);
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
	
	//콜리전 체크
	Collision->CollisionEnter(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{
			State.ChangeState("Player_Escape");
		
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