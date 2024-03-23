#include "nara_util.h"
#include "nara_window.h"

Window
windowNew(char *t, uint32_t w, uint32_t h, bool r)
{
	Window wn;
	wn.width = w;
	wn.height = h;
	wn.resizable = r;

	wn.window = SDL_CreateWindow(t,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			w, h, (r? SDL_WINDOW_RESIZABLE : 0) | SDL_WINDOW_INPUT_FOCUS);

	wn.render = SDL_CreateRenderer(
			wn.window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);

	return wn;
}

bool
windowEvents(Window *wn, SDL_Event event)
{
	switch (event.type) {
	case SDL_QUIT:
		return false;
		break;
	case SDL_WINDOWEVENT: {
		if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
			wn->width  = event.window.data1;
			wn->height = event.window.data2;
		}
		break;
	}
	default: break;
	}
	return true;
}

void
windowFree(Window *wn)
{
	SDL_DestroyRenderer(wn->render);
	SDL_DestroyWindow(wn->window);
}
