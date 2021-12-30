#pragma once
class Game : public Singleton<Game>
{
public:
	Scene* nextScene;

	int screenWidth = 1920;
	int screenHeight = 1080;

	float timeScale = 1.0f;
	float unScaleTime = 0.0f;

	LPD3DXSPRITE pSprite;
	LPD3DXLINE pLine;

	D3DXMATRIX matView;
	D3DXMATRIX matProj;
	D3DXMATRIX matWorld;

	D3DXVECTOR2 cameraPos = { 0, 0 };
	D3DXVECTOR2 cameraScale = { 1, 1 };
	D3DXVECTOR2 cameraQuaken = { 0, 0 };
	D3DXVECTOR2 destCameraPos = cameraPos;
	D3DXVECTOR2 destCameraScale = cameraScale;
	D3DXVECTOR2 destCameraQuaken = cameraQuaken;

	~Game();

	void Init();
	void Update(float deltaTime);
	void Render();
	void DrawLine(const D3DXVECTOR2 p1, const D3DXVECTOR2 p2, D3DXMATRIX mat);
	void ChangeScene(Scene* scene);
};

