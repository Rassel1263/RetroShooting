#pragma once
class PlayerIdle : public State<Player>
{
public:
	static PlayerIdle* instance;

	virtual void EnterState(Player* obj);
	virtual void UpdateState(Player* obj, float deltaTime);
	virtual void ExitState(Player* obj);
};

class PlayerDown : public State<Player>
{
public:
	static PlayerDown* instance;

	virtual void EnterState(Player* obj);
	virtual void UpdateState(Player* obj, float deltaTime);
	virtual void ExitState(Player* obj);
};

class PlayerMove : public State<Player>
{
public:
	static PlayerMove* instance;

	virtual void EnterState(Player* obj);
	virtual void UpdateState(Player* obj, float deltaTime);
	virtual void ExitState(Player* obj);
};

class PlayerRun : public State<Player>
{
public:
	static PlayerRun* instance;

	virtual void EnterState(Player* obj);
	virtual void UpdateState(Player* obj, float deltaTime);
	virtual void ExitState(Player* obj);
};

class PlayerJump : public State<Player>
{
public:
	float timer = 0.1f;
	static PlayerJump* instance;

	virtual void EnterState(Player* obj);
	virtual void UpdateState(Player* obj, float deltaTime);
	virtual void ExitState(Player* obj);
};

class PlayerAttack : public State<Player>
{
public:
	float timer = 0.1f;
	static PlayerAttack* instance;

	virtual void EnterState(Player* obj);
	virtual void UpdateState(Player* obj, float deltaTime);
	virtual void ExitState(Player* obj);
};

class PlayerRunAttack : public State<Player>
{
public:
	float timer = 1.0f;
	static PlayerRunAttack* instance;

	virtual void EnterState(Player* obj);
	virtual void UpdateState(Player* obj, float deltaTime);
	virtual void ExitState(Player* obj);
};

