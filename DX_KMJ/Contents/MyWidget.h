#pragma once
#include <EngineCore/Widget.h>
#include <EngineCore/Image.h>
#include <EngineCore/TextWidget.h>

class MyWidget : public UWidget
{
public : 
	MyWidget();
	~MyWidget();

	MyWidget(const MyWidget& _Other)				 = delete;
	MyWidget(MyWidget& _Other) noexcept				 = delete;
	MyWidget& operator =(const MyWidget& _Other)	 = delete;
	MyWidget& operator =(MyWidget& _Other) noexcept	 = delete;
	
	

protected:
	void BeginPlay();
	void Tick(float _DeltaTime);

	std::vector<UImage*> Images;
	std::vector<UTextWidget*> TextWidgets;


private:

};

