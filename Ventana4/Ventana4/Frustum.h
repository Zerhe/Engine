#ifndef FRUSTUM_H
#define FRUSTUM_H
#include "Graphics.h"

class VENTANA4_API Frustum
{
	D3DXPLANE _planes[6];

public:
	void ConstructFrustum(float, D3DXMATRIX, D3DXMATRIX);

	bool CheckPoint(float, float, float);
	bool CheckCube(float, float, float, float);
	bool CheckSphere(float, float, float, float);
	bool CheckRectangle(float, float, float, float, float, float);
	void Lalala();
};
#endif
