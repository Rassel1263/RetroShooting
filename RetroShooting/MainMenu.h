#pragma once
class MainMenu : public Object
{
public:
	Sprite spr;

	int inputNum = 0;

	std::vector<Sprite> button;
	std::vector<SpriteRI> ri;

	MainMenu();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void SetButton(Sprite& spr, SpriteRI& ri, int index);
};

