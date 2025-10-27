#pragma once

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct nara_window {
	uint32_t width;
	uint32_t height;
	bool resizable;
	SDL_Window *window;
	SDL_Renderer *render;
} Window;


Window windowNew(char *t, uint32_t w, uint32_t h, bool r);
void windowFree(Window *wn);

bool windowEvents(Window *wn, SDL_Event event);
