#pragma once

#include <SDL2/SDL.h>

typedef enum nara_bool {
	false = 0,
	true = 1
} bool;

SDL_Surface *loadImage(char *path);
SDL_Texture *loadImageAsTexture(SDL_Renderer *rn, char *path);

void initNara(void);
void exitNara(void);

