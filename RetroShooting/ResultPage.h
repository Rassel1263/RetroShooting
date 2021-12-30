#pragma once

struct RankInfo
{
	int score = 0;
	std::wstring initial = L"NONE";
};

class ResultPage : public Object
{
public:
	Sprite spr;
	std::vector<Sprite> fonts;
	std::vector<Sprite> nums;
	std::vector<RankInfo> ranks;

	std::wstring name;
	std::wstring score;

	ResultPage();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void ReadRanking();
	void WriteRanking();
};

