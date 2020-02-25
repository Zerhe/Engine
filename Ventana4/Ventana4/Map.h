#ifndef MAP_H
#define MAP_H
#include "Api.h"
#include <fstream>
#include <cctype>
#include <Windows.h>
#include <sstream> 
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
	//GameObject* objectMap;
	SpriteRenderer* srs[10][20];
	Vector2 tilesPositions;

	Sprite* _tile01;
	Sprite* _tile02;
	int _tileSize;
	int _height;
	int _weight;
	int _posX;
	int _posY;
	const char * _tileMapLocation;

public:
	Map(Graphics* graficos, float posX, float posY, int tileSize, Sprite* tile01, Sprite* tile02, const char * tileMapLocation);
	void LoadMap(const char * tileMapLocation);
	void DrawMap();
};
#endif
