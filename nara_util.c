#include "nara_util.h"

#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void
initNara(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG|IMG_INIT_PNG|IMG_INIT_TIF|IMG_INIT_WEBP);
	// Mix_Init(MIX_INIT_FLAC|MIX_INIT_MOD|
	// 			MIX_INIT_MP3|MIX_INIT_OGG);
	TTF_Init();
}

void
exitNara(void)
{
	TTF_Quit();
	// Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

