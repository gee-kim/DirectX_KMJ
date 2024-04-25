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
	// ������ �̶� ������.

	// Renderer->ChangeAnimation("Kris_Idle_Down");
	Renderer->SetOrder(ERenderOrder::Player);
	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetPivot(EPivot::BOT);

	HeartRenderer->SetOrder(ERenderOrder::Heart);
	HeartRenderer->SetAutoSize(1.0f, true);
	HeartRenderer->AddPosition(FVector{ 0.0f, 30.0f });
	//��Ʈ�������� ���ݹ޴°� ���۵Ǹ� SetActive ture �������.
	HeartRenderer->SetActive(false);

	StateInit();
}

void APlayer::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
	
	//�ݸ��� üũ
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