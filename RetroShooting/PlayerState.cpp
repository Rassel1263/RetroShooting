#include "DXUT.h"
#include "Header.h"

void PlayerIdle::EnterState(Player* obj)
{
	obj->SetState(this);
	obj->SetAni(obj->states[L"Idle"]);
	obj->ResetAni();
	obj->speed = 200;
}

void PlayerIdle::UpdateState(Player* obj, float deltaTime)
{
	if(obj->sp < obj->maxSp)
		obj->sp++;

	if (obj->Move())
	{
		PlayerMove::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState(VK_DOWN) == InputState::Press)
	{
		PlayerDown::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState(VK_SPACE) == InputState::Down)
	{
		PlayerJump::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState('A') == InputState::Down)
	{
		PlayerAttack::instance->EnterState(obj);
		return;
	}
}

void PlayerIdle::ExitState(Player* obj)
{
}

void PlayerDown::EnterState(Player* obj)
{
	obj->SetState(this);
	obj->SetAni(obj->states[L"Down"]);
	obj->ResetAni();
}

void PlayerDown::UpdateState(Player* obj, float deltaTime)
{
	if (Input::GetInstance().GetKeyState(VK_DOWN) == InputState::Up)
	{
		PlayerIdle::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState('A') == InputState::Down)
	{
		obj->Shoot(L"Assets/Sprites/player/bullet/" + std::to_wstring(obj->weaponIndex), D3DXVECTOR2(obj->pos.x + 10 * obj->ri.scale.x, obj->pos.y + 22),
			1400.0f);
	}

}

void PlayerDown::ExitState(Player* obj)
{
}

void PlayerMove::EnterState(Player* obj)
{
	obj->SetState(this);
	obj->SetAni(obj->states[L"Move"]);
	obj->ResetAni();
}

void PlayerMove::UpdateState(Player* obj, float deltaTime)
{
	if (!obj->Move())
	{
		PlayerIdle::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState(VK_SPACE) == InputState::Down)
	{
		PlayerJump::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState('A') == InputState::Down)
	{
		PlayerAttack::instance->EnterState(obj);
		return;
	}

	if (obj->SetSpecialIndex() == 0)
	{
		PlayerRun::instance->EnterState(obj);
		return;
	}

}

void PlayerMove::ExitState(Player* obj)
{
}

void PlayerRun::EnterState(Player* obj)
{
	obj->SetState(this);
	obj->SetAni(obj->states[L"Run"]);
	obj->ResetAni();
	obj->speed = 400;
}

void PlayerRun::UpdateState(Player* obj, float deltaTime)
{
	if(obj->sp > 0.0f)
		obj->sp--;


	if (!obj->Move())
	{
		PlayerIdle::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState(VK_SPACE) == InputState::Down)
	{
		PlayerJump::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState('A') == InputState::Down)
	{
		PlayerRunAttack::instance->EnterState(obj);
		return;
	}
}

void PlayerRun::ExitState(Player* obj)
{
}

void PlayerJump::EnterState(Player* obj)
{
	obj->SetState(this);
	obj->SetAni(obj->states[L"Jump"]);
	obj->ResetAni();
	obj->velocity.y = 500;
}

void PlayerJump::UpdateState(Player* obj, float deltaTime)
{
	obj->Move();

	timer -= deltaTime;

	if (Input::GetInstance().GetKeyState('A') == InputState::Down)
	{
		obj->SetAni(obj->states[L"JumpAttack"]);

		obj->Shoot(L"Assets/Sprites/player/bullet/" + std::to_wstring(obj->weaponIndex), D3DXVECTOR2(obj->pos.x + 10 * obj->ri.scale.x, obj->pos.y - 22),
			1400.0f);
	}



	if (obj->bGround && timer <= 0.0f)
	{
		PlayerIdle::instance->EnterState(obj);
		return;
	}

}

void PlayerJump::ExitState(Player* obj)
{
	timer = 0.1f;
}

void PlayerAttack::EnterState(Player* obj)
{
	obj->SetState(this);
	obj->SetAni(obj->states[L"Attack"]);
	obj->ResetAni();
	obj->Shoot(L"Assets/Sprites/player/bullet/" + std::to_wstring(obj->weaponIndex), D3DXVECTOR2(obj->pos.x + 10 * obj->ri.scale.x, obj->pos.y - 22),
		1400.0f);
}

void PlayerAttack::UpdateState(Player* obj, float deltaTime)
{
	if (timer <= 0.0f)
	{
		PlayerIdle::instance->EnterState(obj);
		return;
	}

	timer -= deltaTime;
}

void PlayerAttack::ExitState(Player* obj)
{
	timer = 0.1f;
}

void PlayerRunAttack::EnterState(Player* obj)
{
	obj->SetState(this);
	obj->SetAni(obj->states[L"RunAttack"]);
	obj->ResetAni();
	obj->Shoot(L"Assets/Sprites/player/bullet/" + std::to_wstring(obj->weaponIndex), D3DXVECTOR2(obj->pos.x + 10 * obj->ri.scale.x, obj->pos.y - 22),
		1400.0f);
}

void PlayerRunAttack::UpdateState(Player* obj, float deltaTime)
{

	if (timer <= 0.0f)
	{
		PlayerRun::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState(VK_SPACE) == InputState::Down)
	{
		PlayerJump::instance->EnterState(obj);
		return;
	}

	if (Input::GetInstance().GetKeyState('A') == InputState::Down)
	{
		obj->Shoot(L"Assets/Sprites/player/bullet/" + std::to_wstring(obj->weaponIndex), D3DXVECTOR2(obj->pos.x + 10 * obj->ri.scale.x, obj->pos.y - 22),
			1400.0f);
		timer = 1.0f;
	}

	if (!obj->Move())
	{
		PlayerIdle::instance->EnterState(obj);
		return;
	}

	timer -= deltaTime;
}

void PlayerRunAttack::ExitState(Player* obj)
{
	timer = 1.0f;
}
