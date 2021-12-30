#include "DXUT.h"
#include "DestEffect.h"

DestEffect::DestEffect(D3DXVECTOR2 pos)
{
	this->pos = pos;
	this->destPos = pos + D3DXVECTOR2(float(rand() % 50 - 25), float(rand() % 50- 25));

	spr.LoadAll(L"Assets/Sprites/UI/destCoin.png");
	ri.scale = { 0.3f, 0.3f };
}

void DestEffect::Update(float deltaTime)
{
	if (firstMove)
	{
		D3DXVec2Lerp(&pos, &pos, &destPos, 0.02f);

		if (abs(destPos.x - pos.x) < 1 && abs(destPos.y - pos.y) < 1)
		{
			firstMove = false;
		}
	}
	else
	{
		destPos = nowScene->player->pos;
		D3DXVec2Lerp(&pos, &pos, &destPos, 0.1f);

		if (abs(destPos.x - pos.x) <= 1 && abs(destPos.y - pos.y) <= 1)
		{
			destroy = true;
			nowScene->coin++;
		}
	}
	
}

void DestEffect::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}

