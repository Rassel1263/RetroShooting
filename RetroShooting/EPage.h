#pragma once
class EPage : public Object
{
public:
	float timer = 3.0f;

	Sprite spr;
	SpriteRI ri;

	Sprite font;

	EPage();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

