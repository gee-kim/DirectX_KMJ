#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class AEyePuzzle : public AActor
{
	GENERATED_BODY(AActor)

public : 
	AEyePuzzle();
	~AEyePuzzle();

	AEyePuzzle(const AEyePuzzle& _Other)				 = delete;
	AEyePuzzle(AEyePuzzle& _Other) noexcept				 = delete;
	AEyePuzzle& operator =(const AEyePuzzle& _Other)	 = delete;
	AEyePuzzle& operator =(AEyePuzzle& _Other) noexcept	 = delete;

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

