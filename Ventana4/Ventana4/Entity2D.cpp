#include "Entity2D.h"

void Entity2D::Draw(Graphics *graficos) 
{
	graficos->LoadIdentity();
	graficos->Translate(_x, _y, _z);
	graficos->RotationZ(_angle);
	graficos->Scaling(_sX, _sY, _sZ);
}