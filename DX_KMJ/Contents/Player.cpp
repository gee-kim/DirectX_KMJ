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
	// ������ �̶� ������.

	// Renderer->ChangeAnimation("Kris_Idle_Down");
	Renderer->SetOrder(ERenderOrder::Player);
	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetPivot(EPivot::BOT);


	HeartRenderer->SetOrder(ERenderOrder::Heart);
	HeartRenderer->SetAutoSize(0.8f, true);
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

	//�÷��̾ ���� �� PosCheck�ݸ��� üũ
	Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
		{
			//PosCheck�ݸ����� ������ bullet�̶� �������� attack���°� �ǵ��� �������
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


	//�÷��̾ ���� �� Bullet�ݸ��� üũ �� ���� ����
	Collision->CollisionEnter(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{
			//Bullet�ݸ����� ������ �÷��̾� ����?, Hpbar���� on
			// ���� on�� ���� �ѹ��� �ǰ� hp down Count ���� hp�ִϸ��̼� ü���� �������.
			
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