#ifndef VENTANA_H
#define VENTANA_H
#include "Api.h"
#include <windows.h>
#include <string>
using namespace std;

class VENTANA4_API Ventana {
	HWND		hWnd;
	wstring		className = L"NombreClase";
public:
	void registerClass(HINSTANCE hInstance);
	bool createWindow(HINSTANCE hInstance, wstring title, int width, int height);
	HWND getHwnd() { return hWnd; };
};
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif
