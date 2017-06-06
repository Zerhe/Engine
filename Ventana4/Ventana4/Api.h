#ifdef VENTANA4_EXPORTS
#define VENTANA4_API _declspec(dllexport)
#else
#define VENTANA4_API _declspec(dllimport)
#endif
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE)
#define D3DFVF_CUSTOMVERTEXTEXTURE (D3DFVF_XYZ | D3DFVF_TEX1)
//#include <windows.h>
//#include <string>
//#include "TextureManager.h"
