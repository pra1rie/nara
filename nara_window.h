#pragma once

#include "nara_util.h"
#include <SDL2/SDL.h>

typedef struct nara_window {
	uint32_t width;
	uint32_t height;
	bool resizable;
	SDL_Window *window;
	SDL_Renderer *render;
} Window;

// Why the fuck did i use this shitty ass naming convention
// fucking hell

// handles SDL_QUIT and SDL_WINDOWRESIZED
// returns 'false' on SDL_QUIT, because i just felt like it
bool windowEvents(Window *wn, SDL_Event event);

Window windowNew(char *t, uint32_t w, uint32_t h, bool r);
void windowFree(Window *wn);

