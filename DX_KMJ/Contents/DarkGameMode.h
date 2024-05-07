#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/StateManager.h>
#include <list>
#include <memory>

class GameEvent
{
public:
	std::function<bool()> EventStartCheck = nullptr;
	UStateManager State;
	int CurState = -1;

	void Next();
};

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

	int CurTextIndex = 0;
	std::vector<std::string> Script;

	// 이벤트라는것은
	// 어떻게 시작하는가?

	std::list<std::shared_ptr<GameEvent>> Events;
	std::shared_ptr<GameEvent> CurEvent = nullptr;

	
};

