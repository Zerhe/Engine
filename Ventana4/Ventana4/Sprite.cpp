#include "Sprite.h"

Sprite::Sprite(Graphics* graficos, TextureManager* textureManager, float x, float y, float z, float angle, float sX, float sY, float sZ, float r, int collType, LPCWSTR stringTexture)
{
	_graficos = graficos;
	_textureManager = textureManager;
	_texture = _textureManager->CreateTexture(stringTexture, _graficos);
	_x = x;
	_y = y;
	_z = z;
	_angle = angle;
	_sX = sX;
	_sY = sY;
	_sZ = sZ;
	_collType = collType;
	_frame = 0;
	if(collType == 1)
		_r = r;

	_vertices = new CUSTOMVERTEXTEXTURE[4];
	_vertices[0] = { 50.0f, 200.0f, 0.5f, 0.0f, 1.0f };
	_vertices[1] = { 650.0f, 200.0f, 0.5f, 1.0f, 1.0f } ;
	_vertices[2] = { 50.0f, 500.0f, 0.5f, 0.0f, 0.0f } ;
	_vertices[3] = { 650.0f, 500.0f, 0.5f, 1.0f, 0.0f };
}
void Sprite::Draw()
{
	Transform(_graficos);

	_graficos->BindTexture(_texture->getTexture());

	_graficos->DrawSprite(_vertices, 4);

}
void Sprite::SetUv(float x, float y, float width, float height, int textureWidth, int textureHeight, int framesAncho)
{
	_vertices[0] = { x, y, 0.5f, width / textureWidth * (_frame % framesAncho ), 1.0f };
	_vertices[1] = { x + width, y, 0.5f, width/textureWidth * ((_frame + 1) % framesAncho), 1.0f };
	_vertices[2] = { x, y + height, 0.5f, width / textureWidth * (_frame % framesAncho), 0.0f };
	_vertices[3] = { x + width, y + height, 0.5f, width/textureWidth * ((_frame + 1) % framesAncho), 0.0f };
}
void Sprite::LaterFrame()
{
	_frame++;
}
