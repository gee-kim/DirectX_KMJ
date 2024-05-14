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
	// ȭ�� �� �� ��ũ��
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
	
	// �ؽ�Ʈ�ڽ�
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "TextBox");
		Image->SetupAttachment(this);
		Image->SetSprite("textbox.png");
		Image->SetAutoSize(2.8f, true);
		Image->SetPosition({ 0, 220 });
		Image->SetActive(false);
		Images.push_back(Image);
	}
	
	// ���� face �̹���
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "SusieFace");
		//Image->SetupAttachment(this);
		Image->CreateAnimation("Susie_Face_0", "Susie_Face", 0.0f, false, 6, 6);
		Image->CreateAnimation("Susie_Face_1", "Susie_Face", 0.0f, false, 5, 5);
		Image->CreateAnimation("Susie_Face_2", "Susie_Face", 0.0f, false, 1, 1);
		Image->CreateAnimation("Susie_Face_3", "Susie_Face", 0.0f, false, 0, 0);
		Image->ChangeAnimation("Susie_Face_0");

		Image->SetAutoSize(2.8f, true);
		Image->SetPosition({ -250, 240 });
		Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);
	}

	// �ؽ�Ʈ ����
	{
		UTextWidget* TextWidget = CreateWidget<UTextWidget>(GetWorld(), "Text");
		TextWidget->SetupAttachment(this);
		TextWidget->SetFont("�ü�");
		TextWidget->SetScale(28.0f);
		TextWidget->SetColor(Color8Bit::White);
		TextWidget->SetPosition({ -150, 300 });
		TextWidget->SetActive(false);
		TextWidget->SetFlag(FW1_LEFT);

		TextWidgets.push_back(TextWidget);
		
	}

	

	AddToViewPort(1);

}

void MyWidget::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	int a = 0;

}

void MyWidget::SetFaceOn()
{
	Images[3]->SetActive(true);
}

void MyWidget::SetFaceOff()
{
	Images[3]->SetActive(false);
}

void MyWidget::ChangeFace(std::string _FaceName)
{
	Images[3]->ChangeAnimation(_FaceName);
}

void MyWidget::SetTextBoxOn()
{
	Images[2]->SetActive(true);
}

void MyWidget::SetTextBoxOff()
{
	Images[2]->SetActive(false);
	Images[3]->SetActive(false);
	TextWidgets[0]->SetActive(false);
}
