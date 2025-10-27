#include "nara_font.h"

#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Font
fontNew(char *path, uint32_t size, SDL_Color color)
{
	Font font;
	font.font = TTF_OpenFont(path, size);
	font.size = size;
	font.color = color;
	return font;
}

void
fontFree(Font *font)
{
	TTF_CloseFont(font->font);
}

#define __NARA_FONT_WRITE(X, Y, W, H) \
	if (strlen(text) == 0) return; \
	SDL_Surface *srf = TTF_RenderUTF8_Blended(font->font, text, font->color); \
	SDL_Texture *tex = SDL_CreateTextureFromSurface(dest, srf); \
	SDL_RenderCopy(dest, tex, NULL, &((SDL_Rect) {X, Y, W, H})); \
	SDL_DestroyTexture(tex); \
	SDL_FreeSurface(srf); \

void
fontWrite(Font *font, SDL_Renderer *dest, char *text, int x, int y)
{
	__NARA_FONT_WRITE(x, y, srf->w, srf->h);
}

void
fontWriteCenter(Font *font, SDL_Renderer *dest, char *text, int x, int y)
{
	__NARA_FONT_WRITE(x - (srf->w/2), y - (srf->h/2), srf->w, srf->h);
}

void
fontWriteRight(Font *font, SDL_Renderer *dest, char *text, int x, int y)
{
	__NARA_FONT_WRITE(x - srf->w, y, srf->w, srf->h);
}

#undef __NARA_FONT_WRITE
