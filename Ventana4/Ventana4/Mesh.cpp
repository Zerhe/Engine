#include "Mesh.h"
Mesh::Mesh(Graphics *graficos, float x, float y, float z, float width, float height, float depth)
{
	_graficos = graficos;
	_x = x;
	_y = y;
	_z = z;
	_width = width;
	_height = height;
	_depth = depth;

	_vertices = new CUSTOMVERTEX[8];
	_vertices[0] = { -_width / 2.0f, -_height / 2.0f, -_depth/2, D3DCOLOR_ARGB(255, 255, 0, 255), };
	_vertices[1] = { _width / 2.0f, -_height / 2.0f, -_depth / 2, D3DCOLOR_ARGB(255, 255, 255, 0), };
	_vertices[2] = { -_width / 2.0f, _height / 2.0f, -_depth / 2, D3DCOLOR_ARGB(255, 0, 255, 255), };
	_vertices[3] = { _width / 2.0f, _height / 2.0f, -_depth / 2, D3DCOLOR_ARGB(255, 0, 255, 255), };

	_vertices[4] = { -_width / 2.0f, -_height / 2.0f, _depth / 2, D3DCOLOR_ARGB(255, 255, 0, 255), };
	_vertices[5] = { _width / 2.0f, -_height / 2.0f, _depth / 2, D3DCOLOR_ARGB(255, 255, 255, 0), };
	_vertices[6] = { -_width / 2.0f, _height / 2.0f, _depth / 2, D3DCOLOR_ARGB(255, 0, 255, 255), };
	_vertices[7] = { _width / 2.0f, _height / 2.0f, _depth / 2, D3DCOLOR_ARGB(255, 0, 255, 255), };

	_indices = new WORD[36];
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;

	_indices[3] = 1;
	_indices[4] = 2;
	_indices[5] = 3;

	_indices[6] = 1;
	_indices[7] = 5;
	_indices[8] = 3;

	_indices[9] = 5;
	_indices[10] = 3;
	_indices[11] = 7;

	_indices[12] = 4;
	_indices[13] = 5;
	_indices[14] = 6;

	_indices[15] = 5;
	_indices[16] = 6;
	_indices[17] = 7;

	_indices[18] = 4;
	_indices[19] = 0;
	_indices[20] = 6;

	_indices[21] = 0;
	_indices[22] = 6;
	_indices[23] = 2;

	_indices[24] = 0;
	_indices[25] = 1;
	_indices[26] = 4;

	_indices[27] = 1;
	_indices[28] = 4;
	_indices[29] = 5;

	_indices[30] = 2;
	_indices[31] = 3;
	_indices[32] = 6;

	_indices[33] = 3;
	_indices[34] = 6;
	_indices[35] = 7;

	_graficos->pd3dDevice->CreateVertexBuffer(8 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_MANAGED, &_vertexBuffer, NULL);
	_graficos->pd3dDevice->CreateIndexBuffer(36 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, &_indexBuffer, NULL);

	VOID* lockedData = NULL;
	_vertexBuffer->Lock(0, 8*sizeof(CUSTOMVERTEX), (void**)&lockedData, 0);
	memcpy(lockedData, _vertices, 8*sizeof(CUSTOMVERTEX));
	_vertexBuffer->Unlock();

	_indexBuffer->Lock(0, 36*sizeof(WORD), (void**)&lockedData, 0);
	memcpy(lockedData, _indices, 36*sizeof(WORD));
	_indexBuffer->Unlock();
}
void Mesh::Draw() {
	Transform(_graficos);
	_graficos->BindTexture(NULL);

	_graficos->pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	_graficos->pd3dDevice->SetIndices(_indexBuffer);
	_graficos->pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEX));

	_graficos->pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
}