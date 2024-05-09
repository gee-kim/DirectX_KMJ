#include "PreCompile.h"
#include "Susie.h"
#include "DustPile.h"
#include "Player.h"

ASusie::ASusie()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(140.0f, 100.0f, 10.0f));
	Collision->AddPosition(FVector(0.0f, 40.0f, 0.0f));
	Collision->SetCollisionGroup(ECollisionOrder::SubChar);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);
}

ASusie::~ASusie()
{
}

void ASusie::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetOrder(ERenderOrder::SubChar);
	Renderer->SetAutoSize(2.0f, true);
	Renderer->SetPivot(EPivot::BOT);

	StateInit();

}

void ASusie::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
}

void ASusie::StateInit()
{
	InputOn();

	Renderer->CreateAnimation("Susie_shock", "susie_buble", 0.0f, false);

	Renderer->CreateAnimation("Susie_Move_Down", "susie_down", 0.2f, true); //일반이동
	Renderer->CreateAnimation("Susie_Move_Right", "susie_right", 0.2f, true);
	Renderer->CreateAnimation("Susie_Move_Left", "susie_left", 0.2f, true);
	Renderer->CreateAnimation("Susie_Move_UP", "susie_up", 0.2f, true);

	Renderer->CreateAnimation("Susie_Idle_Down", "susie_down", 0.0f, false, 0, 0); // 정지 시
	Renderer->CreateAnimation("Susie_Idle_Right", "susie_right", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Susie_Idle_Left", "susie_left", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Susie_Idle_UP", "susie_up", 0.0f, false, 0, 0);

	//Renderer->ChangeAnimation("Susie_shock");

	State.CreateState("Susie_Idle");
	State.CreateState("Susie_Move");
	State.CreateState("Susie_EventMode");

	USpriteRenderer* StateRenderer = Renderer;

	State.SetUpdateFunction("Susie_Idle", std::bind(&ASusie::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Susie_Idle", [=]()
		{
			DirAnimationChange("Susie_Idle");
		}
	);


	State.SetUpdateFunction("Susie_Move", std::bind(&ASusie::Move, this, std::placeholders::_1));
	State.SetStartFunction("Susie_Move", [=]()
		{
			DirAnimationChange("Susie_Move");
		}
	);

	State.SetUpdateFunction("Susie_EventMode", std::bind(&ASusie::EventMode, this, std::placeholders::_1));
	State.SetStartFunction("Susie_EventMode", [=]()
		{

		}
	);

	State.ChangeState("Susie_EventMode");
}

void ASusie::DirAnimationChange(std::string _AnimationName)
{
	//if (true == IsPress('A'))
	//{
	//	Dir = "_Left";
	//}
	//else if (true == IsPress('D'))
	//{
	//	Dir = "_Right";
	//}
	//else if (true == IsPress('W'))
	//{
	//	Dir = "_Up";
	//}
	//else if (true == IsPress('S'))
	//{
	//	Dir = "_Down";
	//}

	Renderer->ChangeAnimation(_AnimationName + Dir);

}

void ASusie::Idle(float _DeltaTime)
{
	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		State.ChangeState("Susie_Move");
		return;
	}
}

void ASusie::Move(float _DeltaTime)
{
	if (true == UEngineInput::IsFree('A') && true == IsFree('D') && true == IsFree('W') && true == IsFree('S'))
	{
		State.ChangeState("Susie_Idle");
		return;
	}
}

void ASusie::EventMode(float _DeltaTime)
{
	InputOff();

}
