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
		Image->SetFont("궁서");
		Image->SetScale(100.0f);
		Image->SetColor(Color8Bit::Blue);
		Image->SetPosition({ 400, 300 });
		Image->SetText("하하하ㅏ허ㅏㅣㅁㅇㄴ러ㅏㅣㄴㅁㅇ러ㅏㅣㅁㄴㅇ");*/
	}


	AddToViewPort(1);
}

void MyWidget::Tick(float _DeltaTime)
{
	Image->SetActive(false);
}