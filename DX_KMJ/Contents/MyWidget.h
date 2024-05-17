#pragma once
#include <EngineCore/Widget.h>
#include <EngineCore/Image.h>
#include <EngineCore/TextWidget.h>

class MyWidget : public UWidget
{
	GENERATED_BODY(UWidget)
public : 
	MyWidget();
	~MyWidget();

	MyWidget(const MyWidget& _Other)				 = delete;
	MyWidget(MyWidget& _Other) noexcept				 = delete;
	MyWidget& operator =(const MyWidget& _Other)	 = delete;
	MyWidget& operator =(MyWidget& _Other) noexcept	 = delete;
	
	void SetTextBoxOn();
	void SetTextBoxOff();

	void SetFaceOn();
	void SetFaceOff();

	void ChangeFace(std::string _FaceName);
	
	void SetTextScript(std::string _Text)
	{
		TextWidgets[0]->SetActive(true);
		TextWidgets[0]->SetText(_Text);
	}
	
	void SetTextBoxPos(FVector _Pos)
	{
		TextWidgets[0]->SetPosition(_Pos);
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	std::vector<UImage*> Images;
	std::vector<UTextWidget*> TextWidgets;


private:

};

