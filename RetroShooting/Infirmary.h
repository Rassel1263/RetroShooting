#pragma once
class Infirmary : public Object 
{
public:
	bool heal = true;
	bool crash = false;

	Sprite font;

	Sprite spr;
	SpriteRI ri;

	Infirmary(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

