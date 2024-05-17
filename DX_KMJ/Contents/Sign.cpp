#include "PreCompile.h"
#include "Sign.h"


ASign::ASign()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Collision = CreateDefaultSubObject<UCollision>("Collisioin");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(50.0f, 50.0f, 50.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision->SetCollisionGroup(ECollisionOrder::Check);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);

}

ASign::~ASign()
{
}

void ASign::BeginPlay()
{
	Super::BeginPlay();


}

void ASign::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Collision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
		
		});

	Collision->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			static bool IsSignPlayed = false;

			if (true == UEngineInput::IsDown(VK_SPACE) && false == IsSignPlayed)
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Widget->SetTextBoxOn();
				Widget->SetTextScript("* 이곳에선, 어둠에 눈이 먼 자들만이\n   길을 볼 수 있다... ");
				Widget->SetTextBoxPos(FVector(-250.0f, 310.0f));

				IsSignPlayed = true;
				
			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == IsSignPlayed)
			{
				Widget->SetTextBoxOff();

				IsSignPlayed = false;
				//ContentsConstValue::IsSignOn = false;
			}

		});
}