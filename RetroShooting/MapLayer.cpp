#include "DXUT.h"
#include "MapLayer.h"

MapLayer::MapLayer(std::wstring name, int layer, float layerSpeed, float yPos)
{
	spr.LoadAll(L"Assets/Sprites/Background/" + name + L".png");
	this->layer = layer;
	this->layerSpeed = layerSpeed;

	for (int i = 0; i < 2; ++i)
		layerPos[i] = D3DXVECTOR2(Game::GetInstance().screenWidth * i, yPos);
}

void MapLayer::Update(float deltaTime)
{
	for (int i = 0; i < 2; ++i)
	{
		if (layerPos[i].x + Game::GetInstance().screenWidth < Game::GetInstance().cameraPos.x + 960 + Game::GetInstance().cameraPos.x * layerSpeed)
			layerPos[i].x += Game::GetInstance().screenWidth * 2.0f;

		if (layerPos[i].x - Game::GetInstance().screenWidth > Game::GetInstance().cameraPos.x + 960 + Game::GetInstance().cameraPos.x * layerSpeed)
			layerPos[i].x -= Game::GetInstance().screenWidth * 2.0f;
	}

	pos = -Game::GetInstance().cameraPos * layerSpeed;
}

void MapLayer::Render()
{
	for (int i = 0; i < 2; ++i)
	{
		ri.pos = layerPos[i] + pos;
		spr.Render(ri);
	}
}
