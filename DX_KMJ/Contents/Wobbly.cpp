#include "PreCompile.h"
#include "Wobbly.h"

AWobbly::AWobbly()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	CheckCollision = CreateDefaultSubObject<UCollision>("Collision");
	CheckCollision->SetupAttachment(Root);
	CheckCollision->SetScale(FVector(200.0f, 200.0f, 50.0f));
	CheckCollision->AddPosition(FVector(0.0f, -220.0f, 0.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	CheckCollision->SetCollisionGroup(ECollisionOrder::PosCheck);
	CheckCollision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);
}

AWobbly::~AWobbly()
{

}


void AWobbly::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Wobbly_Idle", "wobblything", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Wobbly_Move", "wobblything", 0.2f);
	
	Renderer->ChangeAnimation("Wobbly_Idle");

	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->SetAutoSize(2.0f, true);
	
}

void AWobbly::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	CheckCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			Renderer->ChangeAnimation("Wobbly_Move");
		});


	CheckCollision->CollisionExit(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			Renderer->ChangeAnimation("Wobbly_Idle");
		});

}