#include "DXUT.h"
#include "Object.h"

void Object::Update(float deltaTime)
{
	if (bRigidbody)
	{
		// 현재 힘에 따른 물리적 위치 이동
		if (!bGround)
			force.y -= gravity * 100 * mass * deltaTime;
		velocity += force * (1 / mass) * 10;
		force = { 0,0 };
		fixedPos = pos;
		pos.x += velocity.x * deltaTime;
		pos.y -= velocity.y * deltaTime;

		// 플랫폼과 충돌했는지 검사
		if (pos.y >= 800)
		{
			pos.y = 800;
			bGround = true;
		}
		else
			bGround = false;

		if (bGround)
			velocity.y = 0.0f;

		//★★★08_21
		if (abs(velocity.x) >= 100)
			velocity.x -= (bGround ? 100 : 10) * velocity.x / abs(velocity.x) * min(abs(velocity.x), 100) * deltaTime;
		else
			velocity.x = 0;
	}
}

void Object::Render()
{
	for (auto& body : bodies)
	{
		D3DXMATRIX matrix;
		D3DXMatrixTranslation(&matrix, pos.x, pos.y, 0.0f);
		if (body.type == Collider2D::Type::TSquare)
		{
			Game::GetInstance().DrawLine(body.square.min, D3DXVECTOR2(body.square.max.x, body.square.min.y), matrix);
			Game::GetInstance().DrawLine(D3DXVECTOR2(body.square.max.x, body.square.min.y), body.square.max, matrix);
			Game::GetInstance().DrawLine(body.square.max, D3DXVECTOR2(body.square.min.x, body.square.max.y), matrix);
			Game::GetInstance().DrawLine(D3DXVECTOR2(body.square.min.x, body.square.max.y), body.square.min, matrix);
		}
	}
}

void Object::OnCollision(const Collider2D& other)
{
}

ObjectManager::~ObjectManager()
{
	for (auto object : objects)
		delete object;

	for (auto addObject : addObjects)
		delete addObject;
}

void ObjectManager::AddObject(Object* object)
{
	addObjects.push_back(object);
}

void ObjectManager::Update(float deltaTime)
{
	objects.insert(objects.end(), addObjects.begin(), addObjects.end());
	addObjects.clear();

	std::sort(objects.begin(), objects.end(), [](const Object* lhs, const Object* rhs) { return lhs->layer < rhs->layer; });

	for (auto it = objects.begin(); it != objects.end();)
	{
		(*it)->Update(deltaTime);

		if ((*it)->destroy)
		{
			SAFE_DELETE(*it);
			it = objects.erase(it);
		}
		else
			++it;
	}

	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		for (auto it2 = it + 1; it2 != objects.end(); ++it2)
		{
			for (auto& itbody : (*it)->bodies)
			{
				for (auto& it2body : (*it2)->bodies)
				{
					if (!(*it)->isCollision || !(*it2)->isCollision) continue;

					if (IntersectCollider2D(itbody, it2body))
					{
						(*it)->OnCollision(it2body);
						(*it2)->OnCollision(itbody);
					}
				}
			}
		}
	}
}

void ObjectManager::Render()
{
	for (auto object : objects)
		object->Render();
}
