#include "Input.h"

Input * Input::Instance = new Input();

Input::~Input()
{
	dip->Release();
	keyDev->Unacquire(); //Libera memoria 
	keyDev->Release();
}
void Input::Initialize(HINSTANCE hInstance, HWND hWnd)
{
	DirectInput8Create(hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&dip,
		NULL);

	dip->CreateDevice(GUID_SysKeyboard, &keyDev, NULL);
	keyDev->SetDataFormat(&c_dfDIKeyboard);
	keyDev->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	keyDev->Acquire();
}
void Input::Update()
{
	for (int i = 0; i < 256; i++) //Actualiza el estado del teclado del anterior frame en prevKeys
	{
		prevKeys[i] = actualKeys[i];
	}
	keyDev->GetDeviceState(sizeof(actualKeys), &actualKeys);	//Actualiza el estado del teclado en keys
}
bool Input::keyJustPressed(unsigned short int key)
{
	if (!prevKeys[key] && actualKeys[key])
		return true;
	return false;
}

bool Input::keyJustPressed(vector<unsigned short int>* keys)
{
	for (int i = 0; i < keys->max_size(); i++)
	{
		if (!prevKeys[keys->at(i)] && actualKeys[keys->at(i)])
			return true;
	}
	return false;
}

bool Input::keyPressing(unsigned short int key)
{
	if (prevKeys[key] && actualKeys[key])
		return true;
	return false;
}

bool Input::keyPressing(vector<unsigned short int>* keys)
{
	for (int i = 0; i < keys->max_size(); i++)
	{
		if (actualKeys[keys->at(i)])
			return true;
	}
	return false;
}

bool Input::keyJustReleased(unsigned short int key)
{
	if (prevKeys[key] && !actualKeys[key])
		return true;
	return false;
}

bool Input::keyJustReleased(vector<unsigned short int>* keys)
{
	for (int i = 0; i < keys->max_size(); i++)
	{
		if (actualKeys[keys->at(i)])
			return true;
	}
	return false;
}

void Input::AddKeyMap(string codigo, unsigned short int key)
{
	if (keyMap[codigo] == NULL)
		keyMap[codigo] = new vector<int>;
	keyMap[codigo]->push_back(key);
}

vector<int>* Input::GetKeyMap(string codigo)
{
	return keyMap[codigo];
}

void Input::Release()
{
	Input::~Input();
}
