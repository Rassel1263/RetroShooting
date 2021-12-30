#include "DXUT.h"
#include "EnemyUI.h"

EnemyUI::EnemyUI(Enemy* target)
{
	this->target = target;

	spr.LoadAll(L"Assets/Sprites/UI/smallE.png");
	spr.isCamera = false;
	pos.y = 950;
}

void EnemyUI::Update(float deltaTime)
{
	pos.x = 60 + target->pos.x / nowScene->endWorldPos * 1800;

	if (target->destroy)
		destroy = true;
}

void EnemyUI::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
