#pragma once
class FlashEnemy : public Enemy
{
public:
	bool dash = false;
	float tempDir = 0.0f;
	float timer = 3.0f;
	float dashTime = 0.5f;

	FlashEnemy(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
};

