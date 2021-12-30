#pragma once

enum class Team
{
	None,
	ally,
	Enemy,
};

class Unit : public Object
{
public:
	std::map<std::wstring, int> states;
	Team team;

	float speed = 200.0f;
	float hp = 5;
	float maxHp = hp;

	int renderNum = 0;

	float angle = 0.0f;
	float angleRange = 0.0f;
	float bulletAmount = 50.0f;
	float maxBulletAmount = bulletAmount;
	int weaponIndex = 1;


public:
	Sprite* spr;
	SpriteRI ri;

	Unit();
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision(const Collider2D& other) override;
	virtual bool Move();

	void Shoot(std::wstring name, D3DXVECTOR2 pos, float bulletSpd);
	void SetAni(int index);
	void ResetAni();
	Sprite& GetData();
};

