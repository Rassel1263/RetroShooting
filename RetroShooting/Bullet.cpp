#include "DXUT.h"
#include "Header.h"

Bullet::Bullet(std::wstring name, int team, D3DXVECTOR2 pos, float angle, float speed, float xRot)
{
	spr.LoadAll(name);
	this->team = team;
	this->pos = pos;
	this->angle = D3DXToRadian(angle);
	this->speed = speed * xRot;
	ri.scale.x = xRot;

	Collider2D::Square square;
	square.min = { -10, -10 };
	square.max = { 10, 10 };
	bodies.push_back(Collider2D(this, L"BULLET", &square, 0));
}

void Bullet::Update(float deltaTime)
{
	IBullet::Update(deltaTime);
}

void Bullet::Render()
{
	IBullet::Render();
}

void Bullet::OnCollision(const Collider2D& other)
{
	IBullet::OnCollision(other);
}
