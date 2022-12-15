#include "nara_sprite.h"
#include "nara_util.h"
#include "nara_global.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite
spritePlain(SDL_Color col, int w, int h)
{
	Sprite spr;
	spr.rect = (SDL_Rect) {0, 0, w, h};

	spr.img = SDL_CreateTexture(global.window.render,
			SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);

	SDL_SetRenderTarget(global.window.render, spr.img);
	SDL_SetRenderDrawColor(global.window.render,
			col.r, col.g, col.b, col.a);
	SDL_RenderClear(global.window.render);
	SDL_SetRenderTarget(global.window.render, NULL);

	spr.width = spr.tileWidth = w;
	spr.height = spr.tileHeight = h;
	spr.frame = -1;
	spr.flip = SDL_FLIP_NONE;
	spr.angle = 0;
	return spr;
}

Sprite
spriteNew(char *path, int w, int h)
{
	Sprite spr;
	spriteLoad(&spr, path);
	spr.rect = (SDL_Rect) {0, 0, w, h};
	spr.tileWidth = w;
	spr.tileHeight = h;
	spr.flip = SDL_FLIP_NONE;
	spr.angle = 0;
	return spr;
}

void
spriteLoad(Sprite *spr, char *path)
{
	spr->img = loadImage(path);
	SDL_QueryTexture(spr->img, NULL, NULL, &spr->width, &spr->height);
	spr->frame = -1;
}

void
spriteAnimate(Sprite *spr, SpriteRange *range)
{
	// interrupt other animation, kinda stupid but it'll work
	if (spr->rect.x > range->end * spr->tileWidth ||
			spr->rect.x < range->start * spr->tileWidth)
		spr->rect.x = range->end * spr->tileWidth;
	// some delay between frames
	if (spr->frame > -1) ++spr->frame;
	if (spr->frame > range->speed) spr->frame = -1;

	// move sprite's rectangle inside range to animate
	if (spr->frame == -1) {
		if (spr->rect.x < range->end * spr->tileWidth)
			spr->rect.x += spr->tileWidth;
		else
			spr->rect.x = range->start * spr->tileWidth;
		spr->rect.y = range->offset * spr->tileHeight;
		spr->frame = 0;
	}
}

void
spriteRender(Sprite *spr, SDL_Rect *dest)
{
	SDL_RenderCopyEx(global.window.render,
			spr->img, &spr->rect, dest, spr->angle, NULL, spr->flip);
}

