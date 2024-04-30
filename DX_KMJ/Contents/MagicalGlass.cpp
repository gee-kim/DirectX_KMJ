#include "PreCompile.h"
#include "MagicalGlass.h"

AMagicalGlass::AMagicalGlass()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);


	//Collision = CreateDefaultSubObject<UCollision>("Collision");
	//Collision->SetupAttachment(Root);
	//Collision->SetScale(FVector(30.0f, 30.0f, 30.0f));
	//Collision->AddPosition(FVector(0.0f, -70.0f, 0.0f));
	//// 콜리전은 무조건 오더를 지정해줘야 한다.
	//Collision->SetCollisionGroup(ECollisionOrder::PosCheck);
	//Collision->SetCollisionType(ECollisionType::Rect);


	SetRoot(Root);
}

AMagicalGlass::~AMagicalGlass()
{
}

void AMagicalGlass::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("magicglass.png");
		
	Renderer->SetOrder(ERenderOrder::BackObject);
	Renderer->SetAutoSize(2.2f, true);


}

void AMagicalGlass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
