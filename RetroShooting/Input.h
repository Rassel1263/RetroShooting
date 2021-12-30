#pragma once

enum InputState
{
	None = 0,
	Down = 1,
	Press = 2,
	Up = 3
};

class Input : public Singleton<Input>
{
public:
	int keyState[255] = {};
	D3DXVECTOR2 mousePos = { 0, 0 };

public:

	int GetKeyState(int key);
	D3DXVECTOR2 GetMousePos();
	D3DXVECTOR2 GetWorldMousePos();
	void Update();

};