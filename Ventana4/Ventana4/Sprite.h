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
	int _frame;
public:
	Sprite(Graphics *graficos, TextureManager* textureManager, float x, float y, float z, float angle, float sx, float sy, float sz, float r, int collType, LPCWSTR stringTexture);
	void Draw();
	void SetUv(float x, float y, float width, float height, int textureWidth, int textureHeight, int framesAncho);
	void LaterFrame();
};
#endif
