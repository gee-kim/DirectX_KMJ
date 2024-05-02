#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	

private:
	USpriteRenderer* Renderer = nullptr;

};

