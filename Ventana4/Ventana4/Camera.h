#ifndef CAMERA_H
#define CAMERA_H
#include "Api.h"
#include "Graphics.h"

class VENTANA4_API Camera{
	Graphics* _graficos;
	D3DXMATRIX _matProj;
	D3DXMATRIX _matView;
	float _heightViewport;
	float _widthViewport;
	float _aspectRatio;
public:
	float _x;
	float _y;
	float _z;
	Camera(Graphics* graficos, float widthViewport, float heightViewport);
	void SetCamera(char type, float fov, float nearClip, float farClip);
	void MovCamera();
	void Draw();
};
#endif

