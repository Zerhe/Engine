#ifndef CAMERA_H
#define CAMERA_H
#include "Api.h"
#include "Component.h"
#include "Graphics.h"
#include "Frustum.h"

class VENTANA4_API Camera : public Component {
	Graphics* _graficos;
	Frustum* _frustum;
	D3DXMATRIX _matProj;
	D3DXMATRIX _matView;
	D3DXVECTOR3 _forward;
	D3DXVECTOR3 _right;
	D3DXVECTOR3 _up;
	float _heightViewport;
	float _widthViewport;
	float _aspectRatio;
public:
	D3DXVECTOR3 _pos;
	Camera(Graphics* graficos, float widthViewport, float heightViewport);
	void SetCamera(char type, float fov, float nearClip, float farClip);
	void PosUpdate();
	void Yaw(float angle);
	void Pitch(float angle);
	void Roll(float angle);
	void Draw();
	D3DXMATRIX GetMatrixView();
	D3DXMATRIX GetMatrixProj();

};
#endif

