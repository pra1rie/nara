#include "nara_font.h"
#include "nara_window.h"

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

void
fontWrite(Font *font, SDL_Renderer *dest, char *text, int x, int y)
{
	if (strlen(text) == 0) return;
	SDL_Surface *srf = TTF_RenderUTF8_Blended(font->font, text, font->color);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(dest, srf);
	SDL_Rect rect = {x, y, srf->w, srf->h};
	SDL_RenderCopy(dest, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(srf);
}

void
fontWriteCenter(Font *font, SDL_Renderer *dest, char *text, int x, int y)
{
	if (strlen(text) == 0) return;
	SDL_Surface *srf = TTF_RenderUTF8_Blended(font->font, text, font->color);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(dest, srf);
	SDL_Rect rect = {x - (srf->w/2), y - (srf->h/2), srf->w, srf->h};
	SDL_RenderCopy(dest, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(srf);
}

void
fontWriteRight(Font *font, SDL_Renderer *dest, char *text, int x, int y)
{
	if (strlen(text) == 0) return;
	SDL_Surface *srf = TTF_RenderUTF8_Blended(font->font, text, font->color);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(dest, srf);
	SDL_Rect rect = {x - srf->w, y, srf->w, srf->h};
	SDL_RenderCopy(dest, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(srf);
}

