#include "DXUT.h"
#include "ResultPage.h"

ResultPage::ResultPage()
{
	spr.LoadAll(L"Assets/Sprites/UI/result.png");
	
	score = std::to_wstring((int)nowScene->score);
	nums.resize(score.size());

	for (int i = 0; i < score.size(); ++i)
		nums[i].LoadAll(L"Assets/Sprites/UI/Font/FinalScore/" + score.substr(i, 1) + L".png");

	ReadRanking();
}

void ResultPage::Update(float deltaTime)
{
	if (name.size() < 3)
	{
		for (char c = 'A'; c <= 'Z'; ++c)
		{
			if (Input::GetInstance().GetKeyState(c) == InputState::Down)
			{
				name += c;
				break;
			}
		}

		fonts.resize(name.size());

		for (int i = 0; name[i] != '\0'; ++i)
		{
			fonts[i].LoadAll(L"Assets/Sprites/UI/Font/Word/" + name.substr(i, 1) + L".png");
		}
	}
	else
	{
		WriteRanking();
	}

	if (!name.empty())
	{
		if (Input::GetInstance().GetKeyState(VK_BACK) == InputState::Down)
		{
			name.pop_back();
		}

	}


}

void ResultPage::Render()
{
	spr.Render(SpriteRI{ D3DXVECTOR2(960, 540) });

	for (int i = 0; i < nums.size(); ++i)
	{
		nums[i].Render(SpriteRI{ D3DXVECTOR2(950 + i * 120, 430) });
	}


	for (int i = 0; i < fonts.size(); ++i)
	{
		fonts[i].Render(SpriteRI{ D3DXVECTOR2(1100 + i * 250, 840) });
	}


	
}

void ResultPage::ReadRanking()
{
	std::wifstream fs(L"Assets/Data/RankingData.txt");
	std::wstring str;

	ranks.resize(3);

	if (fs.is_open())
	{
		for (int i = 0; i < 3; ++i)
		{
			fs >> ranks[i].score;
			fs >> ranks[i].initial;
		}
	}
}

void ResultPage::WriteRanking()
{
	if (Input::GetInstance().GetKeyState(VK_RETURN) == InputState::Down)
	{
		std::wofstream os(L"Assets/Data/RankingData.txt");

		RankInfo temp;
		temp.initial = name;
		temp.score = nowScene->score;

		ranks.push_back(temp);
		std::sort(ranks.begin(), ranks.end(), [](const RankInfo& lhs, const RankInfo& rhs) { return lhs.score > rhs.score; });

		ranks.erase(ranks.end() - 1);

		for (int i = 0; i < 3; ++i)
		{
			os << ranks[i].score << std::endl;
			os << ranks[i].initial << std::endl;
		}

		Game::GetInstance().ChangeScene(nowScene->nextScene);
	}
}
