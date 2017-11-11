#include "Node.h"

void Node::AddChild(Node* child)
{
	childs->push_back(child);
}
void Node::RemoveChild()
{
	childs->pop_back();
}
Node::~Node()
{
	for (int i = 0; i < childs->size(); i++)
	{
		//delete (*childs)[i];
	}
}