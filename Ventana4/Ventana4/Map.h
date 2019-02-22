#ifndef MAP_H
#define MAP_H
#include "Api.h"
#include <Windows.h>
#include <string>
#include "Graphics.h"
#include "GameObject.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
using namespace std;

class VENTANA4_API Map
{
	int _map[10][20];
	GameObject* objectMap[10][20];
	SpriteRenderer* srs[10][20];

	Sprite* _dirt;
	Sprite* _sky;
	int tileSize;
	int _posX;
	int _posY;

public:
	Map(Graphics* graficos, float posX, float posY, Sprite* dirt, Sprite* sky );
	void LoadMap(int map[10][20]);
	void DrawMap();
};
#endif
