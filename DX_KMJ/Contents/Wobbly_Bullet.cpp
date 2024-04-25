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
	// �ݸ����� ������ ������ ��������� �Ѵ�.
	BulletCollision->SetCollisionGroup(ECollisionOrder::Bullet);
	BulletCollision->SetCollisionType(ECollisionType::RotRect);

	CheckCollision = CreateDefaultSubObject<UCollision>("Collision");
	CheckCollision->SetupAttachment(Root);
	CheckCollision->SetScale(FVector(50.0f, 100.0f, 50.0f));
	CheckCollision->AddPosition(FVector(0.0f, -100.0f, 0.0f));
	// �ݸ����� ������ ������ ��������� �Ѵ�.
	CheckCollision->SetCollisionGroup(ECollisionOrder::Back);
	CheckCollision->SetCollisionType(ECollisionType::RotRect);

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

}

void AWobbly_Bullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//Renderer->SetActive(false);


}