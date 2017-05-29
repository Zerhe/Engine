#ifndef ENTITY2D_H
#define ENTITY2D_H
#include "Api.h"
#include <windows.h>
#include <string>
#include "Entity.h"
#include "Graphics.h"
using namespace std;

class VENTANA4_API Entity2D : public Entity {
protected:
	float _x = 0;
	float _y = 0;
	float _z = 0;;
	float _angle = 0;
	float _sX = 1;
	float _sY = 1;
	float _sZ = 1;

public:
	void Draw(Graphics *graficos);
};

#endif
