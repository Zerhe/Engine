#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(Mesh* mesh)
{
	_mesh = mesh;
}
void MeshRenderer::Draw()
{
	_mesh->Draw();
}
void MeshRenderer::SetMesh(Mesh* mesh)
{
	_mesh = mesh;
}
Mesh* MeshRenderer::GetMesh()
{
	return _mesh;
}