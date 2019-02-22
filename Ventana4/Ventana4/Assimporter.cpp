#include "Assimporter.h"

/*Assimporter::Assimporter(Graphics* graficos)
{
	_graficos = graficos;
}
<<<<<<< HEAD
/*bool Assimporter::LoadFile(const std::string& pFile)
=======
GameObject* Assimporter::LoadFile(const std::string& pFile)
>>>>>>> 235022ba36d40fc6fefbbb4d49afb30a8d0b8408
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(pFile,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType |
		aiProcess_MakeLeftHanded);

	if (!scene)
	{
		importer.GetErrorString();
	}
	GameObject* objetoPadre = new GameObject(_graficos);

	CopyNodesWithMeshes(scene->mRootNode, objetoPadre);

<<<<<<< HEAD

	return true;
}*/
/*void Assimporter::CopyNodesWithMeshes(aiNode node, GameObject targetParent)
=======
	return objetoPadre;
}
void Assimporter::CopyNodesWithMeshes(aiNode* node, GameObject* targetParent)
>>>>>>> 235022ba36d40fc6fefbbb4d49afb30a8d0b8408
{
	GameObject* parent;
	// if node has meshes, create a new scene object for it
	if (node->mNumMeshes > 0)
	{
<<<<<<< HEAD
		GameObject* newObject = new GameObject();
		targetParent.AddChild(newObject);
=======
		GameObject* newObject = new GameObject(_graficos);
		targetParent->AddChild(newObject);
>>>>>>> 235022ba36d40fc6fefbbb4d49afb30a8d0b8408
		// copy the meshes
		//CopyMeshes(node, newObject); copiar el mesh del nodo al gameobject
		// the new object is the parent for all child nodes
		parent = newObject;
		//transform.SetUnity(); guardar la transformacion del nodo en el gameobject
	}
	else
	{
		// if no meshes, skip the node, but keep its transformation
		GameObject* newObject = new GameObject(_graficos);
		targetParent->AddChild(newObject);
		parent = newObject;
		//transform = node.mTransformation * accTransform; guardar la transformacion del nodo en el gameobject
	}
	// continue for all child nodes
<<<<<<< HEAD
	for (all node.mChildren)
		CopyNodesWithMeshes(node.mChildren[a], parent, transform);
}*/
=======
	for (int i = 0; i < node->mNumChildren; i++)
		CopyNodesWithMeshes(node->mChildren[i], parent);
}
>>>>>>> 235022ba36d40fc6fefbbb4d49afb30a8d0b8408
