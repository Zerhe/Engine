#include "Assimporter.h"

Assimporter::Assimporter(Graphics* graficos)
{
	_graficos = graficos;
}
bool Assimporter::LoadFile(const std::string& pFile)
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



	return true;
}
void CopyNodesWithMeshes(aiNode node, SceneObject targetParent)
{
	GameObject* parent;
	// if node has meshes, create a new scene object for it
	if (node.mNumMeshes > 0)
	{
		GameObject* newObject = new GameObject();
		targetParent.addChild(newObject);
		// copy the meshes
		CopyMeshes(node, newObject);
		// the new object is the parent for all child nodes
		parent = newObject;
		transform.SetUnity();
	}
	else
	{
		// if no meshes, skip the node, but keep its transformation
		parent = targetParent;
		transform = node.mTransformation * accTransform;
	}
	// continue for all child nodes
	for (all node.mChildren)
		CopyNodesWithMeshes(node.mChildren[a], parent, transform);
}