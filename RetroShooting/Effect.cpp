#include "DXUT.h"
#include "Effect.h"

Effect::Effect(std::wstring eftName, D3DXVECTOR2 pos, D3DXVECTOR2 scale)
{
	this->pos = pos;
	eft.LoadAll(L"Assets/Sprites/Effect/" + eftName);
	eft.aniLoop = false;
}

void Effect::Update(float deltaTime)
{
	if (!eft.bAnimation)
		destroy = true;

	eft.Update(deltaTime);
}

void Effect::Render()
{
	ri.pos = pos;
	eft.Render(ri);
}
