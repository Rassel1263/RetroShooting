#include "DXUT.h"

RankingPage::RankingPage()
{
	spr.LoadAll(L"Assets/Sprites/UI/ranking.png");

	std::wifstream fs(L"Assets/Data/RankingData.txt");
	std::wstring str;

	ranks.resize(3);

	for (int i = 0; i < 3; ++i)
		fonts[i].resize(3);

	if (fs.is_open())
	{
		for (int i = 0; i < 3; ++i)
		{
			fs >> ranks[i].score;
			fs >> ranks[i].initial;
		}
	}

	std::sort(ranks.begin(), ranks.end(), [](const RankInfo& lhs, const RankInfo& rhs) { return lhs.score > rhs.score; });

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			fonts[i][j].LoadAll(L"Assets/Sprites/UI/Font/Word/" + ranks[i].initial.substr(j, 1) + L".png");
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		std::wstring str = std::to_wstring(ranks[i].score);
		nums[i].resize(str.size());

		for (int j = 0; j < str.size(); ++j)
			nums[i][j].LoadAll(L"Assets/Sprites/UI/Font/FinalScore/" + str.substr(j, 1) + L".png");
	}
}

void RankingPage::Update(float deltaTime)
{
	if (Input::GetInstance().GetKeyState(VK_ESCAPE) == InputState::Down)
	{
		static_cast<MainScene*>(nowScene)->inputKey = true;
		destroy = true;
	}
}

void RankingPage::Render()
{
	spr.Render(SpriteRI{ D3DXVECTOR2(960, 540) });

	int yPos = 0;

	for (int i = 0; i < 3; ++i)
	{
		int xPos = 0;

		for (int j = 0; j < 3; ++j)
		{
			fonts[i][j].Render(SpriteRI{ D3DXVECTOR2(700 + xPos * 130, 400 + yPos * 220), D3DXVECTOR2(0.5, 0.5) });

			xPos++;
		}

		xPos = 0;
		for (int j = 0; j < nums[i].size(); ++j)
		{
			nums[i][j].Render(SpriteRI{ D3DXVECTOR2(1200 + xPos * 100, 400 + yPos * 220) });

			xPos++;
		}

		yPos++;
	}
}
