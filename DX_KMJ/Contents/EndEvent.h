#pragma once
#include <EngineCore/Actor.h>

class UCollision;
class AEndEvent : public AActor
{
	GENERATED_BODY(AActor)
public : 
	AEndEvent();
	~AEndEvent();

	AEndEvent(const AEndEvent& _Other)				 = delete;
	AEndEvent(AEndEvent& _Other) noexcept				 = delete;
	AEndEvent& operator =(const AEndEvent& _Other)	 = delete;
	AEndEvent& operator =(AEndEvent& _Other) noexcept	 = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* Collision = nullptr;

};

