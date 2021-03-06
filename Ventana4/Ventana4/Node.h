#ifndef NODE_H
#define NODE_H
#include "Api.h"
#include "Graphics.h"
#include <vector>

using namespace std;

class VENTANA4_API Node
{
protected:
	vector <Node*>* childs = new vector <Node*>();
public:
	string type = "null";
	~Node();
	virtual void AddChild(Node* child);
	virtual void RemoveChild();
	virtual void Draw() {};
};
#endif
