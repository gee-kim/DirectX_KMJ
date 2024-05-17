#include "PreCompile.h"
#include "DarkEye.h"
#include "MagicalGlass.h"

ADarkEye::ADarkEye()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer0 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer0->SetupAttachment(Root);

	Renderer1 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer1->SetupAttachment(Root);

	Renderer2 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer2->SetupAttachment(Root);

	Renderer3 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer3->SetupAttachment(Root);

	Renderer4 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer4->SetupAttachment(Root);

	Renderer5 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer5->SetupAttachment(Root);

	Collision0 = CreateDefaultSubObject<UCollision>("Collision");
	Collision0->SetupAttachment(Root);
	Collision0->SetScale(FVector(30.0f, 30.0f, 30.0f));
	Collision0->AddPosition(FVector(0.0f, -100.0f, 0.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision0->SetCollisionGroup(ECollisionOrder::PosCheck);
	Collision0->SetCollisionType(ECollisionType::Rect);

	Collision1 = CreateDefaultSubObject<UCollision>("Collision");
	Collision1->SetupAttachment(Root);
	Collision1->SetScale(FVector(30.0f, 30.0f, 30.0f));
	Collision1->AddPosition(FVector(130.0f, -100.0f, 0.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision1->SetCollisionGroup(ECollisionOrder::PosCheck);
	Collision1->SetCollisionType(ECollisionType::Rect);

	Collision2 = CreateDefaultSubObject<UCollision>("Collision");
	Collision2->SetupAttachment(Root);
	Collision2->SetScale(FVector(30.0f, 30.0f, 30.0f));
	Collision2->AddPosition(FVector(260.0f, -100.0f, 0.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision2->SetCollisionGroup(ECollisionOrder::PosCheck);
	Collision2->SetCollisionType(ECollisionType::Rect);


	SetRoot(Root);

}

ADarkEye::~ADarkEye()
{
}

void ADarkEye::BeginPlay()
{
	Super::BeginPlay();

	//Renderer0->CreateAnimation("DarkEye_Open", "darkeye", 0.0f, false, 0, 0);
	Renderer0->CreateAnimation("DarkEye_Closed", "darkeye", 0.0f, false, 1, 1);

	//Renderer1->CreateAnimation("DarkEye_Open", "darkeye", 0.0f, false, 0, 0);
	Renderer1->CreateAnimation("DarkEye_Closed", "darkeye", 0.0f, false, 1, 1);
	Renderer1->AddPosition(FVector(130.0f, 0.0f, 0.0f));
	
	//Renderer2->CreateAnimation("DarkEye_Open", "darkeye", 0.0f, false, 0, 0);
	Renderer2->CreateAnimation("DarkEye_Closed", "darkeye", 0.0f, false, 1, 1);
	Renderer2->AddPosition(FVector(260.0f, 0.0f, 0.0f));

	Renderer3->CreateAnimation("DarkEye_Open", "darkeye", 0.0f, false, 0, 0);

	Renderer4->CreateAnimation("DarkEye_Open", "darkeye", 0.0f, false, 0, 0);
	Renderer4->AddPosition(FVector(130.0f, 0.0f, 0.0f));

	Renderer5->CreateAnimation("DarkEye_Open", "darkeye", 0.0f, false, 0, 0);
	Renderer5->AddPosition(FVector(260.0f, 0.0f, 0.0f));


	Renderer0->ChangeAnimation("DarkEye_Closed");
	Renderer1->ChangeAnimation("DarkEye_Closed");
	Renderer2->ChangeAnimation("DarkEye_Closed");
	Renderer3->ChangeAnimation("DarkEye_Open");
	Renderer4->ChangeAnimation("DarkEye_Open");
	Renderer5->ChangeAnimation("DarkEye_Open");

	Renderer0->SetOrder(ERenderOrder::BackObject);
	Renderer1->SetOrder(ERenderOrder::BackObject);
	Renderer2->SetOrder(ERenderOrder::BackObject);
	Renderer3->SetOrder(ERenderOrder::Monster);
	Renderer4->SetOrder(ERenderOrder::Monster);
	Renderer5->SetOrder(ERenderOrder::Monster);
	
	Renderer0->SetAutoSize(1.0f, true);
	Renderer1->SetAutoSize(1.0f, true);
	Renderer2->SetAutoSize(1.0f, true);
	Renderer3->SetAutoSize(1.0f, true);
	Renderer4->SetAutoSize(1.0f, true);
	Renderer5->SetAutoSize(1.0f, true);

	//Renderer3->SetActive(false);
	//Renderer4->SetActive(false);
	//Renderer5->SetActive(false);
	//
}

void ADarkEye::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

			// 모든 랜더러가 off되면 매직유리길 생성
			if (false == Renderer3->IsActive() && false == Renderer4->IsActive() && false == Renderer5->IsActive())
			{
				if (false == UContentsConstValue::IsMagicGlassOn)
				{

					UEngineSound::SoundPlay("snd_locker_ch1.wav");
				}

				std::shared_ptr<AMagicalGlass> MagicGlass = GetWorld()->SpawnActor<AMagicalGlass>("MagicGlass");
				MagicGlass->SetActorLocation(FVector(9642.5f, -1422.0f, 0.0f));

				//플레이어가 유리길 갈수있게
				UContentsConstValue::IsMagicGlassOn = true;

				
			}
			

	Collision0->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			int a = 0;

			if (true == UEngineInput::IsDown(VK_SPACE) && false == Renderer3->IsActive() && false == Renderer5->IsActive())
			{
				int a = 0;
				UEngineSound::SoundPlay("snd_select_ch1.wav");

				Renderer3->SetActive(true);
				Renderer5->SetActive(true);

			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == Renderer3->IsActive() && true == Renderer5->IsActive())
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer3->SetActive(false);
				Renderer5->SetActive(false);
			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && false == Renderer3->IsActive() && true == Renderer5->IsActive())
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer3->SetActive(true);
				Renderer5->SetActive(false);
			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == Renderer3->IsActive() && false == Renderer5->IsActive())
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer3->SetActive(false);
				Renderer5->SetActive(true);
			}


		});

	Collision1->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			int a = 0;

			if (true == UEngineInput::IsDown(VK_SPACE) && false == Renderer3->IsActive() && false == Renderer4->IsActive())
			{
				int a = 0;
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer3->SetActive(true);
				Renderer4->SetActive(true);

			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == Renderer3->IsActive() && true == Renderer4->IsActive())
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer3->SetActive(false);
				Renderer4->SetActive(false);
			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && false == Renderer3->IsActive() && true == Renderer4->IsActive())
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer3->SetActive(true);
				Renderer4->SetActive(false);
			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == Renderer3->IsActive() && false == Renderer4->IsActive())
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer3->SetActive(false);
				Renderer4->SetActive(true);
			}


		});

	Collision2->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			int a = 0;

			if (true == UEngineInput::IsDown(VK_SPACE) && false == Renderer5->IsActive())
			{
				int a = 0;
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer5->SetActive(true);

			}
			else if (true == UEngineInput::IsDown(VK_SPACE) && true == Renderer5->IsActive())
			{
				UEngineSound::SoundPlay("snd_select_ch1.wav");
				Renderer5->SetActive(false);
			}
		
		});


}
