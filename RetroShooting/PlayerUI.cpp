#include "DXUT.h"
#include "PlayerUI.h"

PlayerUI::PlayerUI()
{
	ui.isCamera = false;
	ui.LoadAll(L"Assets/Sprites/UI/playerUI.png");

	for (int i = 0; i < 3; ++i)
	{
		gunUi[i].isCamera = false;
		gunUi[i].LoadAll(L"Assets/Sprites/UI/Gun/" + std::to_wstring(i + 1));
	}


	hpBar.isCamera = false;
	hpBar.LoadAll(L"Assets/Sprites/UI/hpBar.png");
	hpBar.drawRect = new RECT{ 0, 0, (long)hpBar.textures[0]->info.Width, (long)hpBar.textures[0]->info.Height };
	hpRi.pos = { 417, 103 };

	spBar.isCamera = false;
	spBar.LoadAll(L"Assets/Sprites/UI/energybar.png");
	spBar.drawRect = new RECT{ 0, 0, (long)spBar.textures[0]->info.Width, (long)spBar.textures[0]->info.Height };
	spRi.pos = { 417, 137 };

	coin.isCamera = false;
	coin.LoadAll(L"Assets/Sprites/UI/coin.png");

}

void PlayerUI::Update(float deltaTime)
{
	hpBar.drawRect->right = hpBar.textures[0]->info.Width * nowScene->player->hp / nowScene->player->maxHp;
	spBar.drawRect->right = spBar.textures[0]->info.Width * nowScene->player->sp / nowScene->player->maxSp;
}

void PlayerUI::Render()
{
	ui.Render(SpriteRI{D3DXVECTOR2(320, 120)});
	gunUi[nowScene->player->weaponIndex - 1].Render(SpriteRI{ D3DXVECTOR2(240, 190) });
	hpBar.Render(hpRi);
	spBar.Render(spRi);
	coin.Render(SpriteRI{ D3DXVECTOR2(430, 195) });
}
