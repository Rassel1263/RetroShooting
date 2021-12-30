#pragma once
class Turret : public Enemy
{
public:
	float bulletTimer = 0.3f;

	Turret(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

