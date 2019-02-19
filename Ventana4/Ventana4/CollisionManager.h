#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "Api.h"
#include <windows.h>
#include <string>
#include <list>
#include "Entity2D.h"
using namespace std;

//Cambiar Entity2D por GameObject

class VENTANA4_API CollisionManager{
	list <Entity2D*> group01;
	list <Entity2D*> group02;
	list<Entity2D*>::iterator iterBeginGroup01 = group01.begin();
	list<Entity2D*>::iterator iterBeginGroup02 = group02.begin();
	list<Entity2D*>::iterator iterEndGroup01 = group01.end();
	list<Entity2D*>::iterator iterEndGroup02 = group02.end();
	list<Entity2D*>::iterator iter01;
	list<Entity2D*>::iterator iter02;
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

public:
	bool Register(Entity2D* entity, int group);
	bool UnRegister(Entity2D* entity, int group);
	void Clear();
	void CheckCollision();
};

#endif