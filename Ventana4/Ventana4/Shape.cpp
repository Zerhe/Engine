#include "Shape.h"

Shape::Shape(Graphics *graficos)
{
	_graficos = graficos;

	_vertices = new CUSTOMVERTEX[3];
	_vertices[0] = { 50.0f, 200.0f, 0.5f, D3DCOLOR_ARGB(255, 255, 0, 255), };
	_vertices[1] = { 360.0f, 500.0f, 0.5f, D3DCOLOR_ARGB(255, 255, 255, 0), };
	_vertices[2] = { 650.0f, 200.0f, 0.5f, D3DCOLOR_ARGB(255, 0, 255, 255), };

}
void Shape::Draw() 
{
	//Transform(_graficos);
	_graficos->BindTexture(NULL);
	_graficos->DrawShape(_vertices, 3);

}