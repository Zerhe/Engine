#include "Entity3D.h"

void Entity3D::Transform(Graphics *graficos)
{
	graficos->LoadIdentity();
	graficos->Translate(_x, _y, _z);
	graficos->RotationX(_angleX);
	graficos->RotationY(_angleY);
	graficos->RotationZ(_angleZ);
	graficos->Scaling(_sX, _sY, _sZ);
}