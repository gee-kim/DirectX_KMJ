#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADarkMap : public AActor
{
	GENERATED_BODY(AActor)

public : 
	ADarkMap();
	~ADarkMap();

	ADarkMap(const ADarkMap& _Other)				 = delete;
	ADarkMap(ADarkMap& _Other) noexcept				 = delete;
	ADarkMap& operator =(const ADarkMap& _Other)	 = delete;
	ADarkMap& operator =(ADarkMap& _Other) noexcept	 = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;

};

