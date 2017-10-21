#include "GameObject.h"

GameObject::GameObject(Graphics* graficos)
{
	_graficos = graficos;
}
void GameObject::Draw()
{
	transform.LoadTransform(_graficos);

	for (int i = 0; i < childs->size(); i++)
	{
		(*childs)[i]->Draw();
	}
}