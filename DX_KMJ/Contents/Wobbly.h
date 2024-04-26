#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class AWobbly :public AActor
{
	GENERATED_BODY(AActor)

public : 
	AWobbly();
	~AWobbly();

	AWobbly(const AWobbly& _Other)				 = delete;
	AWobbly(AWobbly& _Other) noexcept				 = delete;
	AWobbly& operator =(const AWobbly& _Other)	 = delete;
	AWobbly& operator =(AWobbly& _Other) noexcept	 = delete;

	void ChangeAnimation(std::string_view _AnimationName, int _Frame = 0)
	{
		Renderer->ChangeAnimation(_AnimationName, _Frame);
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* CheckCollision = nullptr;

};

