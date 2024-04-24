#include "Wobbly_Bullet.h"

AWobbly_Bullet::AWobbly_Bullet()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
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

}