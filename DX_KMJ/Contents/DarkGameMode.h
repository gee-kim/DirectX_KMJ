#pragma once
#include <EngineCore/GameMode.h>

class ADarkGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public : 
	ADarkGameMode();
	~ADarkGameMode();

	ADarkGameMode(const ADarkGameMode& _Other)				 = delete;
	ADarkGameMode(ADarkGameMode& _Other) noexcept				 = delete;
	ADarkGameMode& operator =(const ADarkGameMode& _Other)	 = delete;
	ADarkGameMode& operator =(ADarkGameMode& _Other) noexcept	 = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};

