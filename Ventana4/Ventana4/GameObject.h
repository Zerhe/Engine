#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Api.h"
#include "Graphics.h"
#include "Node.h"
#include "Component.h"
#include "Transform.h"

using namespace std;

class VENTANA4_API GameObject : public Node
{
	Graphics* _graficos;
public:
	GameObject(Graphics* graficos);
	Transform transform;
	void Draw();
};
#endif
