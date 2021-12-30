#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	srand(time(NULL));
	nextScene = new GameScene2();

	obm.AddObject(new MapLayer(L"bg", 0, -0.5f, 540.0f));
	obm.AddObject(new MapLayer(L"Platform2", 0, 0.0f, 950.0f));

	obm.AddObject(player = new Player());


	obm.AddObject(new Infirmary({ 1800, 780 }));
	obm.AddObject(new Arsenal({ 1000, 668 }));
	//obm.AddObject(new Obstacle({500, 760}));

	Enemy* enemy;

	for (int i = 1; i <= 5; ++i)
	{
		obm.AddObject(enemy = new RushEnemy({ float(700 * i), 800 }));
		enemyList.push_back(enemy);
		obm.AddObject(enemy = new Turret({ float(960 * i), 800 }));
		enemyList.push_back(enemy);
		obm.AddObject(enemy = new DestructEnemy({ float(rand() % 300 + 400) * i, 800 }));
		enemyList.push_back(enemy);
	}


	for (auto enemy : enemyList)
		obm.AddObject(new EnemyUI(enemy));


	obm.AddObject(new PlayerUI());
	obm.AddObject(new ProgressUI());
	obm.AddObject(new Font(L"Time/", D3DXVECTOR2(960, 80), &gameTimer, 70, false, 0, D3DXVECTOR2(0.7f, 0.7f)));
	obm.AddObject(new Font(L"Score/", D3DXVECTOR2(1800, 80), &score, 90, false, 0, D3DXVECTOR2(0.4f, 0.4f)));
	obm.AddObject(new Font(L"Coin/", D3DXVECTOR2(490, 202), &coin, 30, true, 0, D3DXVECTOR2(1.0f, 1.0f)));
	obm.AddObject(new Font(L"Bullet/", D3DXVECTOR2(290, 190), &player->bulletAmount, 30, true, 0, D3DXVECTOR2(0.7f, 0.7f)));
	obm.AddObject(new Fade(1));
}

void GameScene::Update(float deltaTime)
{

	for (auto it = enemyList.begin(); it != enemyList.end();)
	{
		if ((*it)->destroy)
		{
			it = enemyList.erase(it);
		}
		else
			++it;
	}

	if (enemyList.size() <= 0)
	{
		if (!gameClear)
		{
			gameClear = true;
			obm.AddObject(new Fade(2));
		}
	}

	

	Scene::Update(deltaTime);
}

void GameScene::Render()
{
	Scene::Render();
}
