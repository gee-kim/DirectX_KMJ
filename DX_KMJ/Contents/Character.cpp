#include "PreCompile.h"
#include "Character.h"

ACharacter::ACharacter()
{
}

ACharacter::~ACharacter()
{
}


void ACharacter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (nullptr == Child)
	{
		return;
	}

	float4 Pos = GetActorLocation();


		if (20 <= PrevPos.size())
		{
			PrevPos.pop_front();
		}
		
		//링크 되기 전에 clear() 하면 front 없어서 오류남.
		//먼저 마지막 위치 push_back 시키고 들어오게 하려면?

	if (nullptr != Child)
	{
		if (0 == PrevPos.size())
		{
			return;
		}

		float4 CurPos = PrevPos.front();

		float Size = (GetActorLocation() - CurPos).Size2D();

		float4 Test = PrevPos.front();
		float Dis = 0.0f;

		for (float4& PrePos : PrevPos)
		{
			PrePos.X = PrePos.iroundX();
			PrePos.Y = PrePos.iroundY();
			Dis += (Test - PrePos).Size2D();
			Test = PrePos;
		}

		//if (60 != static_cast<int>(Dis))
		//{
		//	float ChangeDis = Dis - 60.0f;

		//	std::list<float4>::iterator Start0 = PrevPos.begin();
		//	std::list<float4>::iterator Start1 = ++PrevPos.begin();

		//	float4& Pre0 = *Start0;
		//	float4& Pre1 = *Start1;

		//	float4 Dir = Pre1 - Pre0;
		//	Pre0 += -Dir * ChangeDis;
		//}

		//Dis = 0.0f;
		//for (float4& PrePos : PrevPos)
		//{
		//	PrePos.X = PrePos.iroundX();
		//	PrePos.Y = PrePos.iroundY();
		//	Dis += (Test - PrePos).Size2D();
		//	Test = PrePos;
		//}

		int a = 0;
		{
			std::string Msg = std::format("Child Dis : {}\n", Dis);
			UEngineDebugMsgWindow::PushMsg(Msg);
		}

		Child->SetActorLocation(CurPos);
		//Child->State.Update(_DeltaTime);

		if (true == UEngineInput::IsFree('A') && true == IsFree('D') && true == IsFree('W') && true == IsFree('S'))
		{
			Child->State.ChangeState("Susie_Idle");
		}
		else if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
		{
			Child->State.ChangeState("Susie_Move");
		}

	}


	

//if (Dir == "_Right")
//{
//	Child->State.ChangeState("Susie_Idle");
//}
//else if (Dir == "_Left")
//{
//	Pos += float4::Right * 60.0f;
//}
//else if (Dir == "_Up")
//{
//	Pos += float4::Down * 60.0f;
//}
//else if (Dir == "_Down")
//{
//	Pos += float4::Up * 60.0f;
//}

float4 NextPos = float4::Lerp(GetActorLocation(), Pos, 0.5f);

SetActorLocation(NextPos);
// Child->SetActorLocation(Pos);

}