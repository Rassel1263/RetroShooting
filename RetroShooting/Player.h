#pragma once

class Player : public Unit
{
public:
	enum InputDir
	{
		LEFT,
		UP,
		RIGHT,
		DOWN,
	};

	State<Player>* nowState = NULL;
	D3DXCOLOR tempColor = D3DCOLOR_ARGB(255, 255, 255, 255);

	bool isHit = false;
	bool gameOver = false;

	float inputTimer = 0.0f;
	float sp = 100;
	float maxSp = sp;

	int specialIndex = -1;
	int prevInput = -1;
	int nowInput = 1;

	Player();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
	virtual bool Move();

	void SetState(State<Player>* nowState);
	int SetSpecialIndex();
};

