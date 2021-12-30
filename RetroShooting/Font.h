#pragma once
class Font : public Object
{
public:
	bool leftAlign = false;

	float notChangeData = 0;
	float* data = NULL;
	float invisibleTime = 0.0f;
	float invisibleTimer = 0.0f;
	float scaleNum = 1.0f;
	float tracking = 0.0f;

	int fontNum = 0;
	std::vector<Sprite> sprites;
	std::wstring fontName;
	SpriteRI ri;

	Font(std::wstring fontName, D3DXVECTOR2 pos, float data, float tracking, float invisibleTime, int layer = 0, D3DXVECTOR2 scale = { 1, 1 });
	Font(std::wstring fontName, D3DXVECTOR2 pos, float* data, float tracking, bool leftAlign = false, int layer = 0, D3DXVECTOR2 scale = { 1, 1 });

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

