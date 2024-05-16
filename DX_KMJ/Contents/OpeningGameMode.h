#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :

class AOpening_BackGround;

class AOpeningGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	AOpeningGameMode();
	~AOpeningGameMode();

	// delete Function
	AOpeningGameMode(const AOpeningGameMode& _Other) = delete;
	AOpeningGameMode(AOpeningGameMode&& _Other) noexcept = delete;
	AOpeningGameMode& operator=(const AOpeningGameMode& _Other) = delete;
	AOpeningGameMode& operator=(AOpeningGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<AOpening_BackGround> Back = nullptr;

	float LogoOffTime = 3.0f;

	float InpuOnTime = 8.5f;
};

