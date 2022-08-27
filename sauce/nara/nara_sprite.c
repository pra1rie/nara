#include "nara/nara_sprite.h"
#include "nara/nara_util.h"
#include "nara/nara_global.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


Sprite
spriteNew(char *path)
{
	Sprite spr;
	spriteLoad(&spr, path);
	spr.rect = (SDL_Rect) {0, 0, global.tileSize, global.tileSize};
	spr.flip = SDL_FLIP_NONE;
	spr.angle = 0;
	return spr;
}

void
spriteLoad(Sprite *spr, char *path)
{
	spr->img = loadImage(path);
	SDL_QueryTexture(spr->img, NULL, NULL, &spr->width, &spr->height);
	spr->_animLoop = -1;
}

void
spriteAnimate(Sprite *spr, SpriteRange *range)
{
	// interrupt other animation, kinda stupid but it'll work
	if (spr->rect.x > range->end * global.tileSize ||
			spr->rect.x < range->start * global.tileSize)
		spr->rect.x = range->end * global.tileSize;
	// some delay between frames
	if (spr->_animLoop > -1) ++spr->_animLoop;
	if (spr->_animLoop > range->speed) spr->_animLoop = -1;

	// move sprite's rectangle inside range to animate
	if (spr->_animLoop == -1) {
		if (spr->rect.x < range->end * global.tileSize)
			spr->rect.x += global.tileSize;
		else spr->rect.x = range->start * global.tileSize;
		spr->_animLoop = 0;
	}
}

void
spriteRender(Sprite *spr, SDL_Rect *dest)
{
	SDL_RenderCopyEx(global.window.render,
			spr->img, &spr->rect, dest, spr->angle, NULL, spr->flip);
}

