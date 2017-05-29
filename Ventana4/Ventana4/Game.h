#ifndef GAME_H
#define GAME_H
#include "Api.h"
#include <windows.h>
#include <string>
#include "Ventana.h"
#include "Graphics.h"
using namespace std;


class VENTANA4_API Game {
	Ventana* _ventanita;
public:
	bool startup(HINSTANCE hInstance);
	void loop();
	bool shutdown();
protected:
	Graphics* _graficos;
	virtual bool onInit() { return true; };
	virtual bool onUpdate() { return true; };
	virtual void onDraw(){};
	virtual bool onShutdown() { return true; };
};

#endif
