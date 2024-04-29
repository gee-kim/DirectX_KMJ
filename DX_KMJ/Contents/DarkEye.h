#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADarkEye : public AActor
{
public : 
	ADarkEye();
	~ADarkEye();

	ADarkEye(const ADarkEye& _Other)				 = delete;
	ADarkEye(ADarkEye& _Other) noexcept				 = delete;
	ADarkEye& operator =(const ADarkEye& _Other)	 = delete;
	ADarkEye& operator =(ADarkEye& _Other) noexcept	 = delete;

protected:

private:
};

