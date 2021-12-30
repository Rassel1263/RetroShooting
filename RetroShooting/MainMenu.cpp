#include "DXUT.h"
#include "MainMenu.h"

MainMenu::MainMenu()
{
	spr.LoadAll(L"Assets/Sprites/Background/mainbg.png");

	button.resize(4);
	ri.resize(4);

	for (int i = 0; i < 4; ++i)
	{
		button[i].LoadAll(L"Assets/Sprites/UI/Button/" + std::to_wstring(i));
		ri[i].pos = { 960, 500 + (float)i * 120 };
	}
}

void MainMenu::Update(float deltaTime)
{
	for (int i = 0; i < 4; ++i)
		SetButton(button[i], ri[i], i);

	if (!static_cast<MainScene*>(nowScene)->inputKey)
		return;

	if (Input::GetInstance().GetKeyState(VK_DOWN) == InputState::Down)
	{
		inputNum++;

		if (inputNum > 3)
			inputNum = 0;
	}

	if (Input::GetInstance().GetKeyState(VK_UP) == InputState::Down)
	{
		inputNum--;

		if (inputNum < 0)
			inputNum = 3;
	}

	if (Input::GetInstance().GetKeyState(VK_RETURN) == InputState::Down)
	{
		static_cast<MainScene*>(nowScene)->inputKey = false;

		switch (inputNum)
		{
		case 0:
			Game::GetInstance().ChangeScene(nowScene->nextScene);
			break;
		case 1:
			nowScene->obm.AddObject(new RankingPage());
			break;
		case 2:
			// ´õ¿ò¸»
			break;
		case 3:
			PostQuitMessage(0);
			break;
		}
	}

}

void MainMenu::Render()
{
	spr.Render(SpriteRI{ D3DXVECTOR2(960, 540) });

	for (int i = 0; i < 4; ++i)
		button[i].Render(ri[i]);
}

void MainMenu::SetButton(Sprite& spr, SpriteRI& ri, int index)
{
	if (inputNum == index)
	{
		spr.scene = 0;
		D3DXVec2Lerp(&ri.scale, &ri.scale, &D3DXVECTOR2(1.2f, 1.2f), 0.1f);
	}
	else
	{
		spr.scene = 1;
		D3DXVec2Lerp(&ri.scale, &ri.scale, &D3DXVECTOR2(1.0f, 1.0f), 0.1f);
	}
}
