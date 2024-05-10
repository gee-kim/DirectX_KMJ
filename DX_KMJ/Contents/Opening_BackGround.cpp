#include "PreCompile.h"
#include "Opening_BackGround.h"
#include "BackGround.h"


AOpening_BackGround::AOpening_BackGround()
{
}

AOpening_BackGround::~AOpening_BackGround()
{
}


void AOpening_BackGround::BeginPlay()
{
	Super::BeginPlay();

	Back_Renderer->SetSprite("IntroBackGround.png");
	Back_Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(ERenderOrder::ColBack);

	{
		Renderer->SetSprite("spr_krisandsusie_fall_ch1_0.png");
		Renderer->SetAutoSize(OffTime, true);
		Renderer->SetOrder(ERenderOrder::Back);
	}

	{
		Logo_Renderer->SetSprite("IMAGE_LOGO_CENTER_ch1_0.png");
		Logo_Renderer->SetAutoSize(OnTime, true);
		Logo_Renderer->SetOrder(ERenderOrder::Back);
		Logo_Renderer->SetActive(false);
	}

}

void AOpening_BackGround::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);

	OffTime -= _DeltaTime;
	Renderer->SetAutoSize(OffTime, true);

	if (0.0f >= OffTime)
	{
		Renderer->SetActive(false);
		OffTime = 0.0f;
	}
	
	OnTime += _DeltaTime;

	if (4.0f <= OnTime)
	{
		Logo_Renderer->SetActive(true);
		Logo_Renderer->SetAutoSize(OnTime - 4.0f, true);

		if (6.5f <= OnTime)
		{
			Logo_Renderer->SetAutoSize(2.5f, true);
		}

	}
	


}