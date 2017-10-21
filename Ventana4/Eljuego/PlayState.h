#ifndef PLASYSATE_H
#define PLAYSTATE_H
#include <windows.h>
#include <string>
#include "../Ventana4/Game.h"
#include "../Ventana4/GameObject.h"
#include "../Ventana4/MeshRenderer.h"
#include "../Ventana4/Shape.h"
#include "../Ventana4/Sprite.h"
#include "../Ventana4/Mesh.h"
#include "../Ventana4/Camera.h"
#include "../Ventana4/Cube.h"

using namespace std;

class PlayState : public Game {
	Camera* _camera;
	Sprite* _sprite;
	Sprite* _sprite2;
	Sprite* _wolf;
	Mesh* _mesh;
	GameObject* _zombie01;
	GameObject* _zombie02;
	GameObject* _lobo;
	GameObject* _cubo;
	MeshRenderer* _meshRenderer;
	
	int _contador = 0;
	double accumTime = 0.0;

protected:
	bool onInit();
	bool onUpdate();
	void onDraw();
	bool onShutdown();

};
#endif
