#include "Mesh.h"
Mesh::Mesh(Graphics* graficos, TextureManager* textureManager, LPCWSTR stringTexture, const char * model)
{
	_graficos = graficos;
	_textureManager = textureManager;
	_texture = _textureManager->CreateTexture(stringTexture, _graficos);
	_model = model;

	//LoadOBJ();

	/*  http://www.opengl-tutorial.org/es/beginners-tutorials/tutorial-7-model-loading/#cargando-el-obj tutorial loadOBJ*/

}
void Mesh::Draw() {
	GenerateBoundingBox();

	_graficos->BindTexture(_texture->getTexture());
	_graficos->pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEXTEXTURE);
	_graficos->pd3dDevice->SetIndices(_indexBuffer);
	_graficos->pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEXTEXTURE));
	_graficos->pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, _vertexSize, 0, _indexVertexSize / 3);
}
bool Mesh::LoadOBJ()
{
	FILE * file;
	fopen_s(&file, _model, "r");
	vector <D3DXVECTOR3>* _vertices = new vector <D3DXVECTOR3>();
	vector <D3DXVECTOR2>* _uvs = new vector <D3DXVECTOR2>();
	vector <CUSTOMVERTEXTEXTURE>* _verUvs = new vector <CUSTOMVERTEXTEXTURE>();
	vector < WORD >* _verIndices = new vector <WORD>();


	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return false;
	}
	while (1)
	{
		char lineHeader[128];
		int res = fscanf_s(file, "%s", lineHeader, 128);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0) {
			D3DXVECTOR3 vertex;
			fscanf_s(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			_vertices->push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			D3DXVECTOR2 uv;
			fscanf_s(file, "%f %f\n", &uv.x, &uv.y);
			_uvs->push_back(uv);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			CUSTOMVERTEXTEXTURE vertex;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

			fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);

			for (int i = 0; i < 3; i++)
			{

				vertex.x = (*_vertices)[vertexIndex[i] - 1].x;
				vertex.y = (*_vertices)[vertexIndex[i] - 1].y;
				vertex.z = (*_vertices)[vertexIndex[i] - 1].z;
				vertex.u = (*_uvs)[uvIndex[i] - 1].x;
				vertex.v = (*_uvs)[uvIndex[i] - 1].y;

				int id = -1;
				for (int i = 0; i < _verUvs->size(); i++)
				{
					if (CompareVertex(vertex, (*_verUvs)[i]))
					{
						id = i;
						break;
					}
				}

				if (id == -1)
				{
					_verUvs->push_back(vertex);
					id = _verUvs->size() - 1;
				}

				_verIndices->push_back(id);
			}
		}
	}
	_vertexSize = _verUvs->size();
	_indexVertexSize = _verIndices->size();
	_vertex = new CUSTOMVERTEXTEXTURE[_vertexSize];
	_indexVertex = new WORD[_indexVertexSize];

	for (int i = 0; i < _vertexSize; i++)
	{
		_vertex[i] = (*_verUvs)[i];
	}
	int j = _indexVertexSize;
	for (int i = 0; i < _indexVertexSize; i++)
	{
		j--;
		_indexVertex[i] = (*_verIndices)[j];
	}

	_graficos->pd3dDevice->CreateVertexBuffer(_vertexSize * sizeof(CUSTOMVERTEXTEXTURE), 0, D3DFVF_CUSTOMVERTEXTEXTURE, D3DPOOL_MANAGED, &_vertexBuffer, NULL);
	_graficos->pd3dDevice->CreateIndexBuffer(_indexVertexSize * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, &_indexBuffer, NULL);

	VOID* lockedData = NULL;
	_vertexBuffer->Lock(0, _vertexSize * sizeof(CUSTOMVERTEXTEXTURE), (void**)&lockedData, 0);
	memcpy(lockedData, _vertex, _vertexSize * sizeof(CUSTOMVERTEXTEXTURE));
	_vertexBuffer->Unlock();

	_indexBuffer->Lock(0, _indexVertexSize * sizeof(WORD), (void**)&lockedData, 0);
	memcpy(lockedData, _indexVertex, _indexVertexSize * sizeof(WORD));
	_indexBuffer->Unlock();
}
bool Mesh::CompareVertex(CUSTOMVERTEXTEXTURE vertex01, CUSTOMVERTEXTEXTURE vertex02)
{
	if (vertex01.x == vertex02.x &&
		vertex01.y == vertex02.y &&
		vertex01.z == vertex02.z &&
		vertex01.u == vertex02.u &&
		vertex01.v == vertex02.v)
	{
		return true;
	}
	else
		return false;
}
void Mesh::GenerateBoundingBox()
{
	_boundingBox = new D3DXVECTOR3[8];

	int j;
	for (int i = 0; i < _vertexSize; i++)
	{
		j = 0;
		if (_vertex[i].x < _boundingBox[j].x)
		{
			_boundingBox[j].x = _vertex[i].x;
		}
		j++;
		if (_vertex[i].x < _boundingBox[j].x)
		{
			_boundingBox[j].x = _vertex[i].x;
		}
		j++;
	}
}
