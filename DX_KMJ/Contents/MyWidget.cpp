#include "PreCompile.h"
#include "MyWidget.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>

//마이위젯은 하위 위젯들을 관리한다.
MyWidget::MyWidget()
{
}

MyWidget::~MyWidget()
{
}
void MyWidget::BeginPlay()
{
	// UI를 관리하는 개념의 클래스가 된다.
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "SideScreen_Left");
		Image->SetupAttachment(this);
		Image->SetWidgetScale3D(FVector(300.0f, 720.0f, 0.0f));
		Image->SetMulColor(FVector::Black);
		Image->SetPosition({ -550, 0 });
		Images.push_back(Image);
	}

	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "SideScreen_Right");
		Image->SetupAttachment(this);
		Image->SetWidgetScale3D(FVector(300.0f, 720.0f, 0.0f));
		Image->SetMulColor(FVector::Black);
		Image->SetPosition({ 550, 0 });
		Images.push_back(Image);

	}

	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "TextBox");
		Image->SetupAttachment(this);
		Image->SetSprite("textbox.png");
		Image->SetAutoSize(2.5f, true);
		Image->SetPosition({ 0, 200 });
		Images.push_back(Image);

	}



	{
		UTextWidget* TextWidget = CreateWidget<UTextWidget>(GetWorld(), "Text");
		TextWidget->SetupAttachment(this);
		TextWidget->SetFont("궁서");
		TextWidget->SetScale(100.0f);
		TextWidget->SetColor(Color8Bit::White);
		TextWidget->SetPosition({ -100, 200 });
		TextWidget->SetText("테스트 문구");

		TextWidgets.push_back(TextWidget);
	}


	AddToViewPort(1);

}

void MyWidget::Tick(float _DeltaTime)
{
	Images[2]->SetActive(false);

}