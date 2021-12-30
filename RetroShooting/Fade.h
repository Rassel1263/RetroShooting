#pragma once
class Fade : public Object
{
public:
	int fadeNum = 0;

	Sprite spr;
	Sprite ani;

	Fade(int num);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

