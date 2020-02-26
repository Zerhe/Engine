#include "GameObject.h"
GameObject::GameObject(Graphics* graficos)
{
	_graficos = graficos;
}
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
void GameObject::Draw()
{
	_graficos->matrices.push(_graficos->GetMatrixWorld());
	transform.LoadTransform(_graficos);

	for (int i = 0; i < childs->size(); i++)
	{
		(*childs)[i]->Draw();
	}
	_graficos->SetMatrixWorld(_graficos->matrices.top());
	_graficos->matrices.pop();
}
void GameObject::DrawTileMap(int tileSize, int height, int weight, int posX)
{
	_graficos->matrices.push(_graficos->GetMatrixWorld());
	transform.LoadTransform(_graficos);
	int k = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			(*childs)[k]->Draw();
			k++;
			//transform.position->x += tileSize;
			//transform.LoadTransform(_graficos);
		}
		//transform.position->y -= tileSize;
		//transform.position->x = posX;
		//transform.LoadTransform(_graficos);
	}
	_graficos->SetMatrixWorld(_graficos->matrices.top());
	_graficos->matrices.pop();
}
Node* GameObject::GetComponent(string typeSearch)
{
	for (int i = 0; i < childs->size(); i++)
	{
		string type = (*childs)[i]->type;
		if (type == typeSearch)
		{
			return (*childs)[i];
		}
	}
	return NULL;
}
void GameObject::OnCollision(GameObject* entidad)
{
	if (_inamovible == false)
	{
		// hacer algo cuando coliciona 
	}
}
