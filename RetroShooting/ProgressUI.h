#pragma once
class ProgressUI : public Object
{
public:
	Sprite smallP;
	Sprite progress;
	Sprite bPro;

	ProgressUI();

	virtual void Update(float deltaTime);
	virtual void Render();
};

