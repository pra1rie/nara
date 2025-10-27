#include "nara_sprite.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite
spritePlain(SDL_Renderer *rnd, SDL_Color col, int w, int h)
{
	Sprite spr;
	spr.rect = (SDL_Rect) {0, 0, w, h};

	spr.img = SDL_CreateTexture(rnd, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
	// kinda roundabout but it should do
	SDL_Texture *prev = SDL_GetRenderTarget(rnd);
	SDL_SetRenderTarget(rnd, spr.img);
	SDL_SetRenderDrawColor(rnd, col.r, col.g, col.b, col.a);
	SDL_RenderClear(rnd);
	SDL_SetRenderTarget(rnd, prev);

	spr.width = spr.tileWidth = w;
	spr.height = spr.tileHeight = h;
	spr._frame = -1;
	spr.flip = SDL_FLIP_NONE;
	spr.angle = 0;
	return spr;
}

Sprite
spriteNew(SDL_Renderer *rnd, char *path, int w, int h)
{
	Sprite spr;
	spriteLoad(&spr, rnd, path);
	spr.rect = (SDL_Rect) {0, 0, w, h};
	spr.tileWidth = w;
	spr.tileHeight = h;
	spr.flip = SDL_FLIP_NONE;
	spr.angle = 0;
	return spr;
}

void
spriteFree(Sprite *spr)
{
	SDL_DestroyTexture(spr->img);
}

void
spriteLoad(Sprite *spr, SDL_Renderer *rnd, char *path)
{
	spr->img = IMG_LoadTexture(rnd, path);
	SDL_QueryTexture(spr->img, NULL, NULL, &spr->width, &spr->height);
	spr->_frame = -1;
}

void
spriteAnimate(Sprite *spr, SpriteRange *range)
{
	// interrupt other animation, kinda stupid but it'll work
	if (spr->rect.x > range->end * spr->tileWidth ||
			spr->rect.x < range->start * spr->tileWidth)
		spr->rect.x = range->end * spr->tileWidth;
	// some delay between frames
	if (spr->_frame > -1) ++spr->_frame;
	if (spr->_frame > range->speed) spr->_frame = -1;

	// move sprite's rectangle inside range to animate
	if (spr->_frame == -1) {
		if (spr->rect.x < range->end * spr->tileWidth)
			spr->rect.x += spr->tileWidth;
		else
			spr->rect.x = range->start * spr->tileWidth;
		spr->rect.y = range->offset * spr->tileHeight;
		spr->_frame = 0;
	}
}

void
spriteRender(Sprite *spr, SDL_Renderer *dst, SDL_Rect *dstrect)
{
	SDL_RenderCopyEx(dst, spr->img, &spr->rect,
			dstrect, spr->angle, NULL, spr->flip);
}

