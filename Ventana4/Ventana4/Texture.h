#ifndef TEXTURE_H
#define TEXTURE_H
#include "Api.h"
#include "Graphics.h"
using namespace std;

class VENTANA4_API Texture {
	LPDIRECT3DTEXTURE9 _texture;
	int _cantReference = 0;
	LPCWSTR _name;
public:
	LPCWSTR getName()
	{
		return _name;
	}
	void setName(LPCWSTR name)
	{
		_name = name;
	}
	void aumentarCantReference()
	{
		_cantReference++;
	}
	void disminuirCantReference()
	{
		_cantReference--;
	}
	LPDIRECT3DTEXTURE9 getTexture()
	{
		return _texture;
	}
	void setTexture(LPDIRECT3DTEXTURE9 texture)
	{
		_texture = texture;
	}
};
#endif