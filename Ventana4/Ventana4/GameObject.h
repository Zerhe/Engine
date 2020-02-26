#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Api.h"
#include "Graphics.h"
#include "Node.h"
#include "Component.h"
#include "Transform.h"
#include "SpriteRenderer.h"

using namespace std;

class VENTANA4_API GameObject : public Node
{
	Graphics* _graficos;
public:
	GameObject(Graphics* graficos);
	GameObject(Graphics* graficos,
		float posX, float posY, float posZ,
		float rotX, float rotY, float rotZ,
		float scaX, float scaY, float scaZ);
	Transform transform;
	bool _inamovible = false;
	int _mass;
	void Draw();
	void DrawTileMap(int tileSize, int height, int weight, int posX);
	Node* GetComponent(string typeSearch);
	void OnCollision(GameObject* entidad);
};
#endif
