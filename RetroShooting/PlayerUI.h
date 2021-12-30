#pragma once
class PlayerUI : public Object
{
public:
	Sprite ui;
	Sprite gunUi[3];

	Sprite hpBar;
	SpriteRI hpRi;

	Sprite spBar;
	SpriteRI spRi;

	Sprite coin;

	PlayerUI();

	virtual void Update(float deltaTime) override;
	virtual void Render();
};

