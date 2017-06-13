#ifndef SPRITE_H
#define SPRITE_H
#include "Api.h"
#include <Windows.h>
#include <string>
#include "Entity2D.h"
#include "Graphics.h"
#include "TextureManager.h"
#include "Texture.h"
using namespace std;

class VENTANA4_API Sprite : public Entity2D {
	Graphics* _graficos;
	TextureManager* _textureManager;
	Texture* _texture;
	CUSTOMVERTEXTEXTURE* _vertices;
public:
	Sprite(Graphics *graficos,TextureManager* textureManager, float x, float y, float z, float angle, float sx, float sy, float sz, LPCWSTR stringTexture);
	void Draw();
	void setSize(float x, float y, float width, float height, int textureWidth, int textureHeight, int izq, int der);
	void setUv();
};
#endif
