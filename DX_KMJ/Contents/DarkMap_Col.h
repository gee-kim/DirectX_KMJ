#pragma once
#include "BackGround.h"

class USpriteRenderer;

class ADarkMap_Col :public ABackGround
{
	GENERATED_BODY(ABackGround)

public : 
	ADarkMap_Col();
	~ADarkMap_Col();

	ADarkMap_Col(const ADarkMap_Col& _Other)				 = delete;
	ADarkMap_Col(ADarkMap_Col& _Other) noexcept				 = delete;
	ADarkMap_Col& operator =(const ADarkMap_Col& _Other)	 = delete;
	ADarkMap_Col& operator =(ADarkMap_Col& _Other) noexcept	 = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};

