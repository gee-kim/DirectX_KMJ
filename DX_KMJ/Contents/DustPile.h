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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* Part0 = nullptr;
	USpriteRenderer* Part1 = nullptr;
	USpriteRenderer* Part2 = nullptr;
	USpriteRenderer* Part3 = nullptr;
	USpriteRenderer* Part4 = nullptr;

};

