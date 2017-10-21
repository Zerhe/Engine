#ifndef ENTITY2D_H
#define ENTITY2D_H
#include "Api.h"
#include <windows.h>
#include <string>
#include "Entity.h"
#include "Entity2D.h"
#include "Graphics.h"
using namespace std;

enum CollType
{
	Circle,
	Square
};

class VENTANA4_API Entity2D : public Entity 
{
public:
	//float _angle = 0;
	float _r = 0;
	CollType _collType = Circle;
	float _collWidth = 0;
	float _collHeight = 0;
	bool _inamovible = false;
	int _mass;
	//void Transform(Graphics *graficos);
	virtual void OnCollision(Entity2D *entidad) {};
};

#endif
