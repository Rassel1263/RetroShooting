#pragma once
class DefensiveEnemy : public Enemy
{
public:
	float timer = 5.0f;

	DefensiveEnemy(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

