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
#include "Sign.h"

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
	
	//�� �ȵǳ�?
	if (true == UContentsConstValue::IsOpeningOff)
	{
		BGMPlayer = UEngineSound::SoundPlay("basement.ogg");
		int a = 0;
	}

	// DarkMap 
	std::shared_ptr<ADarkMap> DarkMap = GetWorld()->SpawnActor<ADarkMap>("DarkMap");

	// �ȼ��浹map
	UContentsConstValue::MapTex = UEngineTexture::FindRes("dark_colmap0.png");
	UContentsConstValue::MapTexScale = UContentsConstValue::MapTex->GetScale();

	float4 TexScale = UContentsConstValue::MapTexScale;
	float4 ImageScale = { TexScale.X , TexScale.Y, 0.0f };

	DarkMap->SetActorScale3D(ImageScale);
	DarkMap->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 0.0f });

	// ���� ����
	MyWidget* Widget = CreateWidget<MyWidget>(GetWorld(), "GameWidget");
	//Widget->SetTextScript("��ȣȣ �ؽ�Ʈ ���� �׽�Ʈ���\n�ؽ�Ʈ ���� �׽�Ʈ���");


	// PlayerSet
	std::shared_ptr<APlayer> Player = GetWorld()->SpawnActor<APlayer>("Player");
	Player->SetActorLocation(FVector(842.0f, -480.0f, 0.0f)); // start pos 
	//Player->SetActorLocation(FVector(3200.0f, -820.0f, 0.0f)); //wobbly pos
	//Player->SetActorLocation(FVector(6042.0f, -780.0f, 0.0f)); //gravity pos
	//Player->SetActorLocation(FVector(7370.0f, -1428.0f, 0.0f)); // monster
	//Player->SetActorLocation(FVector(6520.0f, -1230.0f, 0.0f)); // monster
	//Player->SetActorLocation(FVector(9111.0f, -1410.0f, 0.0f)); //eyepuzzle
	//Player->SetActorLocation(FVector(11250.0f, -1950.0f, 0.0f)); //susie




	// CameraSet
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector{ Player->GetActorLocation().X, Player->GetActorLocation().Y, -100.0f });

	//��� ��ġ
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

	//��� ���ݿ� ��ġ
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
		Wobbly->ZoneCheckCollisionOn();
	}

	// �ȳ��� ��ġ
	{
		std::shared_ptr<ASign> Sign = GetWorld()->SpawnActor<ASign>("Monster");
		Sign->SetActorLocation(FVector(9055.0f, -1240.0f, 0.0f));
		Sign->SetWidget(Widget);
	}

	// ��ũ���� ��ġ
	{
		std::shared_ptr<ADarkEye> DarkEye = GetWorld()->SpawnActor<ADarkEye>("Monster");
		DarkEye->SetActorLocation(FVector(9117.0f, -1240.0f, 0.0f));
	}

	// �������� ��ġ
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

	// �������� ��ġ
	{
		//std::shared_ptr<AMagicalGlass> MagicGlass = GetWorld()->SpawnActor<AMagicalGlass>("Monster");
		//MagicGlass->SetActorLocation(FVector(9642.5f, -1422.0f, 0.0f));

	}

	// �������� ��ġ
	{
		std::shared_ptr<ADustPile> DustPile = GetWorld()->SpawnActor<ADustPile>("Monster");
		DustPile->SetActorLocation(FVector(6520.0f, -1435.0f, 0.0f));

	}
	{
		std::shared_ptr<ADustPile> DustPile = GetWorld()->SpawnActor<ADustPile>("Monster");
		DustPile->SetActorLocation(FVector(11000.0f, -1935.0f, 0.0f));

	}
	{
		std::shared_ptr<ADustPile> DustPile = GetWorld()->SpawnActor<ADustPile>("Monster");
		DustPile->SetActorLocation(FVector(11100.0f, -1835.0f, 0.0f));

	}
	// susie ���� ��
	std::shared_ptr<ASusie> Susie;
	{
		//std::shared_ptr<ADustPile> DustPile = GetWorld()->SpawnActor<ADustPile>("Monster");
		//DustPile->SetActorLocation(FVector(11360.0f, -1965.0f, 0.0f));
		//DustPile->SetEventMode();

		Susie = GetWorld()->SpawnActor<ASusie>("SubChar");
		Susie->SetActorLocation(FVector(11360.0f, -1963.0f, 0.0f));

		DustBubble = GetWorld()->SpawnActor<ADustPile>("Monster");
		DustBubble->SetActorLocation(FVector(11360.0f, -1965.0f, 0.0f));
	}

	{
		// �̺�Ʈ ����
		std::shared_ptr<GameEvent> NewEvent = std::make_shared<GameEvent>();


		// �̺�Ʈ ��� ���۵Ǵ��� üũ �Լ� �����
		NewEvent->EventStartCheck = std::bind([=]()
			{
				static bool EventStart = false;

				Player->Collision->CollisionEnter(ECollisionOrder::SubChar, [&](std::shared_ptr<UCollision> _Collison)
					{
						EventStart = true;
					});

				return EventStart;
			});


		// �÷��̾�� ������ ó�� �������� �ϰ� ������
		NewEvent->State.CreateState("0");
		NewEvent->State.SetUpdateFunction("0", [=](float _Delta)
			{
				Player->State.ChangeState("Player_Event");
				Susie->Renderer->SetOrder(ERenderOrder::Susie_Bubble);
				Susie->Renderer->ChangeAnimation("Susie_shock");
				DustBubble->SetEventMode();
				NewEvent->State.ChangeState("1");
			}
		);
		// 1�� �� �ؽ�Ʈâ ���� ���
		NewEvent->State.CreateState("1");
		NewEvent->State.SetUpdateFunction("1", [=](float _Delta)
			{
				int a = 0;

				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (1.3f <= WaitTime)
				{

					Widget->SetTextBoxOn();
					Widget->SetFaceOn();
					Widget->SetTextScript("* ��! ��.. ������!\n* �� ������ �Դٰ� Ȯ...!");
					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						Widget->SetTextScript(" ");
						NewEvent->State.ChangeState("2");

					}
				}

			}
		);

		NewEvent->State.CreateState("2");
		NewEvent->State.SetUpdateFunction("2", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (0.5f <= WaitTime)
				{
					DustBubble->SetActive(false);
					Susie->Renderer->ChangeAnimation("Susie_Idle_Left");
					Widget->ChangeFace("Susie_Face_1");
					Widget->SetTextScript("* ...ũ...\n* ..ũ����?\n* �� ���n, �ʿ���...!");
					if (true == UEngineInput::IsDown(VK_SPACE))
					{

						NewEvent->State.ChangeState("3");

					}
				}
			}
		);

		NewEvent->State.CreateState("3");
		NewEvent->State.SetUpdateFunction("3", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (0.5f <= WaitTime)
				{
					Widget->SetTextScript("* ...������ ���� �����,\n* ��û��!");

					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						Widget->SetTextScript(" ");
						NewEvent->State.ChangeState("4");

					}
				}

			}
		);

		NewEvent->State.CreateState("4");
		NewEvent->State.SetUpdateFunction("4", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (0.5f <= WaitTime)
				{
					Widget->ChangeFace("Susie_Face_2");
					Widget->SetTextScript("* Ȯ ����\n* ����������.");

					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						Widget->SetTextScript(" ");
						NewEvent->State.ChangeState("5");

					}
				}

			}
		);

		NewEvent->State.CreateState("5");
		NewEvent->State.SetUpdateFunction("5", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (0.5f <= WaitTime)
				{
					Widget->ChangeFace("Susie_Face_3");
					Widget->SetTextScript("* ��¶��..\n*�ֱ��� �Ÿ��°� ������� �ϰ�,");

					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						NewEvent->State.ChangeState("6");

					}
				}

			}
		);

		NewEvent->State.CreateState("6");
		NewEvent->State.SetUpdateFunction("6", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (0.5f <= WaitTime)
				{
					//Widget->ChangeFace("Susie_Face_2");
					Widget->SetTextScript("* ���⼭ ���� ���� ã�ƺ���.");

					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						Widget->SetTextBoxOff();
						Susie->Renderer->ChangeAnimation("Susie_Idle_Right");
						NewEvent->State.ChangeState("7");

					}
				}

			}
		);

		NewEvent->State.CreateState("7");
		NewEvent->State.SetUpdateFunction("7", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (0.8f <= WaitTime)
				{
					Susie->Renderer->ChangeAnimation("Susie_Idle_Up");

					NewEvent->State.ChangeState("8");
				}
			}
		);

		NewEvent->State.CreateState("8");
		NewEvent->State.SetUpdateFunction("8", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (1.5f <= WaitTime)
				{
					Widget->SetTextBoxOn();
					Widget->SetFaceOn();
					Widget->ChangeFace("Susie_Face_1");
					Widget->SetTextScript("* ...���� ����ü ����?!\n* �츮 ����°ǵ�?..!");

					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						Widget->SetTextBoxOff();
						NewEvent->State.ChangeState("9");
					}
				}

			}
		);

		NewEvent->State.CreateState("9");
		NewEvent->State.SetUpdateFunction("9", [=](float _Delta)
			{
				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (1.5f <= WaitTime)
				{
					Widget->SetTextBoxOn();
					Widget->SetFaceOn();
					Susie->Renderer->ChangeAnimation("Susie_Idle_Left");
					Widget->ChangeFace("Susie_Face_0");
					Widget->SetTextScript("* �� �� ����!\n* �� ���� �̵� ���� ����������,\n* �װ� ������ �������!");


					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						Widget->SetTextBoxOff();
						Susie->Renderer->SetOrder(ERenderOrder::SubChar);
						NewEvent->State.ChangeState("10");

					}
				}

			}
		);

		NewEvent->State.CreateState("10");
		NewEvent->State.SetUpdateFunction("10", [=](float _Delta)
			{
				//������ ũ���� ���� �Ʒ��� �ɾ �����̱�.
				InputOff();
				Susie->Renderer->ChangeAnimation("Susie_Move_Left");
				Susie->AddActorLocation(Susie_Left * _Delta * Susie_Speed);

				static float WaitTime = 2.0f;
				WaitTime -= _Delta;
				if (0.0f >= WaitTime)
				{
					NewEvent->State.ChangeState("11");
				}

			}
		);

		NewEvent->State.CreateState("11");
		NewEvent->State.SetUpdateFunction("11", [=](float _Delta)
			{
				//������ ũ���� ���� �Ʒ��� �ɾ �����̱�.
				InputOn();
				Susie->Renderer->ChangeAnimation("Susie_Idle_Right");

				static float WaitTime = 0.0f;
				WaitTime += _Delta;
				if (0.8f <= WaitTime)
				{
					Widget->SetTextBoxOn();
					Widget->SetFaceOn();
					Widget->ChangeFace("Susie_Face_3");
					Widget->SetTextScript("* ���弭��, ũ����!");

					if (true == UEngineInput::IsDown(VK_SPACE))
					{
						Widget->SetTextBoxOff();
						NewEvent->State.ChangeState("12");
					}
				}

			}
		);


		NewEvent->State.CreateState("12");
		NewEvent->State.SetUpdateFunction("12", [=](float _Delta)
			{

				Player->State.ChangeState("Player_Idle");
				Susie->State.ChangeState("Susie_Idle");

				Player->PrevPos.clear();
				Player->Link(Susie.get());

				NewEvent->End();
				return;
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
		// ���� �������� �̺�Ʈ�� �ִ�.
		CurEvent->State.Update(_DeltaTime);

		if (CurEvent->IsEnd == true)
		{
			Events.remove(CurEvent);
			CurEvent = nullptr;
		}
	}
	else
	{
		// ���� �������� �̺�Ʈ�� ����.

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

// SusieEvent�� ������ ������?
// �÷��̾ �����ݸ����� ������ ? �����ݸ����� ���� ��?
void ADarkGameMode::SusieEvent(float _DeltaTime)
{



}