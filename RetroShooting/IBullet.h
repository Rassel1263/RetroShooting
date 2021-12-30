#pragma once
class IBullet : public Object
{
public:
	int team;
	float angle;
	float speed;
public:
	Sprite spr;
	SpriteRI ri;

	IBullet();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

