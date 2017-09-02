#include "Mesh.h"
Mesh::Mesh(Graphics *graficos, float x, float y, float z, float angle)
{
	_graficos = graficos;
	_x = x;
	_y = y;
	_z = z;
	_angle = angle;

	_vertices = new CUSTOMVERTEX[4];
	_vertices[0] = { 0.0f, 0.0f, 0.5f, D3DCOLOR_ARGB(255, 255, 0, 255), };
	_vertices[1] = { 100.0f, 0.0f, 0.5f, D3DCOLOR_ARGB(255, 255, 255, 0), };
	_vertices[2] = { 0.0f, 100.0f, 0.5f, D3DCOLOR_ARGB(255, 0, 255, 255), };
	_vertices[3] = { 100.0f, 100.0f, 0.5f, D3DCOLOR_ARGB(255, 0, 255, 255), };

	_indices = new WORD[6];
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;
	_indices[3] = 1;
	_indices[4] = 2;
	_indices[5] = 3;

	_graficos->pd3dDevice->CreateVertexBuffer(4 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_MANAGED, &_vertexBuffer, NULL);
	_graficos->pd3dDevice->CreateIndexBuffer(6 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, &_indexBuffer, NULL);

	VOID* lockedData = NULL;
	_vertexBuffer->Lock(0, 0, (void**)&lockedData, 0);
	memcpy(lockedData, &_vertices, sizeof(_vertices));
	_vertexBuffer->Unlock();

	_indexBuffer->Lock(0, 0, (void**)&lockedData, 0);
	memcpy(lockedData, &_indices, sizeof(_indices));
	_indexBuffer->Unlock();
}
void Mesh::Draw() {
	Transform(_graficos);
	_graficos->BindTexture(NULL);



	_graficos->pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	_graficos->pd3dDevice->SetIndices(_indexBuffer);
	_graficos->pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEX));

	_graficos->pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}