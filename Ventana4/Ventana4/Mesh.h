#ifndef MESH_H
#define MESH_H
#include "Api.h"
#include "Entity3D.h"
#include "Graphics.h"

using namespace std;

class VENTANA4_API Mesh : public Entity3D
{
	Graphics* _graficos;
	CUSTOMVERTEX* _vertices;
	WORD* _indices;
	LPDIRECT3DVERTEXBUFFER9	_vertexBuffer;
	LPDIRECT3DINDEXBUFFER9 _indexBuffer;
public:
	Mesh(Graphics *graficos, float x, float y, float z, float angle);
	void Draw();
};
#endif
