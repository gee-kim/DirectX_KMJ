#pragma once
#include "PreCompile.h"
#include <EngineCore/Actor.h>

class USpriteRenderer;
class UCollision;

class AWobbly_Bullet : public AActor
{
	GENERATED_BODY(AActor)

public : 
	AWobbly_Bullet();
	~AWobbly_Bullet();

	AWobbly_Bullet(const AWobbly_Bullet& _Other)				 = delete;
	AWobbly_Bullet(AWobbly_Bullet& _Other) noexcept				 = delete;
	AWobbly_Bullet& operator =(const AWobbly_Bullet& _Other)	 = delete;
	AWobbly_Bullet& operator =(AWobbly_Bullet& _Other) noexcept	 = delete;
	
	void StartAtt(float _DeltaTime);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* BulletCollision = nullptr;

	float Speed = 500.0f;

};

