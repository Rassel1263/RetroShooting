#include "DXUT.h"
#include "Game.h"
Scene* nowScene = NULL;

Game::~Game()
{
	SAFE_RELEASE(pSprite);
	SAFE_RELEASE(pLine);
}

void Game::Init()
{
	ChangeScene(new GameScene2());
	D3DXVECTOR3 vEyePt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vLookAtPt(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookAtPt, &vUpVec);
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &matView);


	D3DXMatrixOrthoLH(&matProj, screenWidth, screenHeight, 0.01f, 100.0f);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &matProj);

	D3DXCreateLine(DXUTGetD3D9Device(), &pLine);
	D3DXCreateSprite(DXUTGetD3D9Device(), &pSprite);
}

void Game::Update(float deltaTime)
{
	if (nextScene)
	{
		if (nowScene)
			delete nowScene;

		nowScene = nextScene;
		nowScene->Init();
		nextScene = NULL;
	}

	cameraPos += (destCameraPos - cameraPos) * 0.07f;
	cameraScale += (destCameraScale - cameraScale) * 0.07f;
	cameraQuaken += (destCameraQuaken - cameraQuaken) * 0.05f;

	D3DXMATRIX matCamScale;
	D3DXMatrixScaling(&matCamScale, cameraScale.x, cameraScale.y, 1.0f);
	D3DXMATRIX matCamPos;
	D3DXMatrixTranslation(&matCamPos, (rand() % 2 ? 1 : -1) * cameraQuaken.x - cameraPos.x, (rand() % 2 ? 1 : -1) * cameraQuaken.y - cameraPos.y, 0.0f);
	matWorld = matCamPos * matCamScale;
	DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &matWorld);

	unScaleTime = deltaTime;

	if (nowScene)
		nowScene->Update(deltaTime * timeScale);
}

void Game::Render()
{
	pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	if (nowScene)
		nowScene->Render();

	pSprite->End();
}

void Game::DrawLine(const D3DXVECTOR2 p1, const D3DXVECTOR2 p2, D3DXMATRIX mat)
{
	pLine->SetWidth(2.0f);
	pLine->Begin();
	D3DXVECTOR3 v[] = { D3DXVECTOR3(p1.x, p1.y, 0.0f), D3DXVECTOR3(p2.x, p2.y, 0.0f) };
	D3DXMATRIX retMat = mat * matView * matProj;
	pLine->DrawTransform(v, 2, &retMat, D3DCOLOR_XRGB(255, 255, 0));
	pLine->End();
}

void Game::ChangeScene(Scene* scene)
{
	nextScene = scene;
}


