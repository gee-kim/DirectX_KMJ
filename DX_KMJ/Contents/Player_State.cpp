#include "PreCompile.h"
#include "Player.h"

void APlayer::StateInit()
{

	Renderer->CreateAnimation("Kris_Act", "krisb_act", 0.1f); // 공격

	Renderer->CreateAnimation("Kris_Move_Down", "kris_dark_down", 0.2f, true); // 일반이동
	Renderer->CreateAnimation("Kris_Move_Right", "kris_dark_right", 0.2f, true);
	Renderer->CreateAnimation("Kris_Move_Left", "kris_dark_left", 0.2f, true);
	Renderer->CreateAnimation("Kris_Move_Up", "kris_dark_up", 0.2f, true);

	Renderer->CreateAnimation("Kris_Idle_Down", "kris_dark_down", 0.0f, false, 0, 0); // 서있기
	Renderer->CreateAnimation("Kris_Idle_Right", "kris_dark_right", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Kris_Idle_Left", "kris_dark_left", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Kris_Idle_Up", "kris_dark_up", 0.0f, false, 0, 0);

	Renderer->CreateAnimation("Kris_Heart_Down", "kris_heart_down", 0.2f, true, (1, 2, 3, 0)); // 도망칠 때 이동
	Renderer->CreateAnimation("Kris_Heart_Right", "kris_heart_right", 0.2f, true, (1, 2, 3, 0));
	Renderer->CreateAnimation("Kris_Heart_Left", "kris_heart_left", 0.2f, true, (1, 2, 3, 0));
	Renderer->CreateAnimation("Kris_Heart_Up", "kris_heart_up", 0.2f, true, (1, 2, 3, 0));

	Renderer->CreateAnimation("Kris_Heart_Idle_Down", "kris_heart_down", 0.0f, false, 0, 0 ); // 도망칠 때 서있기
	Renderer->CreateAnimation("Kris_Heart_Idle_Right", "kris_heart_right", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Kris_Heart_Idle_Left", "kris_heart_left", 0.0f, false, 0,0);
	Renderer->CreateAnimation("Kris_Heart_Idle_Up", "kris_heart_up", 0.0f, false, 0, 0);


	Renderer->CreateAnimation("Hug", "kris_hug", 0.1f);
	Renderer->CreateAnimation("Kris_Fallen", "kris_fallen", 1.5f, false, 0, 2);
	Renderer->CreateAnimation("Kris_Drop", "kris_drop", 0.0f, false, 0, 0);
	
	HeartRenderer->CreateAnimation("Kris_Heart", "kris_heartbeat", 0.4f, true);

	HeartRenderer->ChangeAnimation("Kris_Heart");


	// 스테이트 만들고
	State.CreateState("Player_Idle");
	State.CreateState("Player_Move");
	State.CreateState("Player_Attack");
	State.CreateState("Player_Fallen");

	State.CreateState("Player_FreeMove");
	State.CreateState("Player_Gravity");
	State.CreateState("Player_Escape_Move");
	State.CreateState("Player_Escape_Idle");

	State.CreateState("Player_Event");

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
	
	State.SetUpdateFunction("Player_Escape_Move", std::bind(&APlayer::Escape_Move, this, std::placeholders::_1));
	State.SetStartFunction("Player_Escape_Move", [=]()
		{
			DirAnimationChange("Kris_Heart");
		}
	);

	State.SetUpdateFunction("Player_Escape_Idle", std::bind(&APlayer::Escape_Idle, this, std::placeholders::_1));
	State.SetStartFunction("Player_Escape_Idle", [=]()
		{
			DirAnimationChange("Kris_Heart_Idle");
		}
	);

	State.SetUpdateFunction("Player_Event", std::bind(&APlayer::Event, this, std::placeholders::_1));
	State.SetStartFunction("Player_Event", [=]()
		{
			Renderer->ChangeAnimation("Kris_Idle_Right");
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
		MsgBoxAssert("이미지 충돌체크중 이미지가 존재하지 않습니다.");
	}
#endif

	float4 Pos = PlayerNextPos;

	Pos.Y = -Pos.Y;

	ColColor = Tex->GetColor(Pos, Color8Bit::Black);
	GravColor = Tex->GetColor(Pos, Color8Bit::Magenta);
	PassColor = Tex->GetColor(Pos, Color8Bit::Red);

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

void APlayer::MoveCheck(float4 _Dir)
{
	ColorCheck(_Dir);

	if (ColColor == Color8Bit::Black)
	{
		return;
	}

	if (ColColor == Color8Bit::Red && false == UContentsConstValue::IsMagicGlassOn)
	{
		return;
	}

	if (GravColor == Color8Bit::Magenta)
	{
		State.ChangeState("Player_Gravity");
	}

	AddActorLocation(_Dir);

	return;
}

void APlayer::Move(/*const APlayer* this,*/ float _DeltaTime)
{
	// 1초에 200을 간다.

	GetWorld()->GetMainCamera()->SetActorLocation(GetActorLocation() + float4{ 0.0f, 0.0f, -100.0f });

	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		static float PrevTIme = 1 / 60.0f;
		static float CurTime = PrevTIme;

		CurTime -= _DeltaTime;

		if (0.0f >= CurTime)
		{
			CurTime += PrevTIme;
			PrevPos.push_back(GetActorLocation());
		}
		DirAnimationChange("Kris_Move");
	}

	if (true == UEngineInput::IsPress('A'))
	{
		MoveCheck(FVector::Left * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('D'))
	{
		MoveCheck(FVector::Right * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('W'))
	{
		MoveCheck(FVector::Up * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('S'))
	{
		MoveCheck(FVector::Down * _DeltaTime * Speed);
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
	//fallen 상태에서는 키입력을 받지 않는다.
	InputOff();

	TimeCount -=_DeltaTime;
	if (0.0 >= TimeCount)
	{
		UEngineSound::SoundPlay("snd_wing_ch1.wav");
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

void APlayer::Escape_Move(float _DeltaTime)
{
	GetWorld()->GetMainCamera()->SetActorLocation(GetActorLocation() + float4{ 0.0f, 0.0f, -100.0f });
	
	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		DirAnimationChange("Kris_Heart");
	}

	if (true == UEngineInput::IsPress('A'))
	{
		ColorCheck(FVector::Left * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Left * _DeltaTime * Speed);
		}

	}

	if (true == UEngineInput::IsPress('D'))
	{
		ColorCheck(FVector::Right * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Right * _DeltaTime * Speed);

		}

	}

	if (true == UEngineInput::IsPress('W'))
	{

		ColorCheck(FVector::Up * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Up * _DeltaTime * Speed);
		}
		
	}

	if (true == UEngineInput::IsPress('S'))
	{

		ColorCheck(FVector::Down * _DeltaTime * Speed);

		if (ColColor != Color8Bit::Black)
		{
			AddActorLocation(FVector::Down * _DeltaTime * Speed);
		}
		
	}

	if (true == UEngineInput::IsFree('A') && true == IsFree('D') && true == IsFree('W') && true == IsFree('S'))
	{
		State.ChangeState("Player_Escape_Idle");
		return;
	}


	/*Renderer->ChangeAnimation("Kris_Heart_Right");
	HeartRenderer->SetActive(true);*/

}

void APlayer::Escape_Idle(float _DeltaTime)
{

	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		State.ChangeState("Player_Escape_Move");
		return;
	}

}


void APlayer::Event(float _DeltaTime)
{

}


