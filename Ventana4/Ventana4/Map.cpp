#include "Map.h"

Map::Map(Graphics* graficos, float posX, float posY, int tileSize, Sprite* tile01, Sprite* tile02, const char * tileMapLocation)
{
	_tileSize = tileSize;
	_posX = posX;
	_posY = posY;
	_tile01 = tile01;
	_tile02 = tile02;
	_tileMapLocation = tileMapLocation;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			objectMap[i][j] = new GameObject(graficos, _posX, _posY, 0, 0, 0, 0, 1, 1, 1);
			_posX += _tileSize;
		}
		_posX = posX;
		_posY -= _tileSize;
	}

	//objectMap = new GameObject(graficos, _posX, _posY, 0, 0, 0, 0, 1, 1, 1);

	LoadMap(_tileMapLocation);
}
void Map::LoadMap(const char * tileMapLocation)
{
	std::ifstream openfile(tileMapLocation);
	string s;
	openfile >> s;
	_height = Lib::StringToInt(s);
	openfile >> s;
	_weight = Lib::StringToInt(s);
	
	int type = 0;

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _weight; j++)
		{
			//_map[i][j] = map[i][j];
			openfile >> _map[i][j];

			type = _map[i][j];

			switch (type)
			{
			case 0:
				srs[i][j] = new SpriteRenderer(_tile02);
				objectMap[i][j]->AddChild(srs[i][j]);
				//objectMap[i][j]->Draw();
				break;
			case 1:
				srs[i][j] = new SpriteRenderer(_tile01);
				objectMap[i][j]->AddChild(srs[i][j]);
				//objectMap[i][j]->Draw();
				break;
			default:
				break;
			}
		}
	}
}
void Map::DrawMap()
{
	//objectMap->DrawTileMap(_tileSize, _height, _weight, _posX);
	//objectMap->Draw();

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _weight; j++)
		{
			objectMap[i][j]->Draw();
		}
	}
}