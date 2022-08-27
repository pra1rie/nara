#include "nara/nara_util.h"
#include "nara/nara_global.h"

#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>


SDL_Texture*
loadImage(char *path)
{
	SDL_Surface *s = IMG_Load(path);
	SDL_Texture *t = SDL_CreateTextureFromSurface(global.window.render, s);
	SDL_FreeSurface(s);
	return t;
}

int
getKey(SDL_Scancode key)
{
	const uint8_t* state = SDL_GetKeyboardState(NULL);
	return state[key];
}

void
init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	// Mix_Init(MIX_INIT_FLAC|MIX_INIT_MOD|
	// 			MIX_INIT_MP3|MIX_INIT_OGG);
	TTF_Init();

	// global defaults
	global.tileSize = 32;
	global.isRunning = true;
}

void
quit(void)
{
	TTF_Quit();
	// Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

