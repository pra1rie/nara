#pragma once

#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct nara_font {
	TTF_Font *font;
	uint32_t size;
	SDL_Rect rect;
	SDL_Color color;

	SDL_Texture *_texture;
	SDL_Surface *_surface;
} Font;

Font fontNew(char *path, uint32_t size, SDL_Color color);
void fontFree(Font *font);

void fontWrite(Font *font, char *text, int x, int y);
void fontWriteCenter(Font *font, char *text, int x, int y);
void fontWriteRight(Font *font, char *text, int x, int y);

static void fontRenderTexture(Font *font);
static void fontRenderSurface(Font *font, char *text);

