#include "DXUT.h"
#include "Infirmary.h"

Infirmary::Infirmary(D3DXVECTOR2 pos)
{
	this->pos = pos;
	spr.LoadAll(L"Assets/Sprites/Room/Infirmary.png");
	font.LoadAll(L"Assets/Sprites/UI/heal.png");

	Collider2D::Square square;
	square.min = D3DXVECTOR2(-122, -87);
	square.max = D3DXVECTOR2(122, 87);
	bodies.push_back(Collider2D(this, tag, &square, 0));
}

void Infirmary::Update(float deltaTime)
{
	crash = false;
}

void Infirmary::Render()
{
	ri.pos = pos;
	spr.Render(ri);
	
	if (crash)
		font.Render(SpriteRI{ D3DXVECTOR2(pos.x, pos.y - 200) });

	Object::Render();
}

void Infirmary::OnCollision(const Collider2D& other)
{
	if (other.tag == L"PLAYER")
	{
		crash = true;

		if (Input::GetInstance().GetKeyState(VK_UP) == InputState::Down)
		{
			if (nowScene->coin >= 10)
			{
				nowScene->player->hp = nowScene->player->maxHp;
				nowScene->coin -= 10;
			}
		}

		if (heal)
		{
			heal = false;
			nowScene->player->hp = nowScene->player->maxHp;
		}
	}
}
