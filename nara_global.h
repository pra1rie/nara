#pragma once

#include "nara_util.h"
#include <SDL2/SDL.h>

// I'm unsure whether i keep a global window or not

typedef struct nara_global {
	bool isRunning;
	uint32_t width;
	uint32_t height;
	bool resizable;
	SDL_Window *window;
	SDL_Renderer *render;
} Global;

extern Global global;

