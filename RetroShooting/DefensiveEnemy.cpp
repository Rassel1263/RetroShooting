#include "DXUT.h"
#include "DefensiveEnemy.h"

DefensiveEnemy::DefensiveEnemy(D3DXVECTOR2 pos)
	:Enemy(4, pos)
{
	hp = 20;

	spr.LoadAll(L"Assets/Sprites/Enemy/4");
}

void DefensiveEnemy::Update(float deltaTime)
{
	if (CheckPlayer(500))
	{
		timer -= deltaTime;

		if (timer <= 0.0f)
		{
			nowScene->obm.AddObject(new Barrier(this, { 1, 1 }, 3.0f));
			timer = 5.0f;
		}

		pos.x += deltaTime * speed * dir;
	}

	Enemy::Update(deltaTime);
}

void DefensiveEnemy::Render()
{
	Enemy::Render();
}

void DefensiveEnemy::OnCollision(const Collider2D& other)
{
	Enemy::OnCollision(other);
}
