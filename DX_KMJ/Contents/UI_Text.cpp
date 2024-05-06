#include "PreCompile.h"
#include "UI_Text.h"

UI_Text::UI_Text()
{
}

UI_Text::~UI_Text()
{
}

void UI_Text::BeginPlay()
{
	Super::BeginPlay();

	TextBox = CreateWidget<UImage>(GetWorld(), "TextBox");
	//TextBox->SetupAttachment(this);
	TextBox->SetSprite("textbox.png");
	TextBox->SetAutoSize(2.5f, true);
	TextBox->SetPosition({ 0, 200 });
	// setactive ¾È¸ÔÀ½...
	//TextBox->SetActive(false);


}


void UI_Text::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}






