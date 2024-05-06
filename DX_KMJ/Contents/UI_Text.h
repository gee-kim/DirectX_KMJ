#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Image.h>
#include <EngineCore/TextWidget.h>

// Ό³Έν :
class UI_Text : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	UI_Text();
	~UI_Text();

	// delete Function
	UI_Text(const UI_Text& _Other) = delete;
	UI_Text(UI_Text&& _Other) noexcept = delete;
	UI_Text& operator=(const UI_Text& _Other) = delete;
	UI_Text& operator=(UI_Text&& _Other) noexcept = delete;
	

	void SetScript();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImage* TextBox = nullptr;
	UTextWidget* Script = nullptr;

	
};
