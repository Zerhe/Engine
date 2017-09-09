#ifndef ENTITY3D_H
#define ENTITY3D_H
#include "Api.h"
#include "Entity.h"
#include "Graphics.h"

using namespace std;

class Entity3D : public Entity
{
public:
	float _depth = 0;
	float _angleX = 0;
	float _angleY = 0;
	float _angleZ = 0;
	void Transform(Graphics *graficos);
};
#endif // !ENTITY3D_H

