#ifndef Assimporter_H
#define Assimporter_H
#include "Api.h"
#include "Libraries\Assimp\include\assimp\Importer.hpp"
#include "Libraries\Assimp\include\assimp\scene.h"
#include "Libraries\Assimp\include\assimp\postprocess.h"

class VENTANA4_API Assimporter
{
	bool LoadFile(const std::string& pFile);
};

#endif
