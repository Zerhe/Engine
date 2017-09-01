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
	char prevKeys[256];
	map<string, vector<int>*>keyMap;
public:
	void Initialize(HINSTANCE hInstance, HWND hWnd);
	void Update();
	bool keyJustPressed(int key);
	bool keyJustPressed(vector<int>* keys);
	bool keyPressing(int key);
	bool keyPressing(vector<int>* keys);
	bool keyJustReleased(int key);
	bool keyJustReleased(vector<int>* keys);
};
#endif