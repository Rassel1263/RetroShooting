#pragma once
class Bullet : public IBullet
{
public:
	Bullet(std::wstring name, int team, D3DXVECTOR2 pos, float angle, float speed, float xRot);

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void OnCollision(const Collider2D& other);
};

