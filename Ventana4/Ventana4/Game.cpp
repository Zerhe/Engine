#include "Game.h"


bool Game::startup(HINSTANCE hInstance) {
	_ventanita = new Ventana();
	_graficos = new Graphics();
	_textureManager = new TextureManager();
	_timeMeter = new TimeMeter();
	_collisionManager = new CollisionManager();
	_input = new Input();
	int _width = 800;
	int _height = 600;

	// Registro la clase
	_ventanita->registerClass(hInstance);

	// Creo la ventana
	_ventanita->createWindow(hInstance, L"Aquí esta el titulo", _width, _height);

	_graficos->Initialize(_ventanita->getHwnd(), _width, _height);
	_graficos->SetupScene();
	_timeMeter->FirstMeasure();
	//_input->Initialize(hInstance, _ventanita->getHwnd());

	return onInit();
}
void Game::loop() {
	MSG	msg;			// Estructura de mensajes
	bool	done = false;	// Si debo interrumpir el loop
							// Loop principal
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				done = true;			// ALT-F4
		}
		
		onUpdate();
		_collisionManager->CheckCollision();
		_graficos->Clear();
		_graficos->Begin();
		_frustum->ConstructFrustum(1000.0f, _graficos->GetMatrixProjection(), _graficos->GetMatrixView());
		onDraw();
		_graficos->End();
		_graficos->Present();
		done = !onUpdate();

		_timeMeter->Measure();
	}
}
bool Game::shutdown() {

	if (_ventanita)
		delete _ventanita;
	if (_graficos)
		delete _graficos;
	if (_textureManager)
		delete _textureManager;
	if (_timeMeter)
		delete _timeMeter;
	if (_collisionManager)
		delete _collisionManager;

	return onShutdown();
}
