#pragma once
class DestructEnemy : public Enemy
{
public:
	bool contact = false;
	DestructEnemy(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

