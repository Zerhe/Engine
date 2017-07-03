#include "PlayState.h"

bool PlayState::onInit()
{
	_sprite = new Sprite(_graficos, _textureManager, 500.0f, 200.0f, 0.0f, 200.0f, 312.0f, 0.0f, Square, 0.0f, L"../Walk2.png", 2000.0f, 312.0f);
	_sprite2 = new Sprite(_graficos, _textureManager, 150.0f, 200.0f, 0.0f, 200.0f, 312.0f, 0.0f, Square, 0.0f, L"../Walk2.png", 2000.0f, 312.0f);
	_wolf = new Sprite(_graficos, _textureManager, 400.0f, 500.0f, 0.0f, 200.0f, 200.0f, 0.0f, Square, 0.0f, L"../Wolf.png", 800.0f, 772.0f);
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
	if (_wolf)
		_wolf->Draw();

}
bool PlayState::onShutdown() 
{
	if (_sprite)
		delete _sprite;
	if (_sprite2)
		delete _sprite2;
	if (_wolf)
		delete _wolf;
	return true;
}
bool PlayState::onUpdate() 
{
	accumTime += _timeMeter->GetDT();
	
	if (accumTime > 0.25)
	{ 
		accumTime -= 0.25;

		_sprite->SetUv(500.0f, 200.0f, 200.0f, 312.0f, 10);
		_sprite->LaterFrame();
		_sprite2->SetUv(100.0f, 200.0f, 200.0f, 312.0f, 10);
		_sprite2->LaterFrame();
	}
	
	_sprite->_x-= 10.0 * _timeMeter->GetDT();
	if (_sprite->_x < -1000)
		_sprite->_x = 800;
	_wolf->_angle+=10.0 * _timeMeter->GetDT();
	return true;
}