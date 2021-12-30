#include "DXUT.h"
#include "Collider2D.h"

Collider2D::Collider2D(Object* object, const std::wstring& tag, const Square* square, const Circle* circle)
{
	if (square)
	{
		type = Type::TSquare;
		this->square = *square;
	}
	else if (circle)
	{
		type = Type::TCircle;
		this->circle = *circle;
	}
	this->tag = tag;
	this->object = object;
}

bool IntersectCollider2D(const Collider2D& coli1, const Collider2D& coli2)
{
	if (coli1.type == Collider2D::Type::TSquare && coli2.type == Collider2D::Type::TSquare)
	{
		return IntersectSquare(coli1.object->pos + coli1.square.min, coli1.object->pos + coli1.square.max,
			coli2.object->pos + coli2.square.min, coli2.object->pos + coli2.square.max);
	}
	else if (coli1.type == Collider2D::Type::TCircle && coli2.type == Collider2D::Type::TCircle)
	{
		return IntersectCircle(coli1.object->pos, coli1.circle.radius, coli2.object->pos, coli2.circle.radius);
	}

	return false;
}

bool IntersectSquare(const D3DXVECTOR2& min1, const D3DXVECTOR2& max1, const D3DXVECTOR2& min2, const D3DXVECTOR2& max2)
{
	return (min1.x < max2.x) && (min2.x < max1.x) && (min1.y < max2.y) && (min2.y < max1.y);
}

bool IntersectCircle(const D3DXVECTOR2& p1, const float& r1, const D3DXVECTOR2& p2, const float& r2)
{
	auto p = p2 - p1;
	return p.x * p.x + p.y * p.y < (r1 + r2)* (r1 + r2);
}
