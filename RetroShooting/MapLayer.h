#pragma once
class MapLayer : public Object
{
public:
	Sprite spr;
	SpriteRI ri;

	D3DXVECTOR2 layerPos[2];
	float layerSpeed = 0.0f;
	
	MapLayer(std::wstring name, int layer, float layerSpeed, float yPos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

