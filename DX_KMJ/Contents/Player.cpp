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

			if (false == UContentsConstValue::IsSoundOn)
			{
				BGMPlayer2 = UEngineSound::SoundPlay("battle.ogg");
				BGMPlayer2.SetVolume(0.5f);
				UContentsConstValue::IsSoundOn = true;
			}

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
			if (true == UContentsConstValue::IsAttackEnd)
			{
				
				BGMPlayer2.Off();

				State.ChangeState("Player_Idle");
				HeartRenderer->SetActive(false);

				if (IsWidgetOn)
				{
					HpWidget->SetHpWidgetOff();
					UContentsConstValue::BulletCount = 0;

					IsWidgetOn = false;

					int a = 0;
				}

				return;
			}

			//if (2 <= UContentsConstValue::MonsterCount)
			//{
			//	//HpWidget->SetActive(false);
			//	
			//	State.ChangeState("Player_Idle");
			//	HeartRenderer->SetActive(false);

			//	//HpWidget->SetHpWidgetOff();

			//	int a = 0;
			//	UContentsConstValue::MonsterCount = 0;


			//	if (IsWidgetOn)
			//	{
			//		HpWidget->SetHpWidgetOff();
			//		UContentsConstValue::BulletCount = 0;

			//		IsWidgetOn = false;

			//		int a = 0;
			//	}

			//	return;

			//}
			//++UContentsConstValue::MonsterCount;
		}
	);


	//�÷��̾ ���� �� Bullet�ݸ��� üũ �� ���� ����
	Collision->CollisionEnter(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{
			BGMPlayer3 = UEngineSound::SoundPlay("snd_bump_ch1.wav");
			BGMPlayer3.SetVolume(1.5f);
			//Bullet�ݸ����� ������ �÷��̾� ����?, Hpbar���� on
			// ���� on�� ���� �ѹ��� �ǰ� hp down Count ���� hp�ִϸ��̼� ü���� �������.
			// dŰ�� �������� a ��ŭ ���� , A Ű���� üũ�ؼ� d �� ������
			if (true == IsPress('D'))
			{
				Renderer->AddPosition(FVector(-5.f, 0.f));
				HeartRenderer->AddPosition(FVector(-5.f, 0.f));
			}
			else if (true == IsPress('A'))
			{
				Renderer->AddPosition(FVector(5.f, 0.f));
				HeartRenderer->AddPosition(FVector(5.f, 0.f));
			}

			if (0 == UContentsConstValue::BulletCount)
			{
				HpWidget = CreateWidget<AHpWidget>(GetWorld(), "HpWidget");
				HpWidget->SetActive(true);

				IsWidgetOn = true;
			}
			else if (1 == UContentsConstValue::BulletCount)
			{
				HpWidget->ChangeNumber(1);

			}
			else if (2 == UContentsConstValue::BulletCount)
			{
				HpWidget->ChangeNumber(2);

			}
			else if (3 == UContentsConstValue::BulletCount)
			{
				HpWidget->ChangeNumber(3);

			}
			else if (4 == UContentsConstValue::BulletCount)
			{
				HpWidget->ChangeNumber(4);

			}
			else if (5 == UContentsConstValue::BulletCount)
			{
				HpWidget->ChangeNumber(5);

			}
			else if (6 == UContentsConstValue::BulletCount)
			{
				HpWidget->ChangeNumber(6);

			}
			else if (7 <= UContentsConstValue::BulletCount)
			{

				//���ӿ��� ȭ�� �߰� ���ش�.
				return;

			}

			++UContentsConstValue::BulletCount;
				
		}
	);

	Collision->CollisionStay(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{
			
		}
	);

	Collision->CollisionExit(ECollisionOrder::Bullet, [=](std::shared_ptr<UCollision> _Collison)
		{
			
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