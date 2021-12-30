#pragma once
class DestEffect : public Object
{
public:
	bool firstMove = true;

	D3DXVECTOR2 destPos = { 0, 0 };

	Sprite spr;
	SpriteRI ri;

	DestEffect(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

