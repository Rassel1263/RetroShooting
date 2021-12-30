#include "DXUT.h"
#include "Barrier.h"

Barrier::Barrier(Enemy* target, D3DXVECTOR2 scale, float timer)
{
	this->pos = pos;
	ri.scale = scale;
	this->timer = timer;
	this->target = target;
	spr.color.a = 0.5f;

	spr.LoadAll(L"Assets/Sprites/Enemy/Shield.png");

	Collider2D::Square square;
	square.min = D3DXVECTOR2(-100, -100);
	square.max = D3DXVECTOR2(100, 100);
	bodies.push_back(Collider2D(this, L"Barrier", &square, 0));
}

void Barrier::Update(float deltaTime)
{
	this->pos = target->pos;
	timer -= deltaTime;

	if (timer <= 0.0f)
		destroy = true;
}

void Barrier::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}

void Barrier::OnCollision(const Collider2D& other)
{
	if (other.tag == L"BULLET")
	{
		if (static_cast<IBullet*>(other.object)->team == (int)Team::ally)
			other.object->destroy = true;
	}
}
