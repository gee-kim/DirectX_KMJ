#pragma once
class Player_State
{
public : 
	Player_State();
	~Player_State();

	Player_State(const Player_State& _Other)				 = delete;
	Player_State(Player_State& _Other) noexcept				 = delete;
	Player_State& operator =(const Player_State& _Other)	 = delete;
	Player_State& operator =(Player_State& _Other) noexcept	 = delete;

protected:

private:
};

