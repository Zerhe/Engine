#include "Scene.h"

Scene::Scene(Graphics* graficos)
{
	_graficos = graficos;
}
void Scene::Draw()
{
	_graficos->LoadIdentity();
	for (int i = 0; i < childs->size(); i++)
	{
		(*childs)[i]->Draw();
	}
}