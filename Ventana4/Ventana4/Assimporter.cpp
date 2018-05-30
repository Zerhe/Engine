#include "Assimporter.h"

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
	return true;
}