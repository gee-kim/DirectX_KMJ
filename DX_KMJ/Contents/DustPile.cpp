#include "PreCompile.h"
#include "DustPile.h"

ADustPile::ADustPile()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetPivot(EPivot::BOT);

	Part0 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Part0->SetupAttachment(Root);
	Part0->SetPivot(EPivot::BOT);

	Part1 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Part1->SetupAttachment(Root);
	Part1->SetPivot(EPivot::BOT);

	Part2 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Part2->SetupAttachment(Root);
	Part2->SetPivot(EPivot::BOT);

	Part3 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Part3->SetupAttachment(Root);
	Part3->SetPivot(EPivot::BOT);

	Part4 = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Part4->SetupAttachment(Root);
	Part4->SetPivot(EPivot::BOT);


	SetRoot(Root);

}

ADustPile::~ADustPile()
{
}

void ADustPile::BeginPlay()
{
	Super::BeginPlay();

	//Renderer->CreateAnimation("DustPile_Idle", "dustpile", 0.0f, false, 0);

	//원하는 사진만 반복하려면 {} 안에 시간이랑 사진번호 둘다 넣어줘야함.
	Part0->CreateAnimation("DustPile_Up", "dustpile", {0.4f, 0.4f}, { 1, 4 }, true);

	//Part1->CreateAnimation("DustPile_Left", "dustpile", 0.4f, true, 0, 2);
	//Part2->CreateAnimation("DustPile_Right", "dustpile", 0.4f, true, 0, 3);
	//Part3->CreateAnimation("DustPile_Mid", "dustpile", 0.4f, true, 0, 4);
	//Part4->CreateAnimation("DustPile_Bot", "dustpile", 0.4f, true, (0, 5));

	//Renderer->ChangeAnimation("DustPile_Idle");
	Part0->ChangeAnimation("DustPile_Up");
	//Part1->ChangeAnimation("DustPile_Left");
	//Part2->ChangeAnimation("DustPile_Right");
	//Part3->ChangeAnimation("DustPile_Mid");
	//Part4->ChangeAnimation("DustPile_Bot");

	Renderer->SetOrder(ERenderOrder::BackObject);
	Renderer->SetAutoSize(1.8f, true);

	Part0->SetOrder(ERenderOrder::BackObject);
	Part0->SetAutoSize(1.8f, true);

	//Part1->SetOrder(ERenderOrder::BackObject);
	//Part1->SetAutoSize(1.8f, true);

	//Part2->SetOrder(ERenderOrder::BackObject);
	//Part2->SetAutoSize(1.8f, true);

	//Part3->SetOrder(ERenderOrder::BackObject);
	//Part3->SetAutoSize(1.8f, true);

	//Part4->SetOrder(ERenderOrder::BackObject);
	//Part4->SetAutoSize(1.8f, true);

}

void ADustPile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
