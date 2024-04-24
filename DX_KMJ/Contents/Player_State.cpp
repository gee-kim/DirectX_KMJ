#include "PreCompile.h"
#include "Player.h"

void APlayer::StateInit()
{

	Renderer->CreateAnimation("Kris_Act", "krisb_act", 0.1f); // ����

	Renderer->CreateAnimation("Kris_Move_Down", "kris_dark_down", 0.2f, true, (1, 2, 3, 0)); // �̵�
	Renderer->CreateAnimation("Kris_Move_Right", "kris_dark_right", 0.2f, true, (1, 2, 3, 0));
	Renderer->CreateAnimation("Kris_Move_Left", "kris_dark_left", 0.2f, true, (1, 2, 3, 0));
	Renderer->CreateAnimation("Kris_Move_Up", "kris_dark_up", 0.2f, true, (1, 2, 3, 0));

	Renderer->CreateAnimation("Kris_Idle_Down", "kris_dark_down", 0.0f, false, 0, 0); // ���ֱ�
	Renderer->CreateAnimation("Kris_Idle_Right", "kris_dark_right", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Kris_Idle_Left", "kris_dark_left", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Kris_Idle_Up", "kris_dark_up", 0.0f, false, 0, 0);

	Renderer->CreateAnimation("Hug", "kris_hug", 0.1f);
	Renderer->CreateAnimation("Kris_Fallen", "kris_fallen", 1.5f, false, 0, 2);
	Renderer->CreateAnimation("Kris_Drop", "kris_drop", 0.0f, false, 0, 0);
	



	// ������Ʈ �����
	State.CreateState("Player_Idle");
	State.CreateState("Player_Move");
	State.CreateState("Player_Attack");
	State.CreateState("Player_Fallen");

	State.CreateState("Player_FreeMove");
	State.CreateState("Player_Gravity");

	InputOn();


	USpriteRenderer* StateRenderer = Renderer;

	State.SetUpdateFunction("Player_Idle", std::bind(&APlayer::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Player_Idle", [=]()
		{
			DirAnimationChange("Kris_Idle");
		}
	);


	State.SetUpdateFunction("Player_Move", std::bind(&APlayer::Move, this, std::placeholders::_1));
	State.SetStartFunction("Player_Move", [=]()
		{
			DirAnimationChange("Kris_Move");
		}
	);
	
	State.SetUpdateFunction("Player_Fallen", std::bind(&APlayer::Fallen, this, std::placeholders::_1));
	State.SetStartFunction("Player_Fallen", [=]()
		{
			Renderer->ChangeAnimation("Kris_Fallen"); 
		}
	);

	State.SetUpdateFunction("Player_FreeMove", std::bind(&APlayer::FreeMove, this, std::placeholders::_1));
	State.SetStartFunction("Player_FreeMove", [=]()
		{
			DirAnimationChange("Kris_Idle");
		}
	);

	State.SetUpdateFunction("Player_Gravity", std::bind(&APlayer::Gravity, this, std::placeholders::_1));
	State.SetStartFunction("Player_Gravity", [=]()
		{
			Renderer->ChangeAnimation("Kris_Drop");
		}
	);
	
	State.ChangeState("Player_Fallen");
}

void APlayer::DirAnimationChange(std::string _AnimationName)
{
	if (true == IsPress('A'))
	{
		Dir = "_Left";
	}
	else if (true == IsPress('D'))
	{
		Dir = "_Right";
	}
	else if (true == IsPress('W'))
	{
		Dir = "_Up";
	}
	else if (true == IsPress('S'))
	{
		Dir = "_Down";
	}

	Renderer->ChangeAnimation(_AnimationName + Dir);
}

void APlayer::ColorCheck(float4 _NextPos)
{

	float4 PlayerNextPos = GetActorLocation() + _NextPos;

	std::shared_ptr<UEngineTexture> Tex = UContentsConstValue::MapTex;

#ifdef _DEBUG
	if (nullptr == Tex)
	{
		MsgBoxAssert("�̹��� �浹üũ�� �̹����� �������� �ʽ��ϴ�.");
	}
#endif

	float4 Pos = PlayerNextPos;

	Pos.Y = -Pos.Y;

	ColColor = Tex->GetColor(Pos, Color8Bit::Black);
	GravColor = Tex->GetColor(Pos, Color8Bit::Magenta);

}

void APlayer::Idle(float _DeltaTime)
{

	if (true == UEngineInput::IsDown('1'))
	{
		State.ChangeState("Player_FreeMove");
		return;
	}

	//if (true == UEngineInput::IsDown('2'))
	//{
	//	State.ChangeState("CameraFreeMove");
	//	return;
	//}

	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		State.ChangeState("Player_Move");
		return;
	}

}

