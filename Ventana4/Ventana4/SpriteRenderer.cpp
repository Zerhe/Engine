#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
	type = "SpriteRenderer";
}
SpriteRenderer::SpriteRenderer(Sprite* sprite)
{
	type = "SpriteRenderer";
	_sprite = sprite;
}
void SpriteRenderer::Draw()
{
	_sprite->Draw();
}
void SpriteRenderer::SetSprite(Sprite* sprite)
{
	_sprite = sprite;
}
Sprite* SpriteRenderer::GetSprite()
{
	return _sprite;
}