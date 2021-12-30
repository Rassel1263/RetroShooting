#pragma once
class Effect : public Object
{
public:
	Sprite eft;
	SpriteRI ri;

	Effect(std::wstring eftName, D3DXVECTOR2 pos, D3DXVECTOR2 scale);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

