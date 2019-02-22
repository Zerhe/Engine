#ifndef Assimporter_H
#define Assimporter_H
#include "Api.h"
#include "Libraries\Assimp\include\assimp\Importer.hpp"
#include "Libraries\Assimp\include\assimp\scene.h"
#include "Libraries\Assimp\include\assimp\postprocess.h"
#include "GameObject.h"
#include "MeshRenderer.h"
#include "Mesh.h"
#include "Graphics.h"

/*class VENTANA4_API Assimporter
{
	Graphics* _graficos;
public:
	Assimporter(Graphics* graficos);
<<<<<<< HEAD
	//bool LoadFile(const std::string& pFile);
	//void CopyNodesWithMeshes(aiNode node, GameObject targetParent);
};*/
=======
	GameObject* LoadFile(const std::string& pFile);
	void CopyNodesWithMeshes(aiNode* node, GameObject* targetParent);
};
>>>>>>> 235022ba36d40fc6fefbbb4d49afb30a8d0b8408

#endif
