#ifndef SPRITE_H
#define SPRITE_H
#include "Api.h"
#include <Windows.h>
#include <string>
#include "Entity2D.h"
#include "Graphics.h"
using namespace std;

class VENTANA4_API Sprite : public Entity2D {
	Graphics* _graficos;
	LPDIRECT3DTEXTURE9 _texture;
	CUSTOMVERTEXTEXTURE* _vertices;
public:
	Sprite(Graphics *graficos, float x, float y, float z, float angle, float sx, float sy, float sz, LPCWSTR stringTexture);
	void Draw();
	void setPosition(float x, float y, float width, float height, int textureWidth, int textureHeight);
	void setUv();
};
#endif
