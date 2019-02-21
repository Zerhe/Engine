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
Node* GameObject::GetComponent(const char* typeSearch)
{
	for (int i = 0; i < childs->size(); i++)
	{
		const char* type = (*childs)[i]->type;
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
