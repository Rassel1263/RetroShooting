#pragma once
class SpriteRI
{
public:
	D3DXVECTOR2 pos = { 0, 0 };
	D3DXVECTOR2 scale = { 1, 1 };
	D3DXVECTOR2 center = { 0.5f, 0.5f };
	float rotate = 0.0f;
};

class Sprite
{
private:
	D3DXMATRIX matrix;

public:
	bool aniLoop = true;
	bool bAnimation = true;
	bool isCamera = true;

	float aniMaxTime = 0.08f;
	float aniTime = 0.0f;

	int scene = 0;
	int szScene = 0;

	RECT* drawRect = NULL;

	std::vector<const Texture*> textures;
	D3DXCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255);

	~Sprite();

	void LoadAll(std::wstring filePath);
	void Update(float deltaTime);
	void Render(const SpriteRI& ri);
	void Reset();
	const Texture* GetNowScene();
};

