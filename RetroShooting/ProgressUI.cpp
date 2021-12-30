#include "DXUT.h"
#include "ProgressUI.h"

ProgressUI::ProgressUI()
{
	smallP.isCamera = false;
	smallP.LoadAll(L"Assets/Sprites/UI/smallP.png");
	bPro.isCamera = false;
	bPro.LoadAll(L"Assets/Sprites/UI/bPro.png");

	progress.isCamera = false;
	progress.LoadAll(L"Assets/Sprites/UI/fPro.png");
	progress.drawRect = new RECT{ 0, 0, (long)progress.textures[0]->info.Width, (long)progress.textures[0]->info.Height };

	pos.y = 950;
}

void ProgressUI::Update(float deltaTime)
{
	if (nowScene->player->pos.x >= 0 && nowScene->player->pos.x < nowScene->endWorldPos)
	{
		progress.drawRect->right = nowScene->player->pos.x / nowScene->endWorldPos * progress.textures[0]->info.Width;
		pos.x = 60 + nowScene->player->pos.x / nowScene->endWorldPos * 1800;
	}
}

void ProgressUI::Render()
{
	bPro.Render(SpriteRI{ D3DXVECTOR2(960, 980) });
	progress.Render(SpriteRI{D3DXVECTOR2(960, 980)});
	smallP.Render(SpriteRI{ pos });

}
