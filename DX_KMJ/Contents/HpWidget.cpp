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

	// HP 캐릭터 이름 텍스트 위젯
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

	//Hp number 애니메이션
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Hpbar_Numbers");
		//Image->SetupAttachment(this);
		Image->CreateAnimation("Hp_Energy_0", "hp_energy", 0.0f, false, 0, 0);
		Image->CreateAnimation("Hp_Energy_1", "hp_energy", 0.0f, false, 1, 1);
		Image->CreateAnimation("Hp_Energy_2", "hp_energy", 0.0f, false, 2, 2);
		Image->CreateAnimation("Hp_Energy_3", "hp_energy", 0.0f, false, 3, 3);
		Image->CreateAnimation("Hp_Energy_4", "hp_energy", 0.0f, false, 4, 4);
		Image->CreateAnimation("Hp_Energy_5", "hp_energy", 0.0f, false, 5, 5);
		//Image->CreateAnimation("Hpbar_6", "hpbar_image", 0.0f, false, 6, 6);
		//Image->CreateAnimation("Hpbar_7", "hpbar_image", 0.0f, false, 7, 7);

		Image->ChangeAnimation("Hp_Energy_0");

		Image->SetAutoSize(1.2f, true);
		Image->SetPosition({ 0, -285 });
		//Image->SetActive(false);
		Images.push_back(Image);

		Image->AddToViewPort(2);
	}

	//Hp 슬래쉬 이미지
	{
		UImage* Image = CreateWidget<UImage>(GetWorld(), "FullHp");
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


void AHpWidget::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	int a = 0;

}


void AHpWidget::SetHpWidgetOn()
{

	SetActive(true);

}