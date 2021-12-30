#include "DXUT.h"
#include "EPage.h"

EPage::EPage()
{
	spr.LoadAll(L"Assets/Sprites/UI/end.png");
	font.LoadAll(L"Assets/Sprites/UI/press.png");

	spr.color.a = 0.0f;
	font.color.a = 0.0f;
}

void EPage::Update(float deltaTime)
{
	spr.color.a += deltaTime * 0.3f;

	if (spr.color.a >= 1.0f)
	{
		font.color.a += deltaTime;

		if (font.color.a >= 1.0f)
			font.color.a = 0.0f;

		if (Input::GetInstance().GetKeyState(VK_RETURN) == InputState::Down)
		{
		}
	}
}

void EPage::Render()
{
	spr.Render(SpriteRI{ D3DXVECTOR2(960, 540) });
	font.Render(SpriteRI{ D3DXVECTOR2(960, 840) });
}
