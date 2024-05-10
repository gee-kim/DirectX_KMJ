#pragma once
#include "BackGround.h"

class USpriteRenderer;

class AOpening_BackGround : public ABackGround
{
	GENERATED_BODY(ABackGround)

public : 
	AOpening_BackGround();
	~AOpening_BackGround();

	AOpening_BackGround(const AOpening_BackGround& _Other)				 = delete;
	AOpening_BackGround(AOpening_BackGround& _Other) noexcept				 = delete;
	AOpening_BackGround& operator =(const AOpening_BackGround& _Other)	 = delete;
	AOpening_BackGround& operator =(AOpening_BackGround& _Other) noexcept	 = delete;



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	
	float OffTime = 4.0f;
	float OnTime = 0.0f;


};

