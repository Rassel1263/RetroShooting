#pragma once
class Scene 
{
public:
	Scene* nextScene = NULL;

	float endWorldPos = 5760.0f;
	float gameTimer = 120.0f;
	float pastScore = 0.0f;

	static float score;
	static float destScore;

	float coin = 0;

	ObjectManager obm;
	Player* player = NULL;
	std::vector<Enemy*> enemyList;

	virtual ~Scene();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	void PlusScore(float score);
	void PlusCoin(D3DXVECTOR2 pos, float amount);
};

