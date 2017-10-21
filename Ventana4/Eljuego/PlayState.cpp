#include "PlayState.h"

bool PlayState::onInit()
{
	_camera = new Camera(_graficos, 800.0f, 600.0f);
	_sprite = new Sprite(_graficos, _textureManager, 200.0f, 312.0f, Square, 0.0f, L"../Walk2.png", 2000.0f, 312.0f);
	_sprite2 = new Sprite(_graficos, _textureManager, 200.0f, 312.0f, Square, 0.0f, L"../Walk2.png", 2000.0f, 312.0f);
	_wolf = new Sprite(_graficos, _textureManager, 200.0f, 200.0f, Square, 0.0f, L"../Wolf.png", 800.0f, 772.0f);
	_mesh = new Mesh(_graficos, _textureManager, L"../Estrella.png", "../cube.obj");
	_mesh->LoadOBJ();

	_meshRenderer = new MeshRenderer(_mesh);

	_zombie01 = new GameObject(_graficos);
	_cubo = new GameObject(_graficos);
	_cubo->AddChild(_meshRenderer);

	_collisionManager->Register(_sprite, 1);
	_collisionManager->Register(_sprite2, 2);
	_sprite->_inamovible = false;
	_sprite2->_inamovible = false;

	return true;
}
void PlayState::onDraw() 
{
	if (_camera)
		_camera->Draw();
	if (_zombie01)
		_zombie01->Draw();
	if (_zombie02)
		_zombie02->Draw();
	if (_lobo)
		_lobo->Draw();
	if (_cubo)
		_cubo->Draw();

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
	if (_camera)
		delete _camera;
	if (_mesh)
		delete _mesh;
}
bool PlayState::onUpdate() 
{
	_contador++;
	accumTime += _timeMeter->GetDT();
	
	if (accumTime > 0.25)
	{ 
		accumTime -= 0.25;

		_sprite->SetUv(200.0f, 312.0f, 10);
		_sprite->LaterFrame();
		_sprite2->SetUv(200.0f, 312.0f, 10);
		_sprite2->LaterFrame();
	}
	if (_contador == 2)
	{
		//_camera->Pitch(1.0f * _timeMeter->GetDT());  Roto en x la camara
		_contador = 0;
	}
	//_camera->_pos.x-= 10.0 * _timeMeter->GetDT();    Muevo en x la camara
	/*_sprite->_x-= 10.0 * _timeMeter->GetDT();
	if (_sprite->_x < -1000)
		_sprite->_x = 800;
	_wolf->_angle+=10.0 * _timeMeter->GetDT();
	*/

	_cubo->transform._position->x = 300;
	_cubo->transform._position->y = 300;
	_cubo->transform._rotation->x += 10.0 *_timeMeter->GetDT();;

	return true;
}