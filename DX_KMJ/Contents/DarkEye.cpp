#include "PreCompile.h"
#include "DarkEye.h"

ADarkEye::ADarkEye()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);


	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(30.0f, 30.0f, 30.0f));
	Collision->AddPosition(FVector(0.0f, -70.0f, 0.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision->SetCollisionGroup(ECollisionOrder::PosCheck);
	Collision->SetCollisionType(ECollisionType::Rect);


	SetRoot(Root);

}

ADarkEye::~ADarkEye()
{
}

void ADarkEye::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("DarkEye_Open", "darkeye", 0.0f, false, 0, 0);
	Renderer->CreateAnimation("DarkEye_Closed", "darkeye", 0.0f, false, 1, 1);

	Renderer->ChangeAnimation("DarkEye_Open");

	Renderer->SetOrder(ERenderOrder::Monster);
	Renderer->SetAutoSize(1.0f, true);


}

void ADarkEye::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
