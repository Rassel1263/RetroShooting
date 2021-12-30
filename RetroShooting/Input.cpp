#include "DXUT.h"

int Input::GetKeyState(int key)
{
	return keyState[key];
}

D3DXVECTOR2 Input::GetMousePos()
{
	return mousePos;
}

D3DXVECTOR2 Input::GetWorldMousePos()
{
	//D3DXVECTOR2 ratio = D3DXVECTOR2(mousePos.x / Game::GetInstance().screenWidth, -mousePos.y / Game::GetInstance().screenHeight);
	//D3DXVECTOR2 worldPosition = D3DXVECTOR2(-Game::GetInstance().screenWidth * 0.5f, Game::GetInstance().screenHeight * 0.5f);
	//worldPosition = worldPosition + D3DXVECTOR2(Game::GetInstance().screenWidth * ratio.x, Game::GetInstance().screenHeight * ratio.y);

	//D3DXVECTOR2 cameraScale = Game::GetInstance().cameraScale;
	//if (cameraScale.x == 0.0f || cameraScale.y == 0.0f)
	//	return D3DXVECTOR2(0.0f, 0.0f);

	return mousePos;
}

void Input::Update()
{
	// 키보드 업데이트
	for (int i = 0; i < 255; ++i)
	{
		if (GetAsyncKeyState(i))
		{
			if (keyState[i] == InputState::None)
				keyState[i] = InputState::Down;
			else if (keyState[i] == InputState::Down)
				keyState[i] = InputState::Press;
		}
		else
		{
			if (keyState[i] == InputState::Up)
				keyState[i] = InputState::None;
			else if (keyState[i] > 0)
				keyState[i] = InputState::Up;
		}
	}
}
