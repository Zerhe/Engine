#include "PlayState.h"

bool PlayState::onInit()
{
	_sprite = new Sprite(_graficos, _textureManager, 0, 0, 0, 0, 1, 1, 1, 0, 0, L"../Walk2.png");

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
		_sprite->SetUv(500.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f, 10);
		_contador = 0;
		_sprite->LaterFrame();
	}
	
	_sprite->_x--;
	if (_sprite->_x < -1000)
		_sprite->_x = 800;

	return true;
}