#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "Api.h"
#include <windows.h>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include "VertexBufferManager.h"

//#include <DirectXMath.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")


using namespace std;
struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};
struct CUSTOMVERTEXTEXTURE 
{
	FLOAT x, y, z;
	FLOAT u, v;
};
class VENTANA4_API Graphics
{
	LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;
	D3DVIEWPORT9 _viewport;
	LPDIRECT3D9 pD3D;
	LPDIRECT3DDEVICE9 pd3dDevice;
	D3DCOLOR _clearColor = 0xFF000000;
	VertexBufferManager <CUSTOMVERTEX, D3DFVF_CUSTOMVERTEX> vertexBufferShape;
	VertexBufferManager <CUSTOMVERTEXTEXTURE, D3DFVF_CUSTOMVERTEXTEXTURE> vertexBufferSprite;

public:
	 bool Initialize(HWND wndHandle, int width, int height);
	 void Shutdown();
	 void Clear();
	 void Begin();
	 void End();
	 void Present();
	 bool SetupScene();
	 void SetClearColor(unsigned int col) { _clearColor = col; }
	 unsigned int GetClearColor() { return _clearColor; }
	 void DrawShape(CUSTOMVERTEX* vertices, int cantVert);
	 void DrawSprite(CUSTOMVERTEXTEXTURE* vertices, int cantVert);
	 void LoadIdentity();
	 void Translate(float x, float y, float z);
	 void RotationZ(float angle);
	 void Scaling(float sx, float sy, float sz);
	 LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR stringTexture);
	 void BindTexture(LPDIRECT3DTEXTURE9 textura);
};
#endif 

