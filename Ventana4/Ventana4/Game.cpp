#include "Game.h"


bool Game::startup(HINSTANCE hInstance) {
	_ventanita = new Ventana();
	_graficos = new Graphics();
	int _width = 800;
	int _height = 600;

	// Registro la clase
	_ventanita->registerClass(hInstance);

	// Creo la ventana
	_ventanita->createWindow(hInstance, L"Aquí esta el titulo", _width, _height);

	_graficos->Initialize(_ventanita->getHwnd(), _width, _height);
	_graficos->SetupScene();
	//graficos->VertexBuffer();
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
		else
		{
			onUpdate();
			_graficos->Clear();
			_graficos->Begin();
			onDraw();
			_graficos->End();
			_graficos->Present();
			done = !onUpdate();
		}
	}
}
bool Game::shutdown() {

	if (_ventanita)
		delete _ventanita;
	if (_graficos)
		delete _graficos;

	return onShutdown();
}
/*void Game::onDraw() {
	graficos->Draw();
}*/
