#include "DXUT.h"
#include "FlashEnemy.h"

FlashEnemy::FlashEnemy(D3DXVECTOR2 pos)
	:Enemy(5, pos)
{
	hp = 30;

	spr.LoadAll(L"Assets/Sprites/Enemy/5");
}

void FlashEnemy::Update(float deltaTime)
{
	if (CheckPlayer(1000))
	{
		timer -= deltaTime;

		if (timer <= 0.0f)
		{
			dash = true;
			dashTime -= deltaTime;
			speed = 1000;

			if (dashTime <= 0.0f)
			{
				dash = false;
				speed = 100;
				timer = 3.0f;
				dashTime = 0.5f;
			}
		}

		if (!dash)
		{
			pos.x += deltaTime * speed * dir;
			tempDir = dir;
		}
		else
		{
			ri.scale.x = tempDir;
			pos.x += deltaTime * speed * tempDir;
		}
	}

	Enemy::Update(deltaTime);
}

void FlashEnemy::Render()
{
	Enemy::Render();
}

void FlashEnemy::OnCollision(const Collider2D& other)
{
	Enemy::OnCollision(other);
}
