#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class AMagicalGlass : public AActor
{
GENERATED_BODY(AActor)

public : 
	AMagicalGlass();
	~AMagicalGlass();

	AMagicalGlass(const AMagicalGlass& _Other)				 = delete;
	AMagicalGlass(AMagicalGlass& _Other) noexcept				 = delete;
	AMagicalGlass& operator =(const AMagicalGlass& _Other)	 = delete;
	AMagicalGlass& operator =(AMagicalGlass& _Other) noexcept	 = delete;

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

