#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Api.h"
#include "Graphics.h"
#include "Component.h"

class VENTANA4_API Transform
{
public:
	D3DXVECTOR3* _position = new D3DXVECTOR3(0,0,0);
	D3DXVECTOR3* _rotation = new D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3* _scale = new D3DXVECTOR3(100, 100, 100);
	void LoadTransform(Graphics *graficos);
};
#endif
