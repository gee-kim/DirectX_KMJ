#include "PreCompile.h"
#include "DustPile.h"

ADustPile::ADustPile()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	int Size = 15;

	for (int i = 0; i < Size; i++)
	{
		USpriteRenderer* Renderer_i = CreateDefaultSubObject<USpriteRenderer>("Renderer");
		Renderer_i->SetupAttachment(Root);
		Renderer_i->SetPivot(EPivot::BOT);
		Renderers.push_back(Renderer_i);
		

	}
		int a = 0;
	//
	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}
	//// 버블들
	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}

	//{
	//	USpriteRenderer* Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//	Renderer->SetupAttachment(Root);
	//	Renderer->SetPivot(EPivot::BOT);
	//	Renderers.push_back(Renderer);
	//}


	SetRoot(Root);

}

ADustPile::~ADustPile()
{
}

void ADustPile::BeginPlay()
{
	Super::BeginPlay();

	// 기본 더스트 이미지
	Renderers[0]->CreateAnimation("DustPile_Idle", "dustpile", 0.0f, false, 0);

	// 더스트 파츠들
	//원하는 사진만 반복하려면 {} 안에 시간이랑 사진번호 둘다 넣어줘야함.
	Renderers[1]->CreateAnimation("DustPile_Up", "dustpile", { 0.4f, 0.4f }, { 0, 1 }, true);
	Renderers[2]->CreateAnimation("DustPile_Left", "dustpile", { 0.4f, 0.6f }, { 0, 2 }, true);
	Renderers[3]->CreateAnimation("DustPile_Right", "dustpile", { 0.4f, 0.8f }, { 0, 3 }, true);
	Renderers[4]->CreateAnimation("DustPile_Mid", "dustpile", { 0.8f, 0.4f }, { 0, 4 }, true);
	Renderers[5]->CreateAnimation("DustPile_Bot", "dustpile", 0.0f, false, 5);

	//더스트 버블들
	Renderers[6]->CreateAnimation("DustBall_0", "dustball", { 0.8f, 0.8f }, { 0, 1 }, true);
	Renderers[7]->CreateAnimation("DustBall_0", "dustball", { 0.8f, 0.8f }, { 1, 0 }, true);
	Renderers[8]->CreateAnimation("DustBall_1", "dustball", { 0.8f, 0.8f }, { 0, 1 }, true);
	Renderers[9]->CreateAnimation("DustBall_1", "dustball", { 0.8f, 0.8f }, { 1, 0 }, true);
	Renderers[10]->CreateAnimation("DustBall_2", "dustball",  { 0.8f, 0.8f }, {  1, 2 }, true);
	Renderers[11]->CreateAnimation("DustBall_2", "dustball",  { 0.8f, 0.8f }, {  2, 1 }, true);
	Renderers[12]->CreateAnimation("DustBall_3", "dustball",  { 0.8f, 0.8f }, {  2, 3 }, true);
	Renderers[13]->CreateAnimation("DustBall_3", "dustball",  { 0.8f, 0.8f }, {  3, 2 }, true);


	Renderers[0]->ChangeAnimation("DustPile_Idle");
	Renderers[1]->ChangeAnimation("DustPile_Up");
	Renderers[2]->ChangeAnimation("DustPile_Left");
	Renderers[3]->ChangeAnimation("DustPile_Right");
	Renderers[4]->ChangeAnimation("DustPile_Mid");
	//Renderers[5]->ChangeAnimation("DustPile_Bot");

	Renderers[6]->ChangeAnimation("DustBall_0");
	Renderers[7]->ChangeAnimation("DustBall_0");
	Renderers[8]->ChangeAnimation("DustBall_1");
	Renderers[9]->ChangeAnimation("DustBall_1");
	Renderers[10]->ChangeAnimation("DustBall_2");
	Renderers[11]->ChangeAnimation("DustBall_2");
	Renderers[12]->ChangeAnimation("DustBall_3");
	Renderers[13]->ChangeAnimation("DustBall_3");



	Renderers[0]->SetOrder(ERenderOrder::BackObject);
	Renderers[1]->SetOrder(ERenderOrder::BackObject);
	Renderers[2]->SetOrder(ERenderOrder::BackObject);
	Renderers[3]->SetOrder(ERenderOrder::BackObject);
	Renderers[4]->SetOrder(ERenderOrder::BackObject);
	//Renderers[5]->SetOrder(ERenderOrder::BackObject);

	Renderers[6]->SetOrder(ERenderOrder::BackObject);
	Renderers[7]->SetOrder(ERenderOrder::BackObject);
	Renderers[8]->SetOrder(ERenderOrder::BackObject);
	Renderers[9]->SetOrder(ERenderOrder::BackObject);
	Renderers[10]->SetOrder(ERenderOrder::BackObject);
	Renderers[11]->SetOrder(ERenderOrder::BackObject);
	Renderers[12]->SetOrder(ERenderOrder::BackObject);
	Renderers[13]->SetOrder(ERenderOrder::BackObject);


	Renderers[0]->SetAutoSize(1.8f, true);
	Renderers[1]->SetAutoSize(1.8f, true);
	Renderers[2]->SetAutoSize(1.8f, true);
	Renderers[3]->SetAutoSize(1.8f, true);
	Renderers[4]->SetAutoSize(1.8f, true);
	//Renderers[5]->SetAutoSize(1.8f, true);

	Renderers[6]->SetAutoSize(1.5f, true);
	Renderers[7]->SetAutoSize(1.5f, true);
	Renderers[8]->SetAutoSize(1.5f, true);
	Renderers[9]->SetAutoSize(1.5f, true);
	Renderers[10]->SetAutoSize(1.5f, true);
	Renderers[11]->SetAutoSize(1.5f, true);
	Renderers[12]->SetAutoSize(1.5f, true);
	Renderers[13]->SetAutoSize(1.5f, true);



	Renderers[6]->AddPosition(FVector(30.0f, 100.0f, 0.0f));
	Renderers[7]->AddPosition(FVector(45.0f, 105.0f, 0.0f));
	Renderers[8]->AddPosition(FVector(60.0f, 102.0f, 0.0f));
	Renderers[9]->AddPosition(FVector(75.0f, 107.0f, 0.0f));
	Renderers[10]->AddPosition(FVector(90.0f, 105.0f, 0.0f));
	Renderers[11]->AddPosition(FVector(105.0f, 102.0f, 0.0f));
	Renderers[12]->AddPosition(FVector(130.0f, 100.0f, 0.0f));
	Renderers[13]->AddPosition(FVector(145.0f, 105.0f, 0.0f));

	//Part4->SetOrder(ERenderOrder::BackObject);
	//Part4->SetAutoSize(1.8f, true);

}

void ADustPile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Time += _DeltaTime * 1.0f;

	Count = Time;

	if (Count % 2)
	{
		Renderers[6]->SetActive(true);
		Renderers[7]->SetActive(false);
		Renderers[8]->SetActive(true);
		Renderers[9]->SetActive(false);
		Renderers[10]->SetActive(true);
		Renderers[11]->SetActive(false);
		Renderers[12]->SetActive(true);
		Renderers[13]->SetActive(false);
	}
	else
	{
		Renderers[6]->SetActive(false);
		Renderers[7]->SetActive(true);
		Renderers[8]->SetActive(false);
		Renderers[9]->SetActive(true);
		Renderers[10]->SetActive(false);
		Renderers[11]->SetActive(true);
		Renderers[12]->SetActive(false);
		Renderers[13]->SetActive(true);
	}



}
