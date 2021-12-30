#include "DXUT.h"

Font::Font(std::wstring fontName, D3DXVECTOR2 pos, float data, float tracking, float invisibleTime, int layer, D3DXVECTOR2 scale)
{
	fontNum = 0;

	this->fontName = fontName;
	this->pos = pos;
	this->notChangeData = data;
	this->tracking = tracking;
	this->invisibleTime = invisibleTime;
	this->layer = layer;

	scaleNum = scale.x;
	ri.scale = scale;
}

Font::Font(std::wstring fontName, D3DXVECTOR2 pos, float* data, float tracking, bool leftAlign, int layer, D3DXVECTOR2 scale)
{
	fontNum = 1;

	this->fontName = fontName;
	this->pos = pos;
	this->data = data;
	this->tracking = tracking;
	this->leftAlign = leftAlign;
	this->layer = layer;

	this->invisibleTime = 999.0f;
	scaleNum = scale.x;
	ri.scale = scale;
}

void Font::Update(float deltaTime)
{
	wchar_t temp[10] = L"";
	if (fontNum == 0)
		swprintf_s(temp, L"%d", (int)notChangeData);
	if (fontNum == 1)
		swprintf_s(temp, L"%d", (int)*data);

	std::wstring ss(temp);
	sprites.resize(ss.size());

	for (int i = 0; ss[i] != '\0'; ++i)
		sprites[i].LoadAll(L"Assets/Sprites/UI/Font/" + fontName + ss.substr(i, 1) + L".png");

	invisibleTimer += deltaTime;

	if (invisibleTimer > invisibleTime)
		destroy = true;

}

void Font::Render()
{
	int count = 0;

	for (auto sprite = sprites.begin(); sprite != sprites.end(); ++sprite)
		(*sprite).isCamera = false;

	if (leftAlign)
	{
		for (auto sprite : sprites)
		{
			sprite.color.a = 1.0f - invisibleTimer / invisibleTime;
			ri.pos = pos + D3DXVECTOR2(count++ * tracking * scaleNum, 0);
			sprite.Render(ri);
		}
	}
	else
	{
		for (auto sprite = sprites.rbegin(); sprite != sprites.rend(); ++sprite)
		{
			(*sprite).color.a = 1.0f - invisibleTimer / invisibleTime;
			ri.pos = pos + D3DXVECTOR2(count-- * tracking * scaleNum, 0);
			(*sprite).Render(ri);
		}
	}
}
