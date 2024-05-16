#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class AWobbly_Bullet;

class AWobbly_Monster :public AActor
{
	GENERATED_BODY(AActor)

public:
	AWobbly_Monster();
	~AWobbly_Monster();

	AWobbly_Monster(const AWobbly_Monster& _Other) = delete;
	AWobbly_Monster(AWobbly_Monster& _Other) noexcept = delete;
	AWobbly_Monster& operator =(const AWobbly_Monster& _Other) = delete;
	AWobbly_Monster& operator =(AWobbly_Monster& _Other) noexcept = delete;

	void ChangeAnimation(std::string_view _AnimationName, int _Frame = 0)
	{
		Renderer->ChangeAnimation(_AnimationName, _Frame);
	}

	void ZoneCheckCollisionOn();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* CheckCollision = nullptr;
	UCollision* AttackZoneCheck = nullptr;

	float BulletSpeed = 500.0f;

	FVector Bullet_Left = { -0.3f, -1.0f, 0.0f, 0.0f };
	FVector Bullet_Right = { 0.3f, -1.0f, 0.0f, 0.0f };


	std::vector<std::shared_ptr< AWobbly_Bullet>> Bullets;
};

