#pragma once
class Obstacle : public Object
{
public:
	bool isHit = false;
	float timer = 0.1f;
	float hp = 10;
	int eftAmount = 30;
	Sprite spr;
	SpriteRI ri;

	Obstacle(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

