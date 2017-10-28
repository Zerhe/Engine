#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(Sprite* sprite)
{
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