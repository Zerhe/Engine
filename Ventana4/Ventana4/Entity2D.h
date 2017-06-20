#ifndef ENTITY2D_H
#define ENTITY2D_H
#include "Api.h"
#include <windows.h>
#include <string>
#include "Entity.h"
#include "Entity2D.h"
#include "Graphics.h"
using namespace std;

class VENTANA4_API Entity2D : public Entity {
public:
	float _x = 0;
	float _y = 0;
	float _z = 0;;
	float _angle = 0;
	float _sX = 1;
	float _sY = 1;
	float _sZ = 1;
	float _r = 0;
	int _collType;
	void Transform(Graphics *graficos);
	virtual void OnCollision(Entity2D *entidad);
};

#endif
