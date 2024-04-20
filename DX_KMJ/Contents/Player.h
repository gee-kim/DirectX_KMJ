#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>
#include <EngineBase/EngineSerializer.h>

// Ό³Έν :
class USpriteRenderer;
class UCollision;

class APlayer : public AActor
{
	GENERATED_BODY(AActor)

public:
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	UStateManager State;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	//UCollision* Collision;

	float Speed = 100.0f;

	void StateInit();

	void Idle(float _DeltaTime);

	void MoveStart();
	void Move(float _DeltaTime);

	void AttakStart();
	void Attak(float _DeltaTime);


};

