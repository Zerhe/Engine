#include "Sprite.h"

Sprite::Sprite(Graphics *graficos, float x, float y, float z, float angle, float sX, float sY, float sZ, LPCWSTR stringTexture)
{
	_graficos = graficos;
	_texture = _graficos->LoadTexture(stringTexture);
	_x = x;
	_y = y;
	_z = z;
	_angle = angle;
	_sX = sX;
	_sY = sY;
	_sZ = sZ;

	_vertices = new CUSTOMVERTEXTEXTURE[4];
	_vertices[0] = { 50.0f, 200.0f, 0.5f, 1.0f, 1.0f };
	_vertices[1] = { 650.0f, 200.0f, 0.5f, 0.0f, 1.0f } ;
	_vertices[2] = { 50.0f, 500.0f, 0.5f, 1.0f, 0.0f } ;
	_vertices[3] = { 650.0f, 500.0f, 0.5f, 0.0f, 0.0f };
}
void Sprite::Draw()
{
	Entity2D::Draw(_graficos);

	_graficos->BindTexture(_texture);

	_graficos->DrawSprite(_vertices, 4);

}