#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Api.h"
#include "Graphics.h"
#include "Component.h"

class VENTANA4_API Transform
{
public:
	D3DXVECTOR3* position = new D3DXVECTOR3(0,0,0);
	D3DXVECTOR3* rotation = new D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3* scale = new D3DXVECTOR3(1, 1, 1);
	void LoadTransform(Graphics *graficos);
	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);
};
#endif
