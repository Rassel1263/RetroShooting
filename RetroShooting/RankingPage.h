#pragma once
class RankingPage : public Object
{
public:
	Sprite spr;

	std::vector<RankInfo> ranks;

	std::vector<Sprite> fonts[3];
	std::vector<Sprite> nums[3];

	RankingPage();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

