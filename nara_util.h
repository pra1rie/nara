#pragma once

#include <SDL2/SDL.h>

#define bool char
#define true 1
#define false 0

SDL_Surface *loadImage(char *path);
SDL_Texture *loadImageAsTexture(SDL_Renderer *rn, char *path);

void initNara(void);
void exitNara(void);

