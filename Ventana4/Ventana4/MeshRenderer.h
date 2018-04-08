#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#include "Api.h"
#include "Component.h"
#include "Mesh.h"
#include "Frustum.h"

using namespace std;

class VENTANA4_API MeshRenderer : public Component
{
	Mesh* _mesh;
	Frustum* _frustum;

public:
	MeshRenderer(Frustum* frustum, Mesh* mesh);
	void Draw();
	void SetMesh(Mesh* mesh);
	Mesh* GetMesh();
};
#endif
