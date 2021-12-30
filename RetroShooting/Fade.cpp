#include "DXUT.h"
#include "Fade.h"

Fade::Fade(int num)
{
	this->fadeNum = num;

	spr.LoadAll(L"Assets/Sprites/UI/FadeIn.png");
	ani.LoadAll(L"Assets/Sprites/Effect/GameStart");

	spr.isCamera = false;
	ani.isCamera = false;
	ani.aniLoop = false;

	if (num >= 2)
		spr.color.a = 0.0f;


	layer = 99;
}

void Fade::Update(float deltaTime)
{
	if (fadeNum == 1)
	{
		spr.color.a -= deltaTime * 0.3f;

		if (!ani.bAnimation)
			destroy = true;
	}
	else if (fadeNum == 2)
	{
		spr.color.a += deltaTime * 0.3f;

		if (spr.color.a >= 1.0f)
		{
			destroy = true;
			nowScene->obm.AddObject(new CalcPage());
		}

	}
	else if (fadeNum == 3)
	{
		spr.color.a += deltaTime * 0.3f;

		if(spr.color.a >= 1.0f)
			Game::GetInstance().ChangeScene(nowScene->nextScene);
	}

	ani.Update(deltaTime);
}

void Fade::Render()
{
	spr.Render(SpriteRI{D3DXVECTOR2(960, 540)});

	if(fadeNum == 1)
		ani.Render(SpriteRI{ D3DXVECTOR2(960, 540)});
}
