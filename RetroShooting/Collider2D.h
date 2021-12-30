#pragma once

class Object;
class Collider2D
{
public:
	enum Type
	{
		TSquare,
		TCircle,
	} type;

	struct Square
	{
		D3DXVECTOR2 min = D3DXVECTOR2(0.0f, 0.0f), max = D3DXVECTOR2(0.0f, 0.0f);
	} square;
	struct Circle
	{
		float radius = 0.0f;
	} circle;

	Collider2D(Object* object, const std::wstring& tag, const Square* square, const Circle* circle);
	Object* object;
	std::wstring tag;
};

bool IntersectCollider2D(const Collider2D& coli1, const Collider2D& coli2);
bool IntersectSquare(const D3DXVECTOR2& min1, const D3DXVECTOR2& max1, const D3DXVECTOR2& min2, const D3DXVECTOR2& max2);
bool IntersectCircle(const D3DXVECTOR2& p1, const float& r1, const D3DXVECTOR2& p2, const float& r2);

