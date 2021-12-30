#include "DXUT.h"
#include "Obstacle.h"

Obstacle::Obstacle(D3DXVECTOR2 pos)
{
	this->pos = pos;
	spr.LoadAll(L"Assets/Sprites/Obstacle/1");

	Collider2D::Square square;

	square.min = { -175, -100 };
	square.max = { 175, 100 };
	bodies.push_back(Collider2D(this, L"OBSTACLE", &square, 0));
}

void Obstacle::Update(float deltaTime)
{
	if (isHit)
	{
		spr.color.g += deltaTime;
		spr.color.b += deltaTime;

		if (spr.color.g >= 1.0f)
			isHit = false;
	}

	if (hp <= 0)
	{
		spr.color.g = spr.color.b = 0;

		timer -= deltaTime;

		if (timer <= 0.0f)
		{
			eftAmount--;
			timer = 0.1f;
			nowScene->obm.AddObject(new Effect(L"Obstacle", pos + D3DXVECTOR2(rand() % 200 - 100, rand() % 100 - 50), D3DXVECTOR2(rand() % 3 + 1, rand() % 3 + 1)));
		}

		if (eftAmount < 0)
			destroy = true;
	}

	Object::Update(deltaTime);
}

void Obstacle::Render()
{
	ri.pos = pos;
	spr.Render(ri);
	Object::Render();
}

void Obstacle::OnCollision(const Collider2D& other)
{
	if (other.tag == L"BULLET")
	{
		if (static_cast<IBullet*>(other.object)->team == (int)Team::ally)
		{
			hp--;
			spr.color.g = spr.color.b = 0;
			isHit = true;
		}
	}
}
