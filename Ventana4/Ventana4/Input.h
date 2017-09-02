#ifndef INPUT_H
#define INPUT_H
#include "Api.h"
#include <windows.h>
#include <dinput.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

class VENTANA4_API Input
{
	LPDIRECTINPUT8 dip;
	LPDIRECTINPUTDEVICE8 keyDev;
	char actualKeys[256];
	map<string, vector<int>*>keyMap;
public:
	//void Initialize(HINSTANCE hInstance, HWND hWnd);
	//void Update();
	
};
#endif