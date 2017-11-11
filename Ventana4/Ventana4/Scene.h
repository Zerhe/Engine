#ifndef SCENE_H
#define SCENE_H
#include "Api.h"
#include "Graphics.h"
#include "GameObject.h"
#include "Node.h"


class VENTANA4_API Scene : public Node
{
	Graphics* _graficos;

public:
	Scene(Graphics* graficos);
	void Draw();
};
#endif
