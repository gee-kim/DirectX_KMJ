#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/StateManager.h>
#include <list>
#include <memory>

class GameEvent
{
public:
	bool IsEnd = false;

	std::function<bool()> EventStartCheck = nullptr;
	UStateManager State;
	int CurState = -1;

	void End()
	{
		IsEnd = true;
	}

	void Next();
};

class ADustPile;

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

	void SusieEvent(float _DeltaTime);

private:

	float Susie_Speed = 30.0f;
	FVector Susie_Left = { -2.2f, -0.8f, 0.0f, 0.0f };

	// 이벤트라는것은
	// 어떻게 시작하는가?

	std::shared_ptr<ADustPile> DustBubble;

	std::list<std::shared_ptr<GameEvent>> Events;
	std::shared_ptr<GameEvent> CurEvent = nullptr;

	UEngineSoundPlayer BGMPlayer;
};

