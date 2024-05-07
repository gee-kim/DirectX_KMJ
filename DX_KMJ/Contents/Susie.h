#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;
class UCollision;
class ADustPile;
class APlayer;
class MyWidget;

class ASusie :public AActor
{
	GENERATED_BODY(AActor)

public : 
	ASusie();
	~ASusie();

	ASusie(const ASusie& _Other)				 = delete;
	ASusie(ASusie& _Other) noexcept				 = delete;
	ASusie& operator =(const ASusie& _Other)	 = delete;
	ASusie& operator =(ASusie& _Other) noexcept	 = delete;

	UStateManager State;

	USpriteRenderer* Renderer = nullptr;
	UCollision* Collision = nullptr;
	std::shared_ptr<ADustPile> DustPile = nullptr;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:

	APlayer* Player = nullptr;
	MyWidget* Widget = nullptr;



	void StateInit();

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void EventMode(float _DeltaTime);

};

