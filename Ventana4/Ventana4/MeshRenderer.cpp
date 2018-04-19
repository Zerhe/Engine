#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(Frustum* frustum, Mesh* mesh)
{
	_frustum = frustum;
	_mesh = mesh;
}
void MeshRenderer::Draw()
{
	for (int i = 0; i < 2; i++)
	{
		_mesh->GenerateBoundingBox();
		if (_frustum->CheckPoint(_mesh->_boundingBox[i].x, _mesh->_boundingBox[i].y, _mesh->_boundingBox[i].z))
		{
			_mesh->Draw();
			break;
		}
	}
}
void MeshRenderer::SetMesh(Mesh* mesh)
{
	_mesh = mesh;
}
Mesh* MeshRenderer::GetMesh()
{
	return _mesh;
}