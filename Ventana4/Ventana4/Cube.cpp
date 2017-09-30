#include "Cube.h"
Cube::Cube(Graphics* graficos, TextureManager* textureManager, float x, float y, float z, float width, float height, float depth, LPCWSTR stringTexture)
{
	_graficos = graficos;
	_textureManager = textureManager;
	_texture = _textureManager->CreateTexture(stringTexture, _graficos);
	_x = x;
	_y = y;
	_z = z;
	_width = width;
	_height = height;
	_depth = depth;

	/*_vertices = new CUSTOMVERTEXTEXTURE[24];
	_vertices[0] = { -_width / 2.0f, -_height / 2.0f, -_depth/ 2, 0.0f, 1.0f };
	_vertices[1] = { _width / 2.0f, -_height / 2.0f, -_depth / 2, 1.0f, 1.0f };
	_vertices[2] = { -_width / 2.0f, _height / 2.0f, -_depth / 2, 0.0f, 0.0f };
	_vertices[3] = { _width / 2.0f, _height / 2.0f, -_depth / 2, 1.0f, 0.0f };

	_vertices[4] = { _width / 2.0f, -_height / 2.0f, -_depth / 2, 0.0f, 1.0f };
	_vertices[5] = { _width / 2.0f, -_height / 2.0f, _depth / 2, 1.0f, 1.0f };
	_vertices[6] = { _width / 2.0f, _height / 2.0f, -_depth / 2, 0.0f, 0.0f };
	_vertices[7] = { _width / 2.0f, _height / 2.0f, _depth / 2, 1.0f, 0.0f };

	_vertices[8] = { _width / 2.0f, -_height / 2.0f, _depth / 2, 0.0f, 1.0f };
	_vertices[9] = { -_width / 2.0f, -_height / 2.0f, _depth / 2, 1.0f, 1.0f };
	_vertices[10] = { _width / 2.0f, _height / 2.0f, _depth / 2, 0.0f, 0.0f };
	_vertices[11] = { -_width / 2.0f, _height / 2.0f, _depth / 2, 1.0f, 0.0f };

	_vertices[12] = { -_width / 2.0f, -_height / 2.0f, _depth / 2, 0.0f, 1.0f };
	_vertices[13] = { -_width / 2.0f, -_height / 2.0f, -_depth / 2, 1.0f, 1.0f };
	_vertices[14] = { -_width / 2.0f, _height / 2.0f, _depth / 2, 0.0f, 0.0f };
	_vertices[15] = { -_width / 2.0f, _height / 2.0f, -_depth / 2, 1.0f, 0.0f };

	_vertices[16] = { -_width / 2.0f, _height / 2.0f, -_depth / 2, 0.0f, 1.0f };
	_vertices[17] = { _width / 2.0f, _height / 2.0f, -_depth / 2, 1.0f, 1.0f };
	_vertices[18] = { -_width / 2.0f, _height / 2.0f, _depth / 2, 0.0f, 0.0f };
	_vertices[19] = { _width / 2.0f, _height / 2.0f, _depth / 2, 1.0f, 0.0f };

	_vertices[20] = { -_width / 2.0f, -_height / 2.0f, _depth / 2, 0.0f, 1.0f };
	_vertices[21] = { _width / 2.0f, -_height / 2.0f, _depth / 2, 1.0f, 1.0f };
	_vertices[22] = { -_width / 2.0f, -_height / 2.0f, -_depth / 2, 0.0f, 0.0f };
	_vertices[23] = { _width / 2.0f, -_height / 2.0f, -_depth / 2, 1.0f, 0.0f };

	_indices = new WORD[36]
	{
		0,1,2,
		2,1,3,
		4,5,6,
		6,5,7,
		8,9,10,
		10,9,11,
		12,13,14,
		14,13,15,
		16,17,18,
		18,17,19,
		20,21,22,
		22,21,23,
	};*/

	_graficos->pd3dDevice->CreateVertexBuffer(24 * sizeof(CUSTOMVERTEXTEXTURE), 0, D3DFVF_CUSTOMVERTEXTEXTURE, D3DPOOL_MANAGED, &_vertexBuffer, NULL);
	_graficos->pd3dDevice->CreateIndexBuffer(36 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, &_indexBuffer, NULL);

	VOID* lockedData = NULL;
	_vertexBuffer->Lock(0, 24 * sizeof(CUSTOMVERTEXTEXTURE), (void**)&lockedData, 0);
	memcpy(lockedData, _vertices, 24 * sizeof(CUSTOMVERTEXTEXTURE));
	_vertexBuffer->Unlock();

	_indexBuffer->Lock(0, 36 * sizeof(WORD), (void**)&lockedData, 0);
	memcpy(lockedData, _indices, 36 * sizeof(WORD));
	_indexBuffer->Unlock();
}
void Cube::Draw() {
	Transform(_graficos);

	_graficos->BindTexture(_texture->getTexture());

	_graficos->pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEXTEXTURE);
	_graficos->pd3dDevice->SetIndices(_indexBuffer);
	_graficos->pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEXTEXTURE));

	_graficos->pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
}