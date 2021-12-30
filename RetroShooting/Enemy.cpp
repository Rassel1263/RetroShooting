#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy(int enemyNum, D3DXVECTOR2 pos)
{
	this->pos = pos;
	this->enemyNum = enemyNum;

	tag = L"ENEMY";

	Collider2D::Square square;
	square.min = D3DXVECTOR2(-25, -39);
	square.max = D3DXVECTOR2(25, 39);
	bodies.push_back(Collider2D(this, tag, &square, 0));
}

void Enemy::Update(float deltaTime)
{
	if (isHit)
	{
		spr.color.g += deltaTime;
		spr.color.b += deltaTime;

		if (spr.color.g >= 1.0f)
			isHit = false;
	}
	OnDestroy();
}

void Enemy::Render()
{
	ri.pos = pos;
	spr.Render(ri);
	Object::Render();
}

void Enemy::OnCollision(const Collider2D& other)
{
	if (other.tag == L"BULLET")
	{
		if (static_cast<IBullet*>(other.object)->team != (int)Team::Enemy)
		{
			hp--;
			spr.color.g = spr.color.b = 0;
			isHit = true;
		}
	}
}

void Enemy::OnDestroy()
{
	if (hp <= 0)
	{
		nowScene->obm.AddObject(new Effect(L"EnemyDie", pos, { 1, 1 }));
		nowScene->PlusScore(100);
		nowScene->PlusCoin(pos, rand() % 6 + 5);
		destroy = true;
	}
}

bool Enemy::CheckPlayer(float distance)
{
	if (abs(pos.x - static_cast<GameScene*>(nowScene)->player->pos.x) <= distance)
	{
		if (static_cast<GameScene*>(nowScene)->player->pos.x - pos.x > 0.0f)
			dir = 1.0f;
		else
			dir = -1.0f;

		ri.scale.x = dir;

		return true;
	}
	return false;
}
