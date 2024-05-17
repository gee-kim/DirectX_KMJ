#pragma once
#include <EngineCore/Actor.h>
#include "MyWidget.h"

class USpriteRenderer;
class UCollision;
class APlayer;

class ASign : public AActor
{
	GENERATED_BODY(AActor)

public:
	ASign();
	~ASign();

	ASign(const ASign& _Other) = delete;
	ASign(ASign& _Other) noexcept = delete;
	ASign& operator =(const ASign& _Other) = delete;
	ASign& operator =(ASign& _Other) noexcept = delete;

	void SetWidget(MyWidget* _widget)
	{
		Widget = _widget;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* Collision = nullptr;

	std::shared_ptr<APlayer> Player = nullptr;
		
	MyWidget* Widget = nullptr;

};

