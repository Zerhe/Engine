#include "PlayState.h"

bool PlayState::onInit()
{
	_sprite = new Sprite(_graficos, 0, 0, 0, 0, 1, 1, 1, L"../Walk2.png");

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
			_sprite->setPosition(200.0f, 200.0f, 200.0f, 312.0f, 2000.0f, 312.0f);
			break;
		case 50:
			break;
		default:
			break;
	}
	return true;
}