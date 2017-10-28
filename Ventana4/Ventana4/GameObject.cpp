#include "GameObject.h"

GameObject::GameObject(Graphics* graficos,
	float posX, float posY, float posZ,
	float rotX, float rotY, float rotZ,
	float scaX, float scaY, float scaZ)
{
	transform.SetPosition(posX, posY, posZ);
	transform.SetRotation(rotX, rotY, rotZ);
	transform.SetScale(scaX, scaY, scaZ);
	_graficos = graficos;
}
GameObject::~GameObject()
{
	for (int i = 0; i < childs->size(); i++)
	{
		//delete (*childs)[i];
	}
}
void GameObject::Draw()
{
	transform.LoadTransform(_graficos);

	for (int i = 0; i < childs->size(); i++)
	{
		(*childs)[i]->Draw();
	}
}