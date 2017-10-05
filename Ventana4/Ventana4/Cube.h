#ifndef CUBE_H
#define CUBE_H
#include "Api.h"
#include "Entity3D.h"
#include "Graphics.h"
#include "TextureManager.h"
#include "Texture.h"
#include <vector>

using namespace std;

class VENTANA4_API Cube : public Entity3D
{
	Graphics* _graficos;
	TextureManager* _textureManager;
	Texture* _texture;
	CUSTOMVERTEXTEXTURE* _vertices;
	WORD* _indices;
	LPDIRECT3DVERTEXBUFFER9	_vertexBuffer;
	LPDIRECT3DINDEXBUFFER9 _indexBuffer;
public:
	Cube(Graphics* graficos, TextureManager* textureManager, float x, float y, float z, float width, float height, float depth, LPCWSTR stringTexture);
	void Draw();
};
#endif

