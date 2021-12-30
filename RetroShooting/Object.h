#pragma once
class Object
{
public:
	// ¹°¸®
	bool bRigidbody = false;
	bool bPhysics = false;
	bool bGround = false;
	D3DXVECTOR2 rigidboydOffset;
	D3DXVECTOR2 rigidboydScale;
	float gravity = 0;
	float mass = 1;
	D3DXVECTOR2 force = { 0,0 };
	D3DXVECTOR2 velocity = { 0,0 };

	D3DXVECTOR2 fixedPos = { 0,0 };

	bool destroy = false;
	bool isCollision = true;
	D3DXVECTOR2 pos = { 0, 0 };
	int layer = 0;
	std::vector<Collider2D> bodies;
	std::wstring tag;

	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void OnCollision(const Collider2D& other);
};

class ObjectManager
{
private:
	std::vector<Object*> objects;
	std::vector<Object*> addObjects;

public:
	~ObjectManager();
	void AddObject(Object* object);
	virtual void Update(float deltaTime);
	virtual void Render();
};

