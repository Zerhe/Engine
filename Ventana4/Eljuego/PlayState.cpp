#include "PlayState.h"

bool PlayState::onInit()
{
	_sprite = new Sprite(_graficos, _textureManager, 0, 0, 0, 0, 1, 1, 1, Square, 0, L"../Walk2.png", 2000.0f, 312.0f);
	_sprite2 = new Sprite(_graficos, _textureManager, 0, 0, 0, 0, 1, 1, 1, Square, 0, L"../Walk2.png", 2000.0f, 312.0f);
	_collisionManager->Register(_sprite, 1);
	_collisionManager->Register(_sprite2, 2);

	return true;
}
void PlayState::onDraw() 
{
	if (_sprite)
	_sprite->Draw();
	if (_sprite2)
		_sprite2->Draw();
}
bool PlayState::onShutdown() 
{
	if (_sprite)
		delete _sprite;
	if (_sprite2)
		delete _sprite2;
	return true;
}
bool PlayState::onUpdate() 
{
	_contador++;
	if (_contador == 20)
	{
		_sprite->SetUv(500.0f, 200.0f, 200.0f, 312.0f, 10);
		_sprite->LaterFrame();
		_sprite2->SetUv(100.0f, 200.0f, 200.0f, 312.0f, 10);
		_sprite2->LaterFrame();
		_contador = 0;
	}
	
	_sprite->_x--;
	if (_sprite->_x < -1000)
		_sprite->_x = 800;

	return true;
}