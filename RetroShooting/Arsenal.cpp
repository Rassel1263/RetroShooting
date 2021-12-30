#include "DXUT.h"
#include "Arsenal.h"

Arsenal::Arsenal(D3DXVECTOR2 pos)
{
	this->pos = pos;
	spr.LoadAll(L"Assets/Sprites/Room/Arsenal.png");

	Collider2D::Square square;
	square.min = D3DXVECTOR2(-100, -100);
	square.max = D3DXVECTOR2(100, 100);
	bodies.push_back(Collider2D(this, tag, &square, 0));
}

void Arsenal::Update(float deltaTime)
{

}

void Arsenal::Render()
{
	ri.pos = pos;
	spr.Render(ri);
	Object::Render();
}

void Arsenal::OnCollision(const Collider2D& other)
{
	if (other.tag == L"PLAYER")
	{
		if (Input::GetInstance().GetKeyState(VK_UP) == InputState::Down)
		{
			if (!openPanel)
			{
				openPanel = true;
				nowScene->obm.AddObject(new ShopPanel(openPanel));
			}
		}
	}
}
