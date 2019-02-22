#include "Sprite.h"

Sprite::Sprite(Graphics* graficos, TextureManager* textureManager, float width, float height, CollType collType, float r, LPCWSTR stringTexture, float textureWidth, float textureHeight, int cantFrames)
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
	_cantFrames = cantFrames;
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

	if(_cantFrames > 1)
	{
		LaterFrame();
	}
}
void Sprite::Draw()
{
	//Transform(_graficos);

	_graficos->BindTexture(_texture->getTexture());

	_graficos->DrawSprite(_vertices, 4);

}
void Sprite::LaterFrame()
{
	//_collWidth = _width = width;
	//_collHeight = _height = height;

	_vertices[0] = { -_width / 2.0f, -_height / 2.0f, 0.5f, ((_textureWidth / _cantFrames) / _textureWidth * (_frame % _cantFrames)) * _flipX, 1.0f };
	_vertices[1] = { _width / 2.0f, -_height / 2.0f, 0.5f, ((_textureWidth / _cantFrames) / _textureWidth * ((_frame) % _cantFrames) + ((_textureWidth / _cantFrames) / _textureWidth)) * _flipX, 1.0f };
	_vertices[2] = { -_width / 2.0f, _height / 2.0f, 0.5f, ((_textureWidth / _cantFrames) / _textureWidth * (_frame % _cantFrames)) * _flipX, 0.0f };
	_vertices[3] = { _width / 2.0f, _height / 2.0f, 0.5f, ((_textureWidth / _cantFrames) / _textureWidth * ((_frame) % _cantFrames) + ((_textureWidth / _cantFrames) / _textureWidth)) * _flipX, 0.0f };
	
	_frame++;
}
void Sprite::FlipX(bool flipx)
{
	if (flipx)
		_flipX = -1;
	else
		_flipX = 1;

	if (_cantFrames < 1)
	{
		_vertices[0] = { -_width / 2.0f, -_height / 2.0f, 0.5f, 0.0f * _flipX, 1.0f };
		_vertices[1] = { _width / 2.0f, -_height / 2.0f, 0.5f, 1.0f * _flipX, 1.0f };
		_vertices[2] = { -_width / 2.0f, _height / 2.0f, 0.5f, 0.0f * _flipX, 0.0f };
		_vertices[3] = { _width / 2.0f, _height / 2.0f, 0.5f, 1.0f * _flipX, 0.0f };
	}
}

