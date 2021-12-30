#include "DXUT.h"
#include "ShopPanel.h"

ShopPanel::ShopPanel(bool& openShop)
	:openPanel(openShop)
{
	spr.LoadAll(L"Assets/Sprites/UI/shop.png");
	spr.color.a = 0.0f;
	spr.isCamera = false;

	Game::GetInstance().timeScale = 0.0f;

	layer = 99;
}

void ShopPanel::Update(float deltaTime)
{
	if (openPanel)
	{
		if (spr.color.a < 0.9f)
			spr.color.a += Game::GetInstance().unScaleTime;

		if (Input::GetInstance().GetKeyState(VK_LBUTTON) == InputState::Down)
		{
			D3DXVECTOR2 mPos = Input::GetInstance().GetWorldMousePos();

			// ±âº» ±ÇÃÑ
			OnButton(337, 632, 623, 703, 10, 1); // ±¸¸Å
			OnButton(337, 779, 623, 849, 5, 1); // ÃÑ¾Ë ÃæÀü

			// ·¹ÀÌÀú ±ÇÃÑ
			OnButton(809, 632, 1096, 703, 30, 2); // ±¸¸Å
			OnButton(809, 779, 1096, 849, 15, 2); // ÃÑ¾ËÃæÀü

			// ¼¦°Ç
			OnButton(1291, 632, 1578, 703, 30, 3); // ±¸¸Å
			OnButton(1291, 779, 1578, 849, 15, 3); // ÃÑ¾ËÃæÀü

		}
	}
	else
	{
		spr.color.a -= Game::GetInstance().unScaleTime;

		if (spr.color.a <= 0.0f)
		{
			Game::GetInstance().timeScale = 1.0f;
			destroy = true;
		}
	}

	if (Input::GetInstance().GetKeyState(VK_ESCAPE) == InputState::Down)
	{
		openPanel = false;
	}


}

void ShopPanel::Render()
{
	spr.Render(SpriteRI{ D3DXVECTOR2(960, 540) });
}


void ShopPanel::OnButton(float left, float top, float right, float bottom, float coin, int weaponIndex)
{
	D3DXVECTOR2 mPos = Input::GetInstance().GetWorldMousePos();

	if (mPos.x > left && mPos.x < right && mPos.y > top && mPos.y < bottom)
	{
		if (nowScene->coin >= coin)
		{
			nowScene->coin -= coin;

			if (mPos.y > 632 && mPos.y < 703)
			{
				nowScene->player->weaponIndex = weaponIndex;

				switch (weaponIndex)
				{
				case 1:
					nowScene->player->maxBulletAmount = 50;
					break;
				case 2:
					nowScene->player->maxBulletAmount = 10;
					break;
				case 3:
					nowScene->player->maxBulletAmount = 15;
					break;
				}
			}

			nowScene->player->bulletAmount = nowScene->player->maxBulletAmount;
		}
	}
}
