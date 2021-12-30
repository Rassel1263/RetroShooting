#pragma once
class Arsenal : public Object
{
public:
	bool openPanel = false;

	Sprite spr;
	SpriteRI ri;

	Arsenal(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

