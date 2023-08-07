#pragma once

#include <SDL2/SDL.h>

typedef enum nara_bool {
	false = 0,
	true = 1
} bool;

SDL_Texture *loadImage(char *path);
int getKey(SDL_Scancode key);

// handles SDL_QUIT and SDL_WINDOWRESIZED
void genericEvents(SDL_Event event);

void initNara(char *t, uint32_t w, uint32_t h, bool r);
void exitNara(void);

