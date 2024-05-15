#include "PreCompile.h"
#include "HpWidget.h"
#include <EngineCore/Image.h>
#include <EngineCore/TextWidget.h>

AHpWidget::AHpWidget()
{
}

AHpWidget::~AHpWidget()
{
}

void AHpWidget::BeginPlay()
{
	Super::BeginPlay();

	// Hp바 바탕위젯
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Hpbar_Back");
		Image->SetupAttachment(this);
		Image->SetWidgetScale3D(FVector(1280.0f, 100.0f, 0.0f));
		Image->SetMulColor(FVector::Black);
		Image->SetPosition({ 0, -310 });
		Images.push_back(Image);

		//Image->AddToViewPort(1);
	}

	// Hp바 얼굴 
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "CharFace");
		Image->SetupAttachment(this);
		Image->SetSprite("spr_headkris_ch1_0.png");
		Image->SetAutoSize(1.3f, true);
		Image->SetPosition({ -200, -300 });
		Images.push_back(Image);

		Image->AddToViewPort(2);

	}

	// HP 캐릭터 이름 텍스트 위젯
	{
		TextWidget = CreateWidget<UTextWidget>(GetWorld(), "Text");
		TextWidget->SetupAttachment(this);
		TextWidget->SetFont("굴림");
		TextWidget->SetScale(18.0f);
		TextWidget->SetColor(Color8Bit::White);
		TextWidget->SetPosition({ -160, -290 });
		TextWidget->SetText("크리스");
		//TextWidget->SetActive(false);
		TextWidget->SetFlag(FW1_LEFT);

		TextWidget->AddToViewPort(2);
	}
	// HP 레터 
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
		Image->CreateAnimation("Hpbar0", "hpbar_image", 0.0f, false, 0, 0);
		Image->CreateAnimation("Hpbar1", "hpbar_image", 0.0f, false, 1, 1);
		Image->CreateAnimation("Hpbar2", "hpbar_image", 0.0f, false, 2, 2);
		Image->CreateAnimation("Hpbar3", "hpbar_image", 0.0f, false, 3, 3);
		Image->CreateAnimation("Hpbar4", "hpbar_image", 0.0f, false, 4, 4);
		Image->CreateAnimation("Hpbar5", "hpbar_image", 0.0f, false, 5, 5);
		Image->CreateAnimation("Hpbar6", "hpbar_image", 0.0f, false, 6, 6);
		//Image->CreateAnimation("Hpbar_7", "hpbar_image", 0.0f, false, 7, 7);

		Image->ChangeAnimation("Hpbar0");

		Image->SetAutoSize(0.4f, true);
		Image->SetPosition({ 20, -305 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);
	}

	//Hp number 애니메이션
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Hpbar_Numbers");
		//Image->SetupAttachment(this);
		Image->CreateAnimation("Hp_Energy0", "hp_energy", 0.0f, false, 0, 0);
		Image->CreateAnimation("Hp_Energy1", "hp_energy", 0.0f, false, 1, 1);
		Image->CreateAnimation("Hp_Energy2", "hp_energy", 0.0f, false, 2, 2);
		Image->CreateAnimation("Hp_Energy3", "hp_energy", 0.0f, false, 3, 3);
		Image->CreateAnimation("Hp_Energy4", "hp_energy", 0.0f, false, 4, 4);
		Image->CreateAnimation("Hp_Energy5", "hp_energy", 0.0f, false, 5, 5);
		Image->CreateAnimation("Hp_Energy6", "hp_energy", 0.0f, false, 6, 6);
		//Image->CreateAnimation("Hpbar_7", "hpbar_image", 0.0f, false, 7, 7);

		Image->ChangeAnimation("Hp_Energy0");

		Image->SetAutoSize(1.2f, true);
		Image->SetPosition({ 0, -285 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);
	}

	//Hp 슬래쉬 이미지
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Slash");
		Image->SetupAttachment(this);
		Image->SetSprite("spr_hpslash_ch1_0.png");
		Image->SetAutoSize(1.0f, true);
		Image->SetPosition({ 20, -285 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);

	}

	//Hp Full 이미지
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "FullHp");
		//Image->SetupAttachment(this);
		Image->SetSprite("number_Hp.png");
		Image->SetAutoSize(1.2f, true);
		Image->SetPosition({ 50, -285 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);

	}

	AddToViewPort(1);

	SetActive(false);

}


void  AHpWidget::ChangeNumber(int _Num)
{
	std::string Hpbar = "Hpbar";
	std::string Num = Hpbar + std::to_string(_Num);
	Images[3]->ChangeAnimation(Num);

	std::string Hp_Energy = "Hp_Energy";
	std::string Num1 = Hp_Energy + std::to_string(_Num);
	
	Images[4]->ChangeAnimation(Num1);

}

void AHpWidget::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	int a = 0;

}


void AHpWidget::SetHpWidgetOn()
{
	Images[0]->SetActive(true);
	Images[1]->SetActive(true);
	Images[2]->SetActive(true);
	Images[3]->SetActive(true);
	Images[4]->SetActive(true);
	Images[5]->SetActive(true);
	Images[6]->SetActive(true);

	TextWidget->SetActive(true);

}

void AHpWidget::SetHpWidgetOff()
{
	Images[0]->SetActive(false);
	Images[1]->SetActive(false);
	Images[2]->SetActive(false);
	Images[3]->SetActive(false);
	Images[4]->SetActive(false);
	Images[5]->SetActive(false);
	Images[6]->SetActive(false);

	TextWidget->SetActive(false);
}
