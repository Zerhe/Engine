#ifndef PLASYSATE_H
#define PLAYSTATE_H
#include <windows.h>
#include <string>
#include "../Ventana4/Game.h"
#include "../Ventana4/Shape.h"
#include "../Ventana4/Sprite.h"

using namespace std;

class PlayState : public Game {
	Shape* _shape;
	Shape* _shape2;
	Sprite* _sprite;
protected:
	bool onInit();
	bool onUpdate();
	void onDraw();
	bool onShutdown();

};
#endif
