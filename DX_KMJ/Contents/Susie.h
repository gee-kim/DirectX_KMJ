#pragma once
#include "Character.h"
#include <EngineCore/StateManager.h>

class USpriteRenderer;
class UCollision;
class ADustPile;
class APlayer;
class MyWidget;

class ASusie :public ACharacter
{
	GENERATED_BODY(ACharacter)

public : 
	ASusie();
	~ASusie();

	ASusie(const ASusie& _Other)				 = delete;
	ASusie(ASusie& _Other) noexcept				 = delete;
	ASusie& operator =(const ASusie& _Other)	 = delete;
	ASusie& operator =(ASusie& _Other) noexcept	 = delete;


	USpriteRenderer* Renderer = nullptr;
	UCollision* Collision = nullptr;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:
	APlayer* Player = nullptr;
	MyWidget* Widget = nullptr;

	void DirAnimationChange(std::string _AnimationName);

	void StateInit();

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void EventMode(float _DeltaTime);
};

