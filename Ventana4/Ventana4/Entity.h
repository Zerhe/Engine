#ifndef ENTITY_H
#define ENTITY_H
#include "Api.h"
#include <windows.h>
#include <string>
using namespace std;

class VENTANA4_API Entity {
	char nombre[10];
protected:
	virtual void Draw() {};
};

#endif
