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

	UEngineSound::SoundPlay("AUDIO_INTRONOISE.ogg");

}

void AOpening_BackGround::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	OffTime -= _DeltaTime;
	Renderer->SetAutoSize(OffTime, true);

	if (0.0f >= OffTime)
	{
		Renderer->SetActive(false);
		OffTime = 0.0f;
	}
	
	OnTime += _DeltaTime;

	if (5.0f <= OnTime)
	{
		Logo_Renderer->SetActive(true);
		Logo_Renderer->SetAutoSize(OnTime - 5.0f, true);

		if (8.0f <= OnTime)
		{
			Logo_Renderer->SetAutoSize(3.0f, true);
		}

	}
	


}