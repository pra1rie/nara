#pragma once

#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct nara_sprite {
	SDL_Texture *img;
	SDL_Rect rect;
	SDL_RendererFlip flip;
	int angle;
	int width;
	int height;
	// individual subsprites
	int tileWidth;
	int tileHeight;

	// having this here makes my life easier
	int frame;
} Sprite;

typedef struct nara_sprite_range {
	int start;
	int end;
	int speed;
	int offset;
} SpriteRange;

Sprite spritePlain(SDL_Color col, int w, int h);
Sprite spriteNew(char *path, int w, int h);
void spriteLoad(Sprite *spr, char *path);
void spriteAnimate(Sprite *spr, SpriteRange *range);
void spriteRender(Sprite *spr, SDL_Rect *dest);

