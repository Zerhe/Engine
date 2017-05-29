#include "PlayState.h"

bool PlayState::onInit()
{
	_shape = new Shape(_graficos, 0, 0, 0, 45, 1, 1, 1);
	_shape2 = new Shape(_graficos, 520, 60, 0, 135, 1, 1, 1);
	_sprite = new Sprite(_graficos, 0, 0, 0, 0, 1, 1, 1, L"../Wolf.png");
	return true;
}
void PlayState::onDraw() 
{
	_shape->Draw();
	_shape2->Draw();
	_sprite->Draw();
}
bool PlayState::onShutdown() 
{
	if (_shape)
		delete _shape;
	else if (_shape2)
		delete _shape2;
	else if (_sprite)
		delete _sprite;
	return true;
}
bool PlayState::onUpdate() 
{
	return true;
}