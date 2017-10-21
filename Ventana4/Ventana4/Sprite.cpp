#include "Sprite.h"

Sprite::Sprite(Graphics* graficos, TextureManager* textureManager, float width, float height, CollType collType, float r, LPCWSTR stringTexture, float textureWidth, float textureHeight)
{
	_graficos = graficos;
	_textureManager = textureManager;
	_texture = _textureManager->CreateTexture(stringTexture, _graficos);
	/*_x = x;
	_y = y;
	_z = z;
	_angle = angle;
	_sX = 1;
	_sY = 1;
	_sZ = 1;*/
	_collType = collType;
	_frame = 0;
	_collWidth = _width = width;
	_collHeight = _height = height;
	_textureWidth = textureWidth;
	_textureHeight = textureHeight;
	if (collType == Circle)
		_r = r;

	_vertices = new CUSTOMVERTEXTEXTURE[4];
	_vertices[0] = { -_width / 2.0f, -_height / 2.0f, 0.5f, 0.0f, 1.0f };
	_vertices[1] = { _width / 2.0f, -_height / 2.0f, 0.5f, 1.0f, 1.0f };
	_vertices[2] = { -_width / 2.0f, _height / 2.0f, 0.5f, 0.0f, 0.0f };
	_vertices[3] = { _width / 2.0f, _height / 2.0f, 0.5f, 1.0f, 0.0f };
}
void Sprite::Draw()
{
	//Transform(_graficos);

	_graficos->BindTexture(_texture->getTexture());

	_graficos->DrawSprite(_vertices, 4);

}
void Sprite::SetUv(/*float x, float y,*/ float width, float height, int framesAncho)
{
	_collWidth = _width = width;
	_collHeight = _height = height;

	_vertices[0] = { -width / 2.0f, -height / 2.0f, 0.5f, width / _textureWidth * (_frame % framesAncho), 1.0f };
	_vertices[1] = { width / 2.0f, -height / 2.0f, 0.5f, width / _textureWidth * ((_frame) % framesAncho) + (width / _textureWidth), 1.0f };
	_vertices[2] = { -width / 2.0f, height / 2.0f, 0.5f, width / _textureWidth * (_frame % framesAncho), 0.0f };
	_vertices[3] = { width / 2.0f, height / 2.0f, 0.5f, width / _textureWidth * ((_frame) % framesAncho) + (width / _textureWidth), 0.0f };
}
void Sprite::LaterFrame()
{
	_frame++;
}
void Sprite::OnCollision(Entity2D *entidad)
{
	Penetration(entidad);
	if (_inamovible == false)
	{
		//_x++;
	}
}
void Sprite::Penetration(Entity2D *entidad)
{
	/*if (entidad->_inamovible)
	{
		if (_x < entidad->_x)
			_x = entidad->_x - _width;
		else if (_x > entidad->_x)
			_x = entidad->_x + _width;
	}
	if (entidad->_inamovible == false)
	{
		if (entidad->_x < _x)
			entidad->_x = _x - entidad->_width;
		else if (entidad->_x > _x)
			entidad->_x = _x + entidad->_width;
	}*/
	//entidad->_mass
}
