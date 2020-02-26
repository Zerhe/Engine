#include "Map.h"

Map::Map(Graphics* graficos, float posX, float posY, int tileSize, Sprite* tile01, Sprite* tile02, const char * tileMapLocation)
{
	_graficos = graficos;
	_tileSize = tileSize;
	_posX = posX;
	_posY = posY;
	_tile01 = tile01;
	_tile02 = tile02;
	_tileMapLocation = tileMapLocation;

	/*for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			objectMap[i][j] = new GameObject(graficos, _posX, _posY, 0, 0, 0, 0, 1, 1, 1);
			_posX += _tileSize;
		}
		_posX = posX;
		_posY -= _tileSize;
	}*/

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
	int posXinicial = _posX;
	int posYInicial = _posY;

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _weight; j++)
		{
			objectMap[i][j] = new GameObject(_graficos, _posX, _posY, 0, 0, 0, 0, 1, 1, 1);
			_posX += _tileSize;

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
		_posX = posXinicial;
		_posY -= _tileSize;
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
Vector2 Map::TileNearObject(GameObject* object)
{
	float smallerDistance = 0;
	float distance;
	Vector2 coords = { 0,1 };
	Vector3 object01;
	Vector3 object02;
	object01.x = object->transform.position->x;
	object01.y = object->transform.position->y;
	object01.z = object->transform.position->z;

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _weight; j++)
		{
			object02.x = objectMap[i][j]->transform.position->x;
			object02.y = objectMap[i][j]->transform.position->y;
			object02.z = objectMap[i][j]->transform.position->z;

			distance = Lib::CalculateDistance(object01, object02);

			if (i == 0 && j == 0)
			{
				smallerDistance = distance;
				coords.x = j;
				coords.y = i;
			}
			else
			{
				if (distance < smallerDistance)
				{
					smallerDistance = distance;
					coords.x = j;
					coords.y = i;
				}
			}
		}
	}
	return coords;
}