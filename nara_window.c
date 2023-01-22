#include "nara_window.h"
#include "nara_util.h"
#include "nara_global.h"

#include <stdlib.h>

Window*
windowNew(char *t, uint32_t w, uint32_t h, bool r)
{
	Window *wn = malloc(sizeof(Window));
	wn->width = w;
	wn->height = h;
	wn->resizable = r;
	
	wn->window = SDL_CreateWindow(t,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			w, h, (r? SDL_WINDOW_RESIZABLE : 0) | SDL_WINDOW_INPUT_FOCUS);

	wn->render = SDL_CreateRenderer(wn->window, -1, SDL_RENDERER_ACCELERATED);
	return wn;
}

void
windowFree(Window *wn)
{
	SDL_DestroyRenderer(wn->render);
	SDL_DestroyWindow(wn->window);
	free(wn);
}

