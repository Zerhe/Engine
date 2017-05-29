#ifndef SHAPE_H
#define SHAPE_H
#include "Api.h"
#include <Windows.h>
#include <string>
#include "Entity2D.h"
#include "Graphics.h"
using namespace std;

class VENTANA4_API Shape : public Entity2D {
	Graphics* _graficos;
	CUSTOMVERTEX* _vertices;
public:
	Shape(Graphics *graficos,float x, float y, float z, float angle, float sx, float sy, float sz);
	void Draw();
};
#endif
