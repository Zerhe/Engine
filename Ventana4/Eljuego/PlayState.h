#ifndef PLASYSATE_H
#define PLAYSTATE_H
#include <windows.h>
#include <string>
#include "../Ventana4/Game.h"
#include "../Ventana4/GameObject.h"
#include "../Ventana4/Scene.h"
#include "../Ventana4/MeshRenderer.h"
#include "../Ventana4/SpriteRenderer.h"
#include "../Ventana4/Shape.h"
#include "../Ventana4/Sprite.h"
#include "../Ventana4/Mesh.h"
#include "../Ventana4/Camera.h"
#include "../Ventana4/Cube.h"
#include "../Ventana4/Map.h"

using namespace std;

class PlayState : public Game {
	Scene* _scene01;
	GameObject* _cameraObject;
	GameObject* _zombie01;
	GameObject* _zombie02;
	GameObject* _sol;
	GameObject* _piedra;
	GameObject* _cubo;
	GameObject* _objectEmpty;
	Camera* _camera;
	Sprite* _sprite01;
	Sprite* _sprite02;
	Sprite* _sprite03;
	Sprite* _sprite04;
	Sprite* _sprite05;
	Sprite* _sprite06;
	Mesh* _mesh;
	Map* _map;
	SpriteRenderer* _spriteRenderer01;
	SpriteRenderer* _spriteRenderer02;
	SpriteRenderer* _spriteRenderer03;
	SpriteRenderer* _spriteRenderer04;
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
