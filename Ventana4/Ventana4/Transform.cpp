#include "Transform.h"

void Transform::LoadTransform(Graphics *graficos)
{
	graficos->LoadIdentity();
	graficos->Translate(_position->x, _position->y, _position->z);
	graficos->RotationX(_rotation->x);
	graficos->RotationY(_rotation->y);
	graficos->RotationZ(_rotation->z);
	graficos->Scaling(_scale->x, _scale->y, _scale->z);
}