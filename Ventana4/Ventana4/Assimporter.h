#ifndef Assimporter_H
#define Assimporter_H
#include "Api.h"
#include "assimp\Importer.hpp"
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace Assimp;

class VENTANA4_API Assimporter
{
	bool LoadFile(const std::string& pFile);
};

#endif
