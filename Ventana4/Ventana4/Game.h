#ifndef GAME_H
#define GAME_H
#include "Api.h"
#include <windows.h>
#include <string>
#include "Ventana.h"
#include "Graphics.h"
#include "TextureManager.h"
#include "TimeMeter.h"
#include "CollisionManager.h"

using namespace std;


class VENTANA4_API Game {
public:
	bool startup(HINSTANCE hInstance);
	void loop();
	bool shutdown();
protected:
	Ventana* _ventanita;
	Graphics* _graficos;
	TextureManager* _textureManager;
	TimeMeter* _timeMeter;
	CollisionManager* _collisionManager;

	virtual bool onInit() { return true; };
	virtual bool onUpdate() { return true; };
	virtual void onDraw(){};
	virtual bool onShutdown() { return true; };
};

#endif
