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
	Super::BeginPlay();

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
		Image->SetAutoSize(2.8f, true);
		Image->SetPosition({ 0, 220 });
		Images.push_back(Image);

	}



	{
		TextWidget = CreateWidget<UTextWidget>(GetWorld(), "Text");
		TextWidget->SetupAttachment(this);
		TextWidget->SetFont("궁서");
		TextWidget->SetScale(28.0f);
		TextWidget->SetColor(Color8Bit::White);
		TextWidget->SetPosition({ -150, 300 });
		TextWidget->SetText("* 테스트 문구, 테스트 문구 \n* 테스트 문구\n* 테스트 문구\n* 테스트 문구");
		TextWidget->SetFlag(FW1_LEFT);
		
	}


	AddToViewPort(1);

}

void MyWidget::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//Images[2]->SetActive(false);

	int a = 0;

}

