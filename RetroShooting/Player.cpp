#include "DXUT.h"
#include "Player.h"

PlayerIdle* PlayerIdle::instance = new PlayerIdle;
PlayerDown* PlayerDown::instance = new PlayerDown;
PlayerMove* PlayerMove::instance = new PlayerMove;
PlayerRun* PlayerRun::instance = new PlayerRun;
PlayerJump* PlayerJump::instance = new PlayerJump;
PlayerAttack* PlayerAttack::instance = new PlayerAttack;
PlayerRunAttack* PlayerRunAttack::instance = new PlayerRunAttack;

Player::Player()
{
	states[L"Idle"] = 0;
	states[L"Down"] = 1;
	states[L"Move"] = 2;
	states[L"Run"] = 3;
	states[L"Jump"] = 4;
	states[L"BackJump"] = 5;
	states[L"Attack"] = 6;
	states[L"JumpAttack"] = 7;
	states[L"RunAttack"] = 8;

	spr = new Sprite[states.size()];

	spr[states[L"Idle"]].LoadAll(L"Assets/Sprites/player/idle");
	spr[states[L"Idle"]].aniMaxTime = 0.2f;
	spr[states[L"Down"]].LoadAll(L"Assets/Sprites/player/crouch");
	spr[states[L"Move"]].LoadAll(L"Assets/Sprites/player/walk");
	spr[states[L"Run"]].LoadAll(L"Assets/Sprites/player/run");
	spr[states[L"Jump"]].LoadAll(L"Assets/Sprites/player/jump");
	spr[states[L"Attack"]].LoadAll(L"Assets/Sprites/player/shoot");
	spr[states[L"Attack"]].LoadAll(L"Assets/Sprites/player/shoot");
	spr[states[L"JumpAttack"]].LoadAll(L"Assets/Sprites/player/jump-shoot");
	spr[states[L"RunAttack"]].LoadAll(L"Assets/Sprites/player/run-shoot");

	PlayerIdle::instance->EnterState(this);
	bRigidbody = true;
	gravity = 1;

	tag = L"PLAYER";
	Collider2D::Square square;
	square.min = D3DXVECTOR2(-21, -46);
	square.max = D3DXVECTOR2(21, 46);
	bodies.push_back(Collider2D(this, tag, &square, 0));

	team = Team::ally;
	bulletAmount = 50;
	angleRange = 15;
	weaponIndex = 2;

	pos = { 0, 800 };
	ri.scale = { 2, 2 };

	Game::GetInstance().destCameraPos.x = pos.x;
}

void Player::Update(float deltaTime)
{
	//std::cout << Input::GetInstance().GetMousePos().x << "             " << Input::GetInstance().GetMousePos().y << std::endl;
	std::cout << Game::GetInstance().cameraPos.x << std::endl;

	if (hp <= 0)
	{
		if (!gameOver)
		{
			nowScene->obm.AddObject(new EPage());
			gameOver = true;
		}
		return;
	}

	if(pos.x >= 960 && pos.x <= nowScene->endWorldPos - 960) 
		Game::GetInstance().destCameraPos.x = pos.x - 960;

	inputTimer += deltaTime;
	for (int i = 0; i < 4; ++i)
	{
		if (Input::GetInstance().GetKeyState(VK_LEFT + i) == InputState::Down)
		{
			inputTimer = 0;
			prevInput = nowInput;
			nowInput = i;
		}
	}

	if (inputTimer > 0.2f)
	{
		prevInput = -1;
		nowInput = -1;
	}

	if (nowState)
		nowState->UpdateState(this, deltaTime);

	if (isHit)
	{
		tempColor.a += deltaTime;
		tempColor.b += deltaTime;

		if (tempColor.a >= 1.0f)
		{
			isHit = false;
		}
	}


	Unit::Update(deltaTime);
}

void Player::Render()
{
	spr[renderNum].color = tempColor;
	Unit::Render();
}

void Player::OnCollision(const Collider2D& other)
{
	if (other.tag == L"BULLET")
	{
		if (static_cast<IBullet*>(other.object)->team == (int)Team::Enemy)
		{
			if (!isHit)
			{
				hp--;
				isHit = true;
				tempColor.a = 0;
				tempColor.b = 0;
			}
		}
	}

	if (other.tag == L"ENEMY")
	{
		switch(static_cast<Enemy*>(other.object)->enemyNum)
		{
		case 1:
			speed = 150;
			break;
		case 2:
			isHit = true;
			break;
		case 4:
		case 5:
			isHit = true;
			break;
		}
	}

	if (other.tag == L"OBSTACLE")
	{
		pos.x -= 5; // ±Õ¬˙¿∏¥œ ¥Î√Ê ∏∏µÈ¿⁄
	}
}

bool Player::Move()
{
	D3DXVECTOR2 vMove = { 0.0f, 0.0f };

	if (Input::GetInstance().GetKeyState(VK_LEFT) == InputState::Press)
		vMove.x = -1;

	if (Input::GetInstance().GetKeyState(VK_RIGHT) == InputState::Press)
		vMove.x = 1;

	if (vMove.x != 0)
	{
		ri.scale.x = vMove.x * 2;
		velocity.x = vMove.x * speed;
		return true;
	}

	return false;
}

void Player::SetState(State<Player>* nowState)
{
	if (this->nowState)
	{
		spr[renderNum].scene = 0;
		this->nowState->ExitState(this);
	}

	this->nowState = nowState;
}

int Player::SetSpecialIndex()
{
	specialIndex = -1;
	switch (prevInput)
	{
	case LEFT:
	case RIGHT:
		if (nowInput == prevInput)
			specialIndex = 0;
		break;
	default:
		break;
	}

	return specialIndex;
}
