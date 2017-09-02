#include "Entity3D.h"

void Entity3D::Transform(Graphics *graficos)
{
	graficos->LoadIdentity();
	graficos->Translate(_x, _y, _z);
	graficos->RotationZ(_angle);
	graficos->Scaling(_sX, _sY, _sZ);
}