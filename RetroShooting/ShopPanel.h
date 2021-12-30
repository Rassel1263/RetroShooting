#pragma once
class ShopPanel : public Object
{
public:
	bool closePanel = false;
	bool& openPanel;

	Sprite spr;

	ShopPanel(bool& openShop);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	void OnButton(float left, float top, float right, float bottom, float coin, int weaponIndex);
};

