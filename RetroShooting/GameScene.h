#pragma once
class GameScene : public Scene
{
public:
	bool gameClear = false;

	float timer = 2.0f;

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
};

