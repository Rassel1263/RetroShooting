#pragma once
class Barrier : public Object
{
public:
	float timer = 0.0f;

	Enemy* target = NULL;

	Sprite spr;
	SpriteRI ri;

	Barrier(Enemy* target, D3DXVECTOR2 scale, float timer);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

