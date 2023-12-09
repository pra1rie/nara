#include "nara_font.h"
#include "nara_global.h"

#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

Font
fontNew(char *path, uint32_t size, SDL_Color color)
{
	Font font;
	font.font = TTF_OpenFont(path, size);
	font.size = size;
	font.rect = (SDL_Rect) {0, 0, size, size};
	font.color = color;
	return font;
}

void
fontFree(Font *font)
{
	if (font->_texture != NULL) {
		SDL_DestroyTexture(font->_texture);
		font->_texture = NULL;
	}
	if (font->_surface != NULL) {
		SDL_FreeSurface(font->_surface);
		font->_surface = NULL;
	}
	TTF_CloseFont(font->font);
}

void
fontWrite(Font *font, char *text, int x, int y)
{
	if (strlen(text) == 0) return;
	fontRenderSurface(font, text);

	font->rect = (SDL_Rect) {x, y, font->_surface->w, font->_surface->h};

	fontRenderTexture(font);
}

void
fontWriteCenter(Font *font, char *text, int x, int y)
{
	if (strlen(text) == 0) return;
	fontRenderSurface(font, text);

	font->rect = (SDL_Rect) {
		x - (font->_surface->w/2),
		y - (font->_surface->h/2),
		font->_surface->w,
		font->_surface->h
	};

	fontRenderTexture(font);
}

void
fontWriteRight(Font *font, char *text, int x, int y)
{
	if (strlen(text) == 0) return;
	fontRenderSurface(font, text);

	font->rect = (SDL_Rect) {
		x - (font->_surface->w), y,
		font->_surface->w, font->_surface->h
	};

	fontRenderTexture(font);
}

static void
fontRenderTexture(Font *font)
{
	SDL_RenderCopy(global.render, font->_texture, NULL, &font->rect);
	SDL_DestroyTexture(font->_texture);
	SDL_FreeSurface(font->_surface);
	font->_texture = NULL;
	font->_surface = NULL;
}

static void
fontRenderSurface(Font *font, char *text)
{
	SDL_Color color;
	SDL_GetRenderDrawColor(global.render,
			&color.r, &color.g, &color.b, &color.a);

	font->_surface = TTF_RenderText_Shaded(font->font, text, font->color, color);
	font->_texture = SDL_CreateTextureFromSurface(
				global.render, font->_surface);
}

