#include "PreCompile.h"
#include "MyWidget.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>

//原戚是銭精 馬是 是銭級聖 淫軒廃陥.
MyWidget::MyWidget()
{
}

MyWidget::~MyWidget()
{
}
void MyWidget::BeginPlay()
{
	// UI研 淫軒馬澗 鯵割税 適掘什亜 吉陥.
	{
		UImage* Image0 = CreateWidget<UImage>(GetWorld(), "SideScreen_Left");
		Image0->SetupAttachment(this);
		Image0->SetWidgetScale3D(FVector(300.0f, 720.0f, 0.0f));
		Image0->SetMulColor(FVector::Black);
		Image0->SetPosition({ -550, 0 });
	}

	{
		Image = CreateWidget<UImage>(GetWorld(), "SideScreen_Right");
		Image->SetupAttachment(this);
		Image->SetWidgetScale3D(FVector(300.0f, 720.0f, 0.0f));
		Image->SetMulColor(FVector::Black);
		Image->SetPosition({ 550, 0 });
		Image->SetActive(false);
	}

	

	{
		/*UTextWidget* Image = CreateWidget<UTextWidget>(GetWorld(), "Test");
		Image->SetupAttachment(this);
		Image->SetFont("叡辞");
		Image->SetScale(100.0f);
		Image->SetColor(Color8Bit::Blue);
		Image->SetPosition({ 400, 300 });
		Image->SetText("馬馬馬た買たびけしい君たびいけし君たびけいし");*/
	}


	AddToViewPort(1);
}

void MyWidget::Tick(float _DeltaTime)
{
	Image->SetActive(false);
}