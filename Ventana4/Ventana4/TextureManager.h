#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "Api.h"
#include "Graphics.h"
#include "Texture.h"
#include <list>
using namespace std;

class VENTANA4_API TextureManager 
{
	list <Texture*> listaTexturas;
	list<Texture*>::iterator iterBegin = listaTexturas.begin();
	list<Texture*>::iterator iterEnd = listaTexturas.end();
	list<Texture*>::iterator iter;
	bool textureExists = false;

public:
	Texture* CreateTexture(LPCWSTR stringTexture, Graphics* graficos)
	{
		for (iter = iterBegin; iter != iterEnd && textureExists != true; iter++)
		{
			if ((*iter)->getName() == stringTexture)
				textureExists = true;
		}
		if (textureExists)
		{
			return *iter;
		}
		else
		{
			Texture* textura = new Texture();
			listaTexturas.push_front(textura);
			textura->setTexture(graficos->LoadTexture(stringTexture));
			textura->setName(stringTexture);
			textura->aumentarCantReference();
			
			return textura;
		}
	}
};
#endif
