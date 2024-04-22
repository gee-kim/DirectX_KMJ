#include "PreCompile.h"
#include "Player.h"

void APlayer::StateInit()
{

	Renderer->CreateAnimation("Kris_Act", "krisb_act", 0.1f); // 공격

	Renderer->CreateAnimation("Kris_Move_Down", "kris_dark_down", 0.2f, true, (1, 2, 3, 0)); // 이동
	Renderer->CreateAnimation("Kris_Move_Right", "kris_dark_right", 0.2f, true, (1, 2, 3, 0));
	Renderer->CreateAnimation("Kris_Move_Left", "kris_dark_left", 0.2f, true, (1, 2, 3, 0));
	Renderer->CreateAnimation("Kris_Move_Up", "kris_dark_up", 0.2f, true, (1, 2, 3, 0));

	Renderer->CreateAnimation("Kris_Idle_Down", "kris_dark_down", 0.0f, false, 0, 0); // 서있기
	Renderer->CreateAnimation("Kris_Idle_Right", "kris_dark_right", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Kris_Idle_Left", "kris_dark_left", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Kris_Idle_Up", "kris_dark_up", 0.0f, false, 0, 0);

	Renderer->CreateAnimation("Hug", "kris_hug", 0.1f);




	// 스테이트 만들고
	State.CreateState("Player_Idle");
	State.CreateState("Player_Move");
	State.CreateState("Player_Attack");

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

	State.ChangeState("Player_Idle");
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

void APlayer::ColorCheck(float _DeltaTime, float4 _NextPos)
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

	Color = Tex->GetColor(Pos, Color8Bit::Black);

}

void APlayer::Idle(float _DeltaTime)
{
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
		ColorCheck(_DeltaTime, FVector::Left * _DeltaTime * Speed);

		if (Color != Color8Bit::Black)
		{
			AddActorLocation(FVector::Left * _DeltaTime * Speed);
		}
	}

	if (true == UEngineInput::IsPress('D'))
	{
		ColorCheck(_DeltaTime, FVector::Right * _DeltaTime * Speed);

		if (Color != Color8Bit::Black)
		{
		AddActorLocation(FVector::Right * _DeltaTime * Speed);

		}
	}

	if (true == UEngineInput::IsPress('W'))
	{

		ColorCheck(_DeltaTime, FVector::Up * _DeltaTime * Speed);

		if (Color != Color8Bit::Black)
		{
			AddActorLocation(FVector::Up * _DeltaTime * Speed);
		}
	}

	if (true == UEngineInput::IsPress('S'))
	{

		ColorCheck(_DeltaTime, FVector::Down * _DeltaTime * Speed);

		if (Color != Color8Bit::Black)
		{
			AddActorLocation(FVector::Down * _DeltaTime * Speed);
		}
	}

	if (true == UEngineInput::IsFree('A') && true == IsFree('D') && true == IsFree('W') && true == IsFree('S'))
	{
		State.ChangeState("Player_Idle");
		return;
	}


}


void APlayer::Attak(float _DeltaTime)
{

}



