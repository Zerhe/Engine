#include "PlayState.h"

bool PlayState::onInit()
{
	_scene01 = new Scene(_graficos);
	_cameraObject = new GameObject(_graficos, 0, 0, 0, 0, 0, 0, 1, 1, 1);
	_zombie01 = new GameObject(_graficos, 600, 200, 0, 0, 0, 0, 1, 1, 1);
	_zombie02 = new GameObject(_graficos, 200, 200, 0, 0, 0, 0, 1, 1, 1);
	_sol = new GameObject(_graficos, 400, 500, 0, 0, 0, 0, 1, 1, 1);
	_piedra = new GameObject(_graficos, 800, 165, 0, 0, 0, 0, 1, 1, 1);
	_cubo = new GameObject(_graficos, 200, 400, 0, 0, 0, 0, 100, 100, 100);
	_objectEmpty = new GameObject(_graficos, 400, 500, 0, 0, 0, 0, 1, 1, 1);

	_camera = new Camera(_graficos, 800.0f, 600.0f);
	_sprite01 = new Sprite(_graficos, _textureManager, 75.0f, 150.0f, Square, 0.0f, L"Assets/Walk2.png", 2000.0f, 312.0f, 10);
	_sprite02 = new Sprite(_graficos, _textureManager, 75.0f, 150.0f, Square, 0.0f, L"Assets//Walk2.png", 2000.0f, 312.0f, 10);
	_sprite03 = new Sprite(_graficos, _textureManager, 200.0f, 200.0f, Square, 0.0f, L"Assets//Sun.png", 260.0f, 260.0f, 1);
	_sprite04 = new Sprite(_graficos, _textureManager, 75.0f, 100.0f, Square, 0.0f, L"Assets//Rock.png", 260.0f, 260.0f, 1);
	_mesh = new Mesh(_graficos, _textureManager, L"Assets//Estrella.png", "Assets//cube.obj");
	_mesh->LoadOBJ();

	_spriteRenderer01 = new SpriteRenderer(_sprite01);
	_spriteRenderer02 = new SpriteRenderer(_sprite02);
	_spriteRenderer03 = new SpriteRenderer(_sprite03);
	_spriteRenderer04 = new SpriteRenderer(_sprite04);
	_meshRenderer = new MeshRenderer(_frustum, _mesh);

	_cameraObject->AddChild(_camera);
	_zombie01->AddChild(_spriteRenderer01);
	_zombie02->AddChild(_spriteRenderer02);
	_sol->AddChild(_spriteRenderer03);
	//_lobo->AddChild(_zombie02);
	_piedra->AddChild(_spriteRenderer04);
	_cubo->AddChild(_meshRenderer);

	_scene01->AddChild(_cameraObject);
	_scene01->AddChild(_sol);
	_scene01->AddChild(_piedra);
	_scene01->AddChild(_cubo);
	_scene01->AddChild(_zombie01);
	_scene01->AddChild(_zombie02);


	_collisionManager->Register(_zombie01, 1);
	_collisionManager->Register(_zombie02, 2);
	_collisionManager->Register(_piedra, 2);
	_zombie01->_inamovible = false;
	_zombie02->_inamovible = false;
	_piedra->_inamovible = true;
	_sprite02->FlipX(true);

	return true;
}
void PlayState::onDraw() 
{
	_frustum->ConstructFrustum(1000.0f, _camera->GetMatrixProj(), _camera->GetMatrixView());

	if (_scene01)
		_scene01->Draw();
}
bool PlayState::onShutdown() 
{
	if(_camera)
		delete _camera;
	if (_sprite01)
		delete _sprite01;
	if (_sprite02)
		delete _sprite02;
	if (_sprite03)
		delete _sprite03;
	if (_mesh)
		delete _mesh;
	if (_zombie01)
		delete _zombie01;
	if (_zombie02)
		delete _zombie02;
	if (_sol)
		delete _sol;
	if (_cubo)
		delete _cubo;
	if (_spriteRenderer01)
		delete _spriteRenderer01;
	if (_spriteRenderer02)
		delete _spriteRenderer02;
	if (_spriteRenderer03)
		delete _spriteRenderer03;
	if (_meshRenderer)
		delete _meshRenderer;
	return true;
}
bool PlayState::onUpdate() 
{
	_contador++;
	
	if (accumTime > 0.1) // velocidad de animacion
	{ 
		accumTime -= 0.1;

		_sprite01->LaterFrame();
		_sprite02->LaterFrame();
	}
	if (_contador == 2)
	{
		//_camera->Pitch(1.0f * _timeMeter->GetDT()); // Roto en x la camara
		_contador = 0;
	}

	if (_input->keyPressing(DIK_RIGHTARROW))
	{
		//_camera->SumX(40.0 * _timeMeter->GetDT());   // Muevo en x la camara
		accumTime += _timeMeter->GetDT();
		_zombie01->transform.position->x += 80.0 * _timeMeter->GetDT();
		_sprite01->FlipX(true);
	}
	if (_input->keyPressing(DIK_LEFTARROW))
	{
		//_camera->SumX(-40.0 * _timeMeter->GetDT());   // Muevo en x la camara
		accumTime += _timeMeter->GetDT();
		_zombie01->transform.position->x -= 80.0 * _timeMeter->GetDT();
		_sprite01->FlipX(false);
	}
	_camera->SetPosicion(_zombie01->transform.position->x,_camera->_pos.y, _camera->_pos.z); // le asigno la posicion de la camara al player
	
	if (_zombie01->transform.position->x < -1000)
		_zombie01->transform.position->x = 600;

	_sol->transform.rotation->z += 10.0 * _timeMeter->GetDT();
	_cubo->transform.rotation->x += 10.0 *_timeMeter->GetDT();

	return true;
}