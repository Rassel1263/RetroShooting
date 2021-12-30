#pragma once
class EnemyUI : public Object
{
public:
	Sprite spr;
	SpriteRI ri;

	Enemy* target =NULL;

	EnemyUI(Enemy* target);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

