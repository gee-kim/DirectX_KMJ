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
	// 화면 양 옆 스크린
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
	
	// 텍스트박스
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "TextBox");
		Image->SetupAttachment(this);
		Image->SetSprite("textbox.png");
		Image->SetAutoSize(2.8f, true);
		Image->SetPosition({ 0, 220 });
		Image->SetActive(false);
		Images.push_back(Image);
	}
	
	// 수지 face 이미지
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

	// 텍스트 위젯
	{
		UTextWidget* TextWidget = CreateWidget<UTextWidget>(GetWorld(), "Text");
		TextWidget->SetupAttachment(this);
		TextWidget->SetFont("궁서");
		TextWidget->SetScale(28.0f);
		TextWidget->SetColor(Color8Bit::White);
		TextWidget->SetPosition({ -150, 300 });
		TextWidget->SetActive(false);
		TextWidget->SetFlag(FW1_LEFT);

		TextWidgets.push_back(TextWidget);
		
	}

	// Hp바 바탕위젯
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Hpbar_Back");
		Image->SetupAttachment(this);
		Image->SetWidgetScale3D(FVector(1280.0f, 100.0f, 0.0f));
		Image->SetMulColor(FVector::Black);
		Image->SetPosition({ 0, -310 });
		Images.push_back(Image);

	}

	// Hp바 얼굴 
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "CharFace");
		Image->SetupAttachment(this);
		Image->SetSprite("spr_headkris_ch1_0.png");
		Image->SetAutoSize(1.3f, true);
		Image->SetPosition({ -200, -300 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);

	}

	// HP 이름 텍스트 위젯
	{
		UTextWidget* TextWidget = CreateWidget<UTextWidget>(GetWorld(), "Text");
		TextWidget->SetupAttachment(this);
		TextWidget->SetFont("굴림");
		TextWidget->SetScale(18.0f);
		TextWidget->SetColor(Color8Bit::White);
		TextWidget->SetPosition({ -160, -290 });
		TextWidget->SetText("크리스");
		//TextWidget->SetActive(false);
		TextWidget->SetFlag(FW1_LEFT);

		TextWidgets.push_back(TextWidget);

	}
	
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Hp_Letter");
		Image->SetupAttachment(this);
		Image->SetSprite("spr_hpname_ch1_0.png");
		Image->SetAutoSize(1.3f, true);
		Image->SetPosition({ -40, -305 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);

	}

	//Hp 에너지바 애니메이션
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Hpbar_Images");
		//Image->SetupAttachment(this);
		Image->CreateAnimation("Hpbar_0", "hpbar_image", 0.0f, false, 0, 0);
		Image->CreateAnimation("Hpbar_1", "hpbar_image", 0.0f, false, 1, 1);
		Image->CreateAnimation("Hpbar_2", "hpbar_image", 0.0f, false, 2, 2);
		Image->CreateAnimation("Hpbar_3", "hpbar_image", 0.0f, false, 3, 3);
		Image->CreateAnimation("Hpbar_4", "hpbar_image", 0.0f, false, 4, 4);
		Image->CreateAnimation("Hpbar_5", "hpbar_image", 0.0f, false, 5, 5);
		Image->CreateAnimation("Hpbar_6", "hpbar_image", 0.0f, false, 6, 6);
		Image->CreateAnimation("Hpbar_7", "hpbar_image", 0.0f, false, 7, 7);

		Image->ChangeAnimation("Hpbar_0");

		Image->SetAutoSize(0.4f, true);
		Image->SetPosition({ 20, -305 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);
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