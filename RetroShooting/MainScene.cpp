#include "DXUT.h"
#include "MainScene.h"

void MainScene::Init()
{
	nextScene = new GameScene();

	obm.AddObject(new MainMenu());
}

void MainScene::Update(float deltaTime)
{


	obm.Update(deltaTime);
}

void MainScene::Render()
{
	obm.Render();
}
