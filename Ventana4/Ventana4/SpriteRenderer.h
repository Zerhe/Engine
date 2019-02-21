#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "Api.h"
#include "Component.h"
#include "Sprite.h"

using namespace std;

class VENTANA4_API SpriteRenderer : public Component
{
	Sprite* _sprite;
public:
	SpriteRenderer();
	SpriteRenderer(Sprite* mesh);
	void Draw();
	void SetSprite(Sprite* mesh);
	Sprite* GetSprite();
};
#endif
