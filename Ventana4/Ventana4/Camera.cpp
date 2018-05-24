#include "Camera.h"

Camera::Camera(Graphics* graficos, float widthViewport, float heightViewport) 
{
	_graficos = graficos;
	_widthViewport = widthViewport;
	_heightViewport = heightViewport;
	_aspectRatio = _widthViewport / _heightViewport;
	_pos.x = _widthViewport / 2;
	_pos.y = _heightViewport / 2;
	_pos.z = -500.0f;
	_forward.x = 0.0f; _forward.y = 0.0f; _forward.z = 1.0f;
	_up.x = 0.0f; _up.y = 1.0f; _up.z = 0.0f;
	_right.x = 1.0f; _right.y = 0.0f; _right.z = 0.0f;
}
void Camera::SetCamera(char type, float fov, float nearClip, float farClip) 
{
	if (type == 'O')
	{
		D3DXMatrixOrthoLH(&_matProj, _widthViewport, _heightViewport, nearClip, farClip);
	}
	else if (type == 'P')
	{
		D3DXMatrixPerspectiveFovLH(&_matProj, D3DX_PI * fov / 180.0f, _aspectRatio, nearClip, farClip);
	}
	
	_graficos->SetTransformCamera(D3DTS_PROJECTION, &_matProj);
}
void Camera::SumX(float num)
{
	_pos.x += num;
	PosUpdate();
}
void Camera::SumY(float num)
{
	_pos.y += num;
	PosUpdate();
}
void Camera::SumZ(float num)
{
	_pos.z += num;
	PosUpdate();
}
void Camera::PosUpdate()
{
	D3DXVECTOR3 _lookPos(_pos.x, _pos.y, _pos.z);
	_lookPos += _forward;
	D3DXMatrixLookAtLH(&_matView, &_pos, &_lookPos, &_up);
	_graficos->SetTransformCamera(D3DTS_VIEW, &_matView);
}
void Camera::Yaw(float angle)
{
	D3DXMATRIX _matUp;
	D3DXMatrixRotationAxis(&_matUp, &_up, angle);
	D3DXVec3TransformCoord(&_forward, &_forward, &_matUp);
	D3DXVec3TransformCoord(&_right, &_right, &_matUp);

	D3DXMatrixLookAtLH(&_matView, &_pos, &(_pos + _forward), &_up);
	_graficos->SetTransformCamera(D3DTS_VIEW, &_matView);
}
void Camera::Pitch(float angle)
{
	D3DXMATRIX _matUp;
	D3DXMatrixRotationAxis(&_matUp, &_right, angle);
	D3DXVec3TransformCoord(&_forward, &_forward, &_matUp);
	D3DXVec3TransformCoord(&_up, &_up, &_matUp);

	D3DXMatrixLookAtLH(&_matView, &_pos, &(_pos + _forward), &_up);
	_graficos->SetTransformCamera(D3DTS_VIEW, &_matView);
}
void Camera::Roll(float angle)
{
	D3DXMATRIX _matUp;
	D3DXMatrixRotationAxis(&_matUp, &_forward, angle);
	D3DXVec3TransformCoord(&_right, &_right, &_matUp);
	D3DXVec3TransformCoord(&_up, &_up, &_matUp);

	D3DXMatrixLookAtLH(&_matView, &_pos, &(_pos + _forward), &_up);
	_graficos->SetTransformCamera(D3DTS_VIEW, &_matView);
}
void Camera::Draw() 
{
	//PosUpdate();
}
D3DXMATRIX Camera::GetMatrixView()
{
	return _matView;
}
D3DXMATRIX Camera::GetMatrixProj()
{
	return _matProj;
}