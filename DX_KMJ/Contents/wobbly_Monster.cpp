#include "PreCompile.h"
#include "Wobbly_Monster.h"
#include <memory>
#include "Wobbly_Bullet.h"

AWobbly_Monster::AWobbly_Monster()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	CheckCollision = CreateDefaultSubObject<UCollision>("Collision");
	CheckCollision->SetupAttachment(Root);
	CheckCollision->SetScale(FVector(200.0f, 200.0f, 50.0f));
	CheckCollision->AddPosition(FVector(0.0f, -220.0f, 0.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	CheckCollision->SetCollisionGroup(ECollisionOrder::Monster);
	CheckCollision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);
}

AWobbly_Monster::~AWobbly_Monster()
{
}

void AWobbly_Monster::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Wobbly_Dark_Idle", "wobblything_evil", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("Wobbly_Drak_Move", "wobblything_evil", 0.2f);

	Renderer->ChangeAnimation("Wobbly_Dark_Idle");

	Renderer->SetOrder(ERenderOrder::Monster);

	Renderer->SetAutoSize(2.0f, true);


}

void AWobbly_Monster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	CheckCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			Renderer->ChangeAnimation("Wobbly_Drak_Move");
			{
				std::shared_ptr< AWobbly_Bullet> bullet = GetWorld()->SpawnActor<AWobbly_Bullet>("AWobbly_Bullet");
			//bullet->AddactorLocation(방향해주기)

			}
			{
				std::shared_ptr< AWobbly_Bullet> bullet = GetWorld()->SpawnActor<AWobbly_Bullet>("AWobbly_Bullet");
			}
			{
				std::shared_ptr< AWobbly_Bullet> bullet = GetWorld()->SpawnActor<AWobbly_Bullet>("AWobbly_Bullet");
			}

			int a = 0;
		});

	CheckCollision->CollisionExit(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			Renderer->ChangeAnimation("Wobbly_Dark_Idle");
		});


}