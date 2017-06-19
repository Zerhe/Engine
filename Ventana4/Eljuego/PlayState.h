#ifndef PLASYSATE_H
#define PLAYSTATE_H
#include <windows.h>
#include <string>
#include "../Ventana4/Game.h"
#include "../Ventana4/Shape.h"
#include "../Ventana4/Sprite.h"

using namespace std;

class PlayState : public Game {
	Sprite* _sprite;
	Sprite* _sprite2;
	Sprite* _sprite3;
	float _uvs[8] {0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f};
	int _contador = 0;
	int _frame = 0;

protected:
	bool onInit();
	bool onUpdate();
	void onDraw();
	bool onShutdown();

};
#endif
