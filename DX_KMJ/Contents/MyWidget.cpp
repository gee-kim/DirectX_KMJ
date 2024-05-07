#include "PreCompile.h"
#include "MyWidget.h"
#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>

//���������� ���� �������� �����Ѵ�.
MyWidget::MyWidget()
{
}

MyWidget::~MyWidget()
{
}
void MyWidget::BeginPlay()
{
	Super::BeginPlay();

	// UI�� �����ϴ� ������ Ŭ������ �ȴ�.
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
		TextWidget->SetFont("�ü�");
		TextWidget->SetScale(28.0f);
		TextWidget->SetColor(Color8Bit::White);
		TextWidget->SetPosition({ -150, 300 });
		TextWidget->SetText("* �׽�Ʈ ����, �׽�Ʈ ���� \n* �׽�Ʈ ����\n* �׽�Ʈ ����\n* �׽�Ʈ ����");
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

