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

	Renderer->SetSprite("spr_krisandsusie_fall_ch1_0.png");
	Renderer->SetAutoSize(Time, true);
	Renderer->SetOrder(ERenderOrder::Back);

	//Logo->SetSprite("IMAGE_LOGO_CENTER_ch1_0.png");
	//Logo->SetAutoSize(1.0f, true);
	//Logo->SetOrder(ERenderOrder::Back);
	//Logo->SetActive(false);

}

void AOpening_BackGround::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	Time -= _DeltaTime;
	Renderer->SetAutoSize(Time, true);

	if (Time <= 0.0f)
	{
		//Time = 0.0f;
		Renderer->SetActive(false);
		
		//Logo->SetActive(true);
		//Time += _DeltaTime;

		//Logo->SetAutoSize(Time, true);
	}



}