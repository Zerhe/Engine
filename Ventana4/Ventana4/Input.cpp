#include "Input.h"

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
	for (int i = 0; i < 256; i++)
	{
		prevKeys[i] = actualKeys[i];
	}
	keyDev->GetDeviceState(sizeof(actualKeys), &actualKeys);
}

bool Input::keyJustPressed(int key)
{
	if (!prevKeys[key] && actualKeys[key])
		return true;
	return false;
}

bool Input::keyJustPressed(vector<int>* keys)
{
	for (int i = 0; i < keys->max_size(); i++)
	{
		if (!prevKeys[keys->at(i)] && actualKeys[keys->at(i)])
			return true;
	}
	return false;
}

bool Input::keyPressing(int key)
{
	if (prevKeys[key] && actualKeys[key])
		return true;
	return false;
}

bool Input::keyPressing(vector<int>* keys)
{
	for (int i = 0; i < keys->max_size(); i++)
	{
		if (actualKeys[keys->at(i)])
			return true;
	}
	return false;
}

bool Input::keyJustReleased(int key)
{
	if (prevKeys[key] && !actualKeys[key])
		return true;
	return false;
}

bool Input::keyJustReleased(vector<int>* keys)
{
	for (int i = 0; i < keys->max_size(); i++)
	{
		if (actualKeys[keys->at(i)])
			return true;
	}
	return false;
}