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
	float _textureWidth = 0;
	float _textureHeight = 0;;
	Sprite(Graphics* graficos, TextureManager* textureManager, float width, float height, CollType collType, float r, LPCWSTR stringTexture, float textureWidth, float textureHeight);
	void Draw();
	void SetUv(/*float x, float y,*/ float width, float height, int framesAncho);
	void LaterFrame();	
};
#endif
