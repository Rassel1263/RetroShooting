#include "DXUT.h"
#include "Header.h"

IBullet::IBullet()
{
	layer = 2;
}

void IBullet::Update(float deltaTime)
{
	ri.rotate = -D3DXToDegree(angle);

	pos += D3DXVECTOR2(cosf(angle), sinf(angle)) * speed * deltaTime;

	if (pos.x >= Game::GetInstance().cameraPos.x + 1920 || pos.x <= Game::GetInstance().cameraPos.x - 1920)
	{
		destroy = true;
	}

	spr.Update(deltaTime);
}

void IBullet::Render()
{
	ri.pos = pos;
	spr.Render(ri);
	Object::Render();
}

void IBullet::OnCollision(const Collider2D& other)
{
	if (team == (int)Team::ally)
	{
		if (other.tag == L"ENEMY" || other.tag == L"OBSTACLE")
		{
			if(nowScene->player->weaponIndex != 2)
				destroy = true;

			nowScene->obm.AddObject(new Effect(L"Hit", pos, { 1, 1 }));
		}
	}

	/*if (team == (int)Team::Enemy)
	{
		if (other.tag == L"PLAYER")
			destroy = true;
	}*/
}

