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
	int _frame;
} Sprite;

typedef struct nara_sprite_range {
	int start;
	int end;
	int speed;
	int offset;
} SpriteRange;

Sprite spritePlain(SDL_Renderer *rnd, SDL_Color col, int w, int h);
Sprite spriteNew(SDL_Renderer *rnd, char *path, int w, int h);
void spriteFree(Sprite *spr);
void spriteLoad(Sprite *spr, SDL_Renderer *rnd, char *path);
void spriteAnimate(Sprite *spr, SpriteRange *range);
void spriteRender(Sprite *spr, SDL_Renderer *dst, SDL_Rect *dstrect);
