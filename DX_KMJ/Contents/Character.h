#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class ACharacter : public AActor
{
public : 
	ACharacter();
	~ACharacter();

	ACharacter(const ACharacter& _Other)				 = delete;
	ACharacter(ACharacter& _Other) noexcept				 = delete;
	ACharacter& operator =(const ACharacter& _Other)	 = delete;
	ACharacter& operator =(ACharacter& _Other) noexcept	 = delete;

	UStateManager State;

	std::string Dir = "_Right";

	void Link(ACharacter* _Ch)
	{
		Child = _Ch;
	}

	std::list<float4> PrevPos;


protected:
	void Tick(float _DeltaTime) override;

private:
	ACharacter* Child = nullptr;


};

