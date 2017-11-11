#include "Transform.h"

void Transform::LoadTransform(Graphics *graficos)
{
	graficos->Translate(position->x, position->y, position->z);
	graficos->RotationX(rotation->x);
	graficos->RotationY(rotation->y);
	graficos->RotationZ(rotation->z);
	graficos->Scaling(scale->x, scale->y, scale->z);
}
void Transform::SetPosition(float x, float y, float z) 
{
	position->x = x;
	position->y = y;
	position->z = z;
}
void Transform::SetRotation(float x, float y, float z) 
{
	rotation->x = x;
	rotation->y = y;
	rotation->z = z;
}
void Transform::SetScale(float x, float y, float z)
{
	scale->x = x;
	scale->y = y;
	scale->z = z;
}