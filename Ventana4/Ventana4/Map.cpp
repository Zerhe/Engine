#include "Map.h"

Map::Map(Graphics* graficos, float posX, float posY, Sprite* dirt, Sprite* sky)
{
	tileSize = 75;
	_posX = posX;
	_posY = posY;
	_dirt = dirt;
	_sky = sky;
	int map01[10][20] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			objectMap[i][j] = new GameObject(graficos, _posX, _posY, 0, 0, 0, 0, 1, 1, 1);
			_posX += tileSize;
		}
		_posX = posX;
		_posY -= tileSize;
	}
	LoadMap(map01);
}
void Map::LoadMap(int map[10][20])
{
	int type = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			_map[i][j] = map[i][j];

			type = _map[i][j];

			switch (type)
			{
			case 0:
				srs[i][j] = new SpriteRenderer(_sky);
				objectMap[i][j]->AddChild(srs[i][j]);
				//objectMap[i][j]->Draw();
				break;
			case 1:
				srs[i][j] = new SpriteRenderer(_dirt);
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
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			objectMap[i][j]->Draw();
		}
	}
}