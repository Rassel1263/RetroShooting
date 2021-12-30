#include "DXUT.h"
#include "ResultScene.h"

void ResultScene::Init()
{
	nextScene = new MainScene();

	obm.AddObject(new ResultPage());
}

void ResultScene::Update(float deltaTime)
{
	obm.Update(deltaTime);
}

void ResultScene::Render()
{
	obm.Render();
}
