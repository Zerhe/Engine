#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "Api.h"
#include <windows.h>
#include <string>
#include <list>
#include "GameObject.h"
#include "SpriteRenderer.h"
using namespace std;

//Cambiar Entity2D por GameObject

class VENTANA4_API CollisionManager{
	list <GameObject*> group01;
	list <GameObject*> group02;
	list<GameObject*>::iterator iterBeginGroup01 = group01.begin();
	list<GameObject*>::iterator iterBeginGroup02 = group02.begin();
	list<GameObject*>::iterator iterEndGroup01 = group01.end();
	list<GameObject*>::iterator iterEndGroup02 = group02.end();
	list<GameObject*>::iterator iter01;
	list<GameObject*>::iterator iter02;
	float x1 = 0;
	float x2 = 0;
	float y1 = 0;
	float y2 = 0;
	float r1 = 0;
	float r2 = 0;
	float width1 = 0;
	float width2 = 0;
	float height1 = 0;
	float height2 = 0;
	Sprite* sr01;
	Sprite* sr02;

public:
	bool Register(GameObject* entity, int group);
	bool UnRegister(GameObject* entity, int group);
	void Clear();
	void CheckCollision();
	void Penetration();
};

#endif