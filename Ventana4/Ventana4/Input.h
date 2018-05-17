#ifndef INPUT_H
#define INPUT_H
#include "Api.h"
#include <windows.h>
#include <dinput.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")


class VENTANA4_API Input
{
	LPDIRECTINPUT8 dip;
	LPDIRECTINPUTDEVICE8 keyDev;
	byte actualKeys[256];
	byte prevKeys[256];
	map<string, vector<int>*>keyMap;

public:
	~Input();
	void Initialize(HINSTANCE hInstance, HWND hWnd);
	void Update();
	bool keyJustPressed(unsigned short int);
	bool keyJustPressed(vector<unsigned short int>*);
	bool keyPressing(unsigned short int);
	bool keyPressing(vector<unsigned short int>*);
	bool keyJustReleased(unsigned short int key);
	bool keyJustReleased(vector<unsigned short int>* keys);
	void AddKeyMap(string codigo, unsigned short int key);
	vector<int>* GetKeyMap(string codigo);
	static Input * Instance;
	void Release();
	
};
#endif