#include "DXUT.h"
#include "RushEnemy.h"

RushEnemy::RushEnemy(D3DXVECTOR2 pos)
	:Enemy(1, pos)
{
	hp = 10;

	spr.LoadAll(L"Assets/Sprites/Enemy/1");
}

void RushEnemy::Update(float deltaTime)
{
	if (CheckPlayer(100))
	{
		pos.x += deltaTime * speed * dir;
	}

	Enemy::Update(deltaTime);
}

void RushEnemy::Render()
{
	Enemy::Render();
}

void RushEnemy::OnCollision(const Collider2D& other)
{
	Enemy::OnCollision(other);
}
