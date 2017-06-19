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
	if (_contador == 20)
	{
		_sprite->setSize(800.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, _frame, 10);
		_contador = 0;
		_frame++;
	}
	
	_sprite->_x--;
	if (_sprite->_x < -1000)
		_sprite->_x = 800;

	if (_frame == 10)
	{
		_frame = 0;
	}
	return true;
}