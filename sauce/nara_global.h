#pragma once

#include "nara_util.h"
#include "nara_window.h"

typedef struct nara_global {
	int tileWidth, tileHeight;
	bool isRunning;
	Window window;
} Global;

extern Global global;

