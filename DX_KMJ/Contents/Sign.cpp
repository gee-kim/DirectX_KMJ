#include "PreCompile.h"
#include "Sign.h"


ASign::ASign()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Collision = CreateDefaultSubObject<UCollision>("Collisioin");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(50.0f, 50.0f, 50.0f));
	// �ݸ����� ������ ������ ��������� �Ѵ�.
	Collision->SetCollisionGroup(ECollisionOrder::PosCheck);
	Collision->SetCollisionType(ECollisionType::Rect);

	SetRoot(Root);

}

ASign::~ASign()
{
}

void ASign::BeginPlay()
{
	Super::BeginPlay();

	
}

void ASign::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Collision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Col)
		{
			Widget->SetTextBoxOn();
			Widget->SetTextScript("* �̰�����, ��ҿ� ���� �� �ڵ鸸��\n   ���� �� �� �ִ�... ");
			
		});
}