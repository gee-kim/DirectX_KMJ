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
	void DirAnimationChange(std::string _AnimationName);

private:
	std::string Dir = "_Right";
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* HeartRenderer = nullptr;
	UCollision* Collision = nullptr;
	Color8Bit ColColor;
	Color8Bit GravColor;
	float4 GravityValue;

	float Speed = 200.0f;
	float FreeMoveSpeed = 1000.0f;
	float DropSpeed = 500.0f;

	float TimeCount = 5.0f;

	void StateInit();

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void Attak(float _DeltaTime);
	void Fallen(float _DeltaTime);
	void Gravity(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Escape(float _DeltaTime);



	void DebugMessageFunction();
	void ColorCheck(float4 _NextPos);

};

