#pragma once
class Enemy : public Object
{
public:
	bool isHit = false;
	float dir = 1;
	float hp = 3;
	float speed = 100;
	float bulletTimer = 0.3f;
	int enemyNum = 1;

	Sprite spr;
	SpriteRI ri;

	Enemy(int enemyNum, D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
	virtual void OnDestroy();

	bool CheckPlayer(float distance);
};

