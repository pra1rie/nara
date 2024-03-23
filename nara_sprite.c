#include "nara_sprite.h"
#include "nara_util.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite
spritePlain(int col, int w, int h)
{
	Sprite spr;
	spr.rect = (SDL_Rect) {0, 0, w, h};

	spr.img = SDL_CreateRGBSurface(
			0, w, h, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);

	SDL_FillRect(spr.img, NULL, col);

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
spriteFree(Sprite *spr)
{
	SDL_FreeSurface(spr->img);
}

void
spriteLoad(Sprite *spr, char *path)
{
	spr->img = loadImage(path);
	spr->width = spr->img->w;
	spr->height = spr->img->h;
	/* SDL_QueryTexture(spr->img, NULL, NULL, &spr->width, &spr->height); */
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
spriteRender(Sprite *spr, SDL_Renderer *dst, SDL_Rect *dstrect)
{
	SDL_Texture *tex = SDL_CreateTextureFromSurface(dst, spr->img);
	SDL_RenderCopyEx(
			dst, tex, &spr->rect,
			dstrect, spr->angle, NULL, spr->flip);
	SDL_DestroyTexture(tex);
}

