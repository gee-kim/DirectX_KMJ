#include "PreCompile.h"
#include "Wobbly_Bullet.h"


AWobbly_Bullet::AWobbly_Bullet()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	BulletCollision = CreateDefaultSubObject<UCollision>("Collision");
	BulletCollision->SetupAttachment(Root);
	BulletCollision->SetScale(FVector(15.0f, 15.0f, 15.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	BulletCollision->SetCollisionGroup(ECollisionOrder::Bullet);
	BulletCollision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);

}

AWobbly_Bullet::~AWobbly_Bullet()
{
}

void AWobbly_Bullet::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("spr_wobblebullet_ch1_0.png");
	Renderer->SetOrder(ERenderOrder::Bullet);

	Renderer->SetAutoSize(2.0f, true);

	//Renderer->SetPosition(FVector(7558.0f, -1188.0f, 0.0f));

	
}

void AWobbly_Bullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	AddActorLocation(Bullet_Dir * Speed * _DeltaTime);
}

void AWobbly_Bullet::SetBulletDir(FVector _Dir)
{
	Bullet_Dir = _Dir;
}