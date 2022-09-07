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

	// having this here kinda makes my life easier
	int _animLoop;
} Sprite;

typedef struct nara_sprite_range {
	int start;
	int end;
	int speed;

	// int _animLoop;
} SpriteRange;

Sprite spriteNew(char *path);
void spriteLoad(Sprite *spr, char *path);
void spriteAnimate(Sprite *spr, SpriteRange *range);
void spriteRender(Sprite *spr, SDL_Rect *dest);

