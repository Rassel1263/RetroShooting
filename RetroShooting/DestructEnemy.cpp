#include "DXUT.h"
#include "DestructEnemy.h"

DestructEnemy::DestructEnemy(D3DXVECTOR2 pos)
	:Enemy(3, pos)
{
	hp = 5;

	spr.LoadAll(L"Assets/Sprites/Enemy/3");
}

void DestructEnemy::Update(float deltaTime)
{
	if (CheckPlayer(200))
	{
		pos.x += deltaTime * speed * dir;
	}

	if (!isHit)
	{
		if (contact)
		{
			spr.color.g = spr.color.b -= deltaTime;

			if (spr.color.g <= 0.0f)
			{
				nowScene->obm.AddObject(new Effect(L"EnemyDie", pos, { 1, 1 }));
				nowScene->player->hp--;
				destroy = true;
			}
		}
		else
			spr.color.g = spr.color.b += deltaTime;
	}

	contact = false;

	Enemy::Update(deltaTime);
}

void DestructEnemy::Render()
{
	Enemy::Render();
}

void DestructEnemy::OnCollision(const Collider2D& other)
{
	if (other.tag == L"PLAYER")
	{
		contact = true;
	}

	Enemy::OnCollision(other);
}
