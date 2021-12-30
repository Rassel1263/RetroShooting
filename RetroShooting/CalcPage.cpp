#include "DXUT.h"
#include "CalcPage.h"

CalcPage::CalcPage()
{
	spr.LoadAll(L"Assets/Sprites/UI/clear.png");
	spr.isCamera = false;
	
	this->score = nowScene->score;
	this->time = nowScene->gameTimer;

	layer = 10;

	nowScene->obm.AddObject(new Font(L"Score/", D3DXVECTOR2(800, 300), &this->score, 80, true, layer + 1, D3DXVECTOR2(0.7, 0.7)));
	nowScene->obm.AddObject(new Font(L"Score/", D3DXVECTOR2(800, 500), &this->time, 80, true, layer + 1, D3DXVECTOR2(0.7, 0.7)));
	nowScene->obm.AddObject(new Font(L"Score/", D3DXVECTOR2(800, 700), &nowScene->coin, 80, true, layer + 1, D3DXVECTOR2(0.7, 0.7)));
	nowScene->obm.AddObject(new Font(L"Score/", D3DXVECTOR2(1200, 900), &this->totalScore, 80, true, layer + 1));
}

void CalcPage::Update(float deltaTime)
{
	stopTimer -= deltaTime;

	if (stopTimer <= 0.0f)
	{
		if (score != 0)
			Calc(score, 1);
		else if (time != 0)
			Calc(time, 10);
		else if (nowScene->coin != 0)
			Calc(nowScene->coin, 500);
	}

	if (Input::GetInstance().GetKeyState(VK_RETURN) == InputState::Down && nowScene->coin == 0)
	{
		nowScene->score = totalScore;
		nowScene->destScore = totalScore;
		nowScene->obm.AddObject(new Fade(3));
	}
}

void CalcPage::Render()
{
	spr.Render(SpriteRI{ D3DXVECTOR2(960, 540) });
}

void CalcPage::Calc(float& num, int numWeight)
{
	if (num < 1.0f)
	{
		num = 0.0f;
		return;
	}

	int decreNum = 50.0f;

	if (num >= 10000.0f)
		decreNum = 50000.0f;
	else if (num >= 1000.0f)
		decreNum = 5000.0f;
	else if (num >= 100.0f)
		decreNum = 500.0f;

	float tempNum = num;
	num -= Game::GetInstance().unScaleTime * decreNum;

	totalScore += (tempNum - num) * numWeight;
}
