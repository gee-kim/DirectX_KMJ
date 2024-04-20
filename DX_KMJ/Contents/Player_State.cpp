#include "PreCompile.h"
#include "Player.h"
#include <xmemory>

void APlayer::StateInit()
{
	// 스테이트 만들고
	State.CreateState("Player_Idle");
	State.CreateState("Player_Move");
	State.CreateState("Player_Attack");

	InputOn();

	State.SetUpdateFunction("Player_Idle", std::bind(&APlayer::Idle, this, std::placeholders::_1));

	USpriteRenderer* StateRenderer = Renderer;

	State.SetStartFunction("Player_Idle", [=]
		{
			StateRenderer->ChangeAnimation("Player_Idle");
		}
	);
}
void APlayer::Idle(float _DeltaTime)
{
	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		State.ChangeState("Player_Move");
		return;
	}
}

void APlayer::MoveStart()
{

}
void APlayer::Move(float _DeltaTime)
{

	if (true == UEngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('W'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}

	if (true == UEngineInput::IsPress('S'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}

}

void APlayer::AttakStart()
{

}
void APlayer::Attak(float _DeltaTime)
{

}



