#include "Camera.h"

Camera::Camera(Graphics* graficos, float widthViewport, float heightViewport) 
{
	_graficos = graficos;
	_widthViewport = widthViewport;
	_heightViewport = heightViewport;
	_aspectRatio = _widthViewport / _heightViewport;
	_x = _widthViewport / 2;
	_y = _heightViewport / 2;
	_z = 0;
}
void Camera::SetCamera(char type, float fov, float nearClip, float farClip) 
{
	if (type = 'O')
	{
		D3DXMatrixOrthoLH(&_matProj, _widthViewport, _heightViewport, nearClip, farClip);
	}
	else if (type = 'P')
	{
		D3DXMatrixPerspectiveFovLH(&_matProj, D3DX_PI / fov, _aspectRatio, nearClip, farClip);
	}
	
	_graficos->SetTransformCamera(D3DTS_PROJECTION, &_matProj);
}
void Camera::MovCamera() 
{
	D3DXVECTOR3 eyePos(_x, _y, _z - 5.0f);
	D3DXVECTOR3 lookPos(_x, _y, _z);
	D3DXVECTOR3 upVec(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&_matView, &eyePos, &lookPos, &upVec);
	_graficos->SetTransformCamera(D3DTS_VIEW, &_matView);
}
void Camera::Draw() 
{
	MovCamera();
}