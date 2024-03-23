#pragma once

#include <stdint.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct nara_font {
	TTF_Font *font;
	uint32_t size;
	SDL_Color color;
} Font;

Font fontNew(char *path, uint32_t size, SDL_Color color);
void fontFree(Font *font);

void fontWrite(Font *font, SDL_Renderer *dest, char *text, int x, int y);
void fontWriteCenter(Font *font, SDL_Renderer *dest, char *text, int x, int y);
void fontWriteRight(Font *font, SDL_Renderer *dest, char *text, int x, int y);

