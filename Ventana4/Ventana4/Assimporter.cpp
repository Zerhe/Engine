#include "Assimporter.h"

Assimporter::Assimporter(Graphics* graficos)
{
	_graficos = graficos;
}
GameObject* Assimporter::LoadFile(const std::string& pFile)
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

	return objetoPadre;
}
void Assimporter::CopyNodesWithMeshes(aiNode* node, GameObject* targetParent)
{
	GameObject* parent;
	// if node has meshes, create a new scene object for it
	if (node->mNumMeshes > 0)
	{
		GameObject* newObject = new GameObject(_graficos);
		targetParent->AddChild(newObject);
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
	for (int i = 0; i < node->mNumChildren; i++)
		CopyNodesWithMeshes(node->mChildren[i], parent);
}