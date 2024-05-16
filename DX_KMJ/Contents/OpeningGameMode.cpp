#include "PreCompile.h"
#include "OpeningGameMode.h"
#include "Opening_BackGround.h"
#include <EngineCore/Camera.h>
#include "Player.h"

AOpeningGameMode::AOpeningGameMode()
{
}

AOpeningGameMode::~AOpeningGameMode()
{
}

void AOpeningGameMode::BeginPlay()
{
	Super::BeginPlay();

	Back = GetWorld()->SpawnActor<AOpening_BackGround>("BackGround");
		
	Back->SetActorLocation({ 640.0f, -360.0f, 100.0f });

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(640.0f, -360.0f, -200.0f));


	
}


void AOpeningGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	InpuOnTime -= _DeltaTime;

	if (true == UEngineInput::IsDown(VK_SPACE) && 0.0>= InpuOnTime)
	{

		UEngineSound::SoundPlay("AUDIO_APPEARANCE_ch1.wav");
		UContentsConstValue::IsOpeningOff = true;

		GEngine->ChangeLevel("DarkLevel");


	}

}