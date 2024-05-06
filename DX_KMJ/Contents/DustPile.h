#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADustPile : public AActor
{
	GENERATED_BODY(AActor)

public : 
	ADustPile();
	~ADustPile();

	ADustPile(const ADustPile& _Other)				 = delete;
	ADustPile(ADustPile& _Other) noexcept				 = delete;
	ADustPile& operator =(const ADustPile& _Other)	 = delete;
	ADustPile& operator =(ADustPile& _Other) noexcept	 = delete;

	void SetEventMode();

	protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::vector<USpriteRenderer*> Renderers;
	
	float Time = 0.0f;
	int Count = 1;
	bool bubble = true;
};

