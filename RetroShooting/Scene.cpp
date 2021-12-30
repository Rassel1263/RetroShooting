#include "DXUT.h"
#include "Scene.h"

float Scene::score = 0.0f;
float Scene::destScore = 0.0f;

Scene::~Scene()
{
}

void Scene::Init()
{
}

void Scene::Update(float deltaTime)
{
	if (destScore - pastScore != 0)
		nowScene->obm.AddObject(new Font(L"Score/", D3DXVECTOR2(1800, 120), destScore - pastScore, 90, 0.3f, 0, D3DXVECTOR2(0.2, 0.2)));

	score += ceil((destScore - score) * 0.1f);
	pastScore = destScore;

	gameTimer -= deltaTime;

	if (Input::GetInstance().GetKeyState(VK_F4) == InputState::Down)
		obm.AddObject(new CalcPage());

	if (Input::GetInstance().GetKeyState(VK_F6) == InputState::Down)
		Game::GetInstance().ChangeScene(new GameScene2());

	if (Input::GetInstance().GetKeyState(VK_F7) == InputState::Down)
		player->hp--;

	if (Input::GetInstance().GetKeyState(VK_F7) == InputState::Down)
		Game::GetInstance().ChangeScene(new ResultScene());

	obm.Update(deltaTime);
}

void Scene::Render()
{
	obm.Render();
}

void Scene::PlusScore(float score)
{
	destScore += score;
}

void Scene::PlusCoin(D3DXVECTOR2 pos, float amount)
{
	for (int i = 0; i < amount; ++i)
	{
		obm.AddObject(new DestEffect(pos));
	}
}


