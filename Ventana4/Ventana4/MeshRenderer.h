#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#include "Api.h"
#include "Component.h"
#include "Mesh.h"

using namespace std;

class VENTANA4_API MeshRenderer : public Component
{
	Mesh* _mesh;
public:
	MeshRenderer(Mesh* mesh);
	void Draw();
	void SetMesh(Mesh* mesh);
	Mesh* GetMesh();
};
#endif
