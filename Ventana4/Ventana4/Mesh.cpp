#include "Mesh.h"
Mesh::Mesh(Graphics* graficos, TextureManager* textureManager, float x, float y, float z, float width, float height, float depth, LPCWSTR stringTexture, const char * model)
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
	_model = model;

	//LoadOBJ();

	/*  http://www.opengl-tutorial.org/es/beginners-tutorials/tutorial-7-model-loading/#cargando-el-obj tutorial loadOBJ*/

	_graficos->pd3dDevice->CreateVertexBuffer(_vertexSize * sizeof(CUSTOMVERTEXTEXTURE), 0, D3DFVF_CUSTOMVERTEXTEXTURE, D3DPOOL_MANAGED, &_vertexBuffer, NULL);
	_graficos->pd3dDevice->CreateIndexBuffer(_indexVertexSize * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, &_indexBuffer, NULL);

	VOID* lockedData = NULL;
	_vertexBuffer->Lock(0, _vertexSize *sizeof(CUSTOMVERTEXTEXTURE), (void**)&lockedData, 0);
	memcpy(lockedData, _vertex, _vertexSize *sizeof(CUSTOMVERTEXTEXTURE));
	_vertexBuffer->Unlock();

	_indexBuffer->Lock(0, _indexVertexSize *sizeof(WORD), (void**)&lockedData, 0);
	memcpy(lockedData, _indexVertex, _indexVertexSize *sizeof(WORD));
	_indexBuffer->Unlock();
}
void Mesh::Draw() {
	Transform(_graficos);

	_graficos->BindTexture(_texture->getTexture());

	_graficos->pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEXTEXTURE);
	_graficos->pd3dDevice->SetIndices(_indexBuffer);
	_graficos->pd3dDevice->SetStreamSource(0, _vertexBuffer, 0, sizeof(CUSTOMVERTEXTEXTURE));

	_graficos->pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, _vertexSize, 0, _indexVertexSize /3);
}
/*bool Mesh::LoadOBJ()
{
	FILE * file;
	fopen_s(&file,_model, "r");
	vector <CUSTOMVERTEXTEXTURE>* _vertices;
	vector< WORD >* _verIndices,* _uvIndices;
	

	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return false;
	}
	while (1) 
	{
		char lineHeader[128];
		int res = fscanf_s(file, "%s", lineHeader);
		if (res == EOF)
			break;

		if (strcmp(lineHeader, "v") == 0) {
			CUSTOMVERTEXTEXTURE vertex;
			fscanf_s(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			_vertices->push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			CUSTOMVERTEXTEXTURE uv;
			fscanf_s(file, "%f %f\n", &uv.x, &uv.y);
			//_uvs->push_back(uv);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			//std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9)
			{
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}
			_verIndices->push_back(vertexIndex[0]);
			_verIndices->push_back(vertexIndex[1]);
			_verIndices->push_back(vertexIndex[2]);
			_uvIndices->push_back(uvIndex[0]);
			_uvIndices->push_back(uvIndex[1]);
			_uvIndices->push_back(uvIndex[2]);
		}
	}
	_vertexSize = _vertices->size;
	_indexVertexSize = _verIndices->size;
	_vertex = new CUSTOMVERTEXTEXTURE[_vertexSize];
	_indexVertex = new WORD[_indexVertexSize];
}*/