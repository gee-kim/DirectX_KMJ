#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADarkEye : public AActor
{
	GENERATED_BODY(AActor)

public : 
	ADarkEye();
	~ADarkEye();

	ADarkEye(const ADarkEye& _Other)				 = delete;
	ADarkEye(ADarkEye& _Other) noexcept				 = delete;
	ADarkEye& operator =(const ADarkEye& _Other)	 = delete;
	ADarkEye& operator =(ADarkEye& _Other) noexcept	 = delete;

	void ChangeAnimation(std::string_view _AnimationName, int _Frame = 0)
	{
		Renderer->ChangeAnimation(_AnimationName, _Frame);
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	UCollision* Collision = nullptr;

};

