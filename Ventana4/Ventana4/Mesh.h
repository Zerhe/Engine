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
	vector <CUSTOMVERTEXTEXTURE>* _vertices;
	vector <WORD>* _indices;
	LPDIRECT3DVERTEXBUFFER9	_vertexBuffer;
	LPDIRECT3DINDEXBUFFER9 _indexBuffer;
public:
	Mesh(Graphics* graficos, TextureManager* textureManager, float x, float y, float z, float width, float height, float depth, LPCWSTR stringTexture);
	void Draw();
	bool LoadOBJ();
};
#endif