void APlayer::Move(float _DeltaTime)
{
	GetWorld()->GetMainCamera()->SetActorLocation(GetActorLocation() + float4{ 0.0f, 0.0f, -100.0f });

	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		DirAnimationChange("Kris_Move");
	}

	if (true == UEngineInput::IsPress('A'))
	{
		ColorCheck(FVector::Left * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Left * _DeltaTime * Speed);
		}

		if (GravColor == Color8Bit::Magenta)
		{
			State.ChangeState("Player_Gravity");
		}
	}

	if (true == UEngineInput::IsPress('D'))
	{
		ColorCheck(FVector::Right * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Right * _DeltaTime * Speed);

		}

		if (GravColor == Color8Bit::Magenta)
		{
			State.ChangeState("Player_Gravity");
		}
	}

	if (true == UEngineInput::IsPress('W'))
	{

		ColorCheck(FVector::Up * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Up * _DeltaTime * Speed);
		}
		if (GravColor == Color8Bit::Magenta)
		{
			State.ChangeState("Player_Gravity");
		}
	}

	if (true == UEngineInput::IsPress('S'))
	{

		ColorCheck(FVector::Down * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Down * _DeltaTime * Speed);
		}
		if (GravColor == Color8Bit::Magenta)
		{
			State.ChangeState("Player_Gravity");
		}
	}

	if (true == UEngineInput::IsFree('A') && true == IsFree('D') && true == IsFree('W') && true == IsFree('S'))
	{
		State.ChangeState("Player_Idle");
		return;
	}


}

void APlayer::FreeMove(float _DeltaTime)
{
	GetWorld()->GetMainCamera()->SetActorLocation(GetActorLocation() + float4{ 0.0f, 0.0f, -100.0f });

	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddActorLocation(FVector::Left * _DeltaTime * FreeMoveSpeed);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddActorLocation(FVector::Right * _DeltaTime * FreeMoveSpeed);
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		AddActorLocation(FVector::Up* _DeltaTime* FreeMoveSpeed);
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		AddActorLocation(FVector::Down * _DeltaTime * FreeMoveSpeed);
	}

	if (UEngineInput::IsDown('2'))
	{
		State.ChangeState("Player_Idle");
	}
}

void APlayer::Fallen(float _DeltaTime)
{
	//fallen ���¿����� Ű�Է��� ���� �ʴ´�.
	InputOff();

	TimeCount -=_DeltaTime;
	if (0.0 >= TimeCount)
	{
		State.ChangeState("Player_Idle");
		InputOn();
	}

}

void APlayer::Gravity(float _DeltaTime)
{
	ColorCheck(FVector::Down * _DeltaTime * Speed);

	AddActorLocation(FVector::Down * _DeltaTime* DropSpeed);

	GetWorld()->GetMainCamera()->SetActorLocation(GetActorLocation() + float4{ 0.0f, 0.0f, -100.0f });

	if (GravColor != Color8Bit::Magenta)
	{
		State.ChangeState("Player_Idle");
	}

}

void APlayer::Attak(float _DeltaTime)
{

}
