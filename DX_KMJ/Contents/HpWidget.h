#pragma once
#include <EngineCore/Widget.h>

class UImage;
class UTextWidget;

class AHpWidget: public UWidget
{
	GENERATED_BODY(UWidget)
public : 
	AHpWidget();
	~AHpWidget();

	AHpWidget(const AHpWidget& _Other)				 = delete;
	AHpWidget(AHpWidget& _Other) noexcept				 = delete;
	AHpWidget& operator =(const AHpWidget& _Other)	 = delete;
	AHpWidget& operator =(AHpWidget& _Other) noexcept	 = delete;

	void SetHpWidgetOn();
	void SetHpWidgetOff();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::vector<UImage*> Images;
};

