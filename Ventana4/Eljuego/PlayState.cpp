#include "PlayState.h"

bool PlayState::onInit()
{
	_sprite = new Sprite(_graficos, _textureManager, 0, 0, 0, 0, 1, 1, 1, L"../Walk2.png");

	return true;
}
void PlayState::onDraw() 
{
	if (_sprite)
	_sprite->Draw();
}
bool PlayState::onShutdown() 
{
	if (_sprite)
		delete _sprite;
	return true;
}
bool PlayState::onUpdate() 
{
	_contador++;
	switch (_contador)
	{
		case 20:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 0, 10);
			break;
		case 40:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 1, 10);
			break;
		case 60:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 2, 10);
			break;
		case 80:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 3, 10);
			break;
		case 100:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 4, 10);
			break;
		case 120:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 5, 10);
			break;
		case 140:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 6, 10);
			break;
		case 160:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 7, 10);
			break;
		case 180:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 8, 10);
			break;
		case 200:
			_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 9, 10);
			_contador = 0;
			break;
	}
	_sprite->_x--;
	if (_sprite->_x < -1000)
		_sprite->_x = 800;
	return true;
}