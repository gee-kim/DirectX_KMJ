#pragma once
#include "Character.h"
#include <EngineBase/EngineSerializer.h>
#include "ContentsConstValue.h"

// Ό³Έν :
class USpriteRenderer;
class UCollision;
class AHpWidget;

class APlayer : public ACharacter
{
	GENERATED_BODY(ACharacter)

public:
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	UCollision* Collision = nullptr;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void DirAnimationChange(std::string _AnimationName);

private:
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* HeartRenderer = nullptr;
	AHpWidget* HpWidget = nullptr;

	Color8Bit ColColor;
	Color8Bit GravColor;
	Color8Bit PassColor;

	float4 GravityValue;

	float Speed = 200.0f;
	float FreeMoveSpeed = 1000.0f;
	float DropSpeed = 500.0f;

	float TimeCount = 3.0f;

	float ShakeTime = 0.5f;
	bool IsWidgetOn = false;

	void StateInit();

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void Fallen(float _DeltaTime);
	void Gravity(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Escape_Move(float _DeltaTime);
	void Escape_Idle(float _DeltaTime);
	void Event(float _DeltaTime);

	bool IsEnd = false;

	void DebugMessageFunction();
	void ColorCheck(float4 _NextPos);

	void MoveCheck(float4 _Dir);

	UEngineSoundPlayer BGMPlayer1;
	UEngineSoundPlayer BGMPlayer2;
	UEngineSoundPlayer BGMPlayer3;
};

