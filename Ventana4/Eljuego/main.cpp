#include <windows.h>
#include <string>
#include "PlayState.h"
using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	PlayState* game = new PlayState();
	if (!game->startup(hInstance)) {
		return 1;
	}
	game->loop();

	if (!game->shutdown()){
		return 1;
	}

	return 0;
	if (game)
		delete game;
}