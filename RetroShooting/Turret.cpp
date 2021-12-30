#include "DXUT.h"
#include "Turret.h"

Turret::Turret(D3DXVECTOR2 pos)
	:Enemy(2, pos + D3DXVECTOR2(0, 40))
{
	spr.LoadAll(L"Assets/Sprites/Enemy/2");

	hp = 7;
}

void Turret::Update(float deltaTime)
{
	bulletTimer -= deltaTime;

	if (CheckPlayer(200))
	{
		if (bulletTimer <= 0.0f)
		{
			bulletTimer = 1.0f;
			nowScene->obm.AddObject(new Bullet(L"Assets/Sprites/bullet", (int)Team::Enemy, D3DXVECTOR2(pos.x + 22 * dir, pos.y - 20),
				0, 700.0f, dir));
		}
	}

	Enemy::Update(deltaTime);
}

void Turret::Render()
{
	Enemy::Render();
}

void Turret::OnCollision(const Collider2D& other)
{
	Enemy::OnCollision(other);
}
