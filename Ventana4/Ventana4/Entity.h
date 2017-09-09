#ifndef ENTITY_H
#define ENTITY_H
#include "Api.h"
#include <windows.h>
#include <string>
using namespace std;

class VENTANA4_API Entity {
	char nombre[10];
public:
	float _x = 0;
	float _y = 0;
	float _z = 0;;
	float _width = 0;
	float _height = 0;
	float _sX = 1;
	float _sY = 1;
	float _sZ = 1;
protected:
	virtual void Draw() {};
};

#endif
