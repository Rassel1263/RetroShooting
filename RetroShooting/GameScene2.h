#pragma once
class GameScene2 : public Scene
{
public:
	bool gameClear = false;

	float timer = 2.0f;

	virtual void Init();
	virtual void Update(float deltaTime) override;
	virtual void Render();
};

