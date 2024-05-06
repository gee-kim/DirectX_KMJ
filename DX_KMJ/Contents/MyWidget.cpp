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
	// UI�� �����ϴ� ������ Ŭ������ �ȴ�.
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
		Image->SetFont("�ü�");
		Image->SetScale(100.0f);
		Image->SetColor(Color8Bit::Blue);
		Image->SetPosition({ 400, 300 });
		Image->SetText("�����Ϥ��㤿�Ӥ����������Ӥ����������Ӥ�����");*/
	}


	AddToViewPort(1);
}

void MyWidget::Tick(float _DeltaTime)
{
	Image->SetActive(false);
}