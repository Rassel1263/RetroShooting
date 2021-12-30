#pragma once
class CalcPage : public Object
{
public:
	Sprite spr;
	SpriteRI ri;

	float time = 0.0f;
	float score = 0.0f;
	float totalScore = 0.0f;
	float stopTimer = 3.0f;

	CalcPage();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void Calc(float& num, int numWeight);
};

