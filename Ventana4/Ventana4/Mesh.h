#ifndef MESH_H
#define MESH_H
#include "Api.h"
#include "Entity3D.h"
#include "Graphics.h"
#include "TextureManager.h"
#include "Texture.h"
#include <vector>

using namespace std;

class VENTANA4_API Mesh : public Entity3D
{
	Graphics* _graficos;
	TextureManager* _textureManager;
	Texture* _texture;
	CUSTOMVERTEXTEXTURE* _vertex;
	WORD* _indexVertex ;
	float _vertexSize;
	float _indexVertexSize;
	LPDIRECT3DVERTEXBUFFER9	_vertexBuffer;
	LPDIRECT3DINDEXBUFFER9 _indexBuffer;
	const char * _model;
public:
	Mesh(Graphics* graficos, TextureManager* textureManager, float x, float y, float z, float width, float height, float depth, LPCWSTR stringTexture, const char * model);
	void Draw();
	//bool LoadOBJ();
};
#endif
