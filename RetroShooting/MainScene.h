#pragma once
class MainScene : public Scene
{
public:
	bool inputKey = true;

	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

