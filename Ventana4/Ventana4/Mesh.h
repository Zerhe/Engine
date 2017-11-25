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
	int _vertexSize;
	int _indexVertexSize;
	LPDIRECT3DVERTEXBUFFER9	_vertexBuffer;
	LPDIRECT3DINDEXBUFFER9 _indexBuffer;
	D3DXVECTOR3* _boundingBox;
	const char * _model;
public:
	Mesh(Graphics* graficos, TextureManager* textureManager, LPCWSTR stringTexture, const char * model);
	void Draw();
	bool LoadOBJ();
	bool CompareVertex(CUSTOMVERTEXTEXTURE vertex01, CUSTOMVERTEXTEXTURE vertex02);
	void GenerateBoundingBox();
};
#endif
