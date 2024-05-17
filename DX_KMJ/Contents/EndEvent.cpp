#include "PreCompile.h"
#include "EndEvent.h"

AEndEvent::AEndEvent()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Collision = CreateDefaultSubObject<UCollision>("Collisioin");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(50.0f, 100.0f, 50.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision->SetCollisionGroup(ECollisionOrder::EndCheck);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);
}

AEndEvent::~AEndEvent()
{
}

void AEndEvent::BeginPlay()
{
	Super::BeginPlay();


}

void AEndEvent::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
