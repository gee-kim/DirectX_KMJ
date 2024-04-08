#pragma once
class Template
{
public : 
	Template();
	~Template();

	Template(const Template& _Other)				 = delete;
	Template(Template& _Other) noexcept				 = delete;
	Template& operator =(const Template& _Other)	 = delete;
	Template& operator =(Template& _Other) noexcept	 = delete;

protected:

private:
};

