#include "DXUT.h"
#include "Unit.h"

Unit::Unit()
{
	tag = L"Units";
}

void Unit::Update(float deltaTime)
{
	spr[renderNum].Update(deltaTime);
	Object::Update(deltaTime);
}

void Unit::Render()
{
	ri.pos = pos;
	spr[renderNum].Render(ri);
	Object::Render();
}

void Unit::OnCollision(const Collider2D& other)
{
}

bool Unit::Move()
{
	return false;
}

void Unit::Shoot(std::wstring name, D3DXVECTOR2 pos, float bulletSpd)
{
	if (bulletAmount <= 0)
		return;

	bulletAmount--;

	if (weaponIndex < 3)
		nowScene->obm.AddObject(new Bullet(name, (int)team, pos, angle, bulletSpd, ri.scale.x * 0.5f));

	if (weaponIndex == 3)
	{
		int c = rand() % 4 + 3;

		for (int i = 0; i < c; i++)
			nowScene->obm.AddObject(new Bullet(name, (int)team, pos,
				angle + (rand() % 15 + 1) * ((float)i / (c - 1) - 0.5f), rand()% 100 + 1200, ri.scale.x * 0.5f));
	}
}

void Unit::SetAni(int index)
{
	if (index < states.size())
	{
		renderNum = index;
	}
}

void Unit::ResetAni()
{
	spr[renderNum].Reset();
}

Sprite& Unit::GetData()
{
	return spr[renderNum];
}
