#pragma once

#include <SDL2/SDL.h>

typedef enum nara_bool {
	false = 0,
	true = 1
} bool;

SDL_Texture *loadImage(char *path);
int getKey(SDL_Scancode key);

void init(void);
void quit(void);

