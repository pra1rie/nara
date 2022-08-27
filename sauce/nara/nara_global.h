#pragma once

#include "nara/nara_util.h"
#include "nara/nara_window.h"

typedef struct nara_global {
	int tileSize;
	bool isRunning;
	Window window;
} Global;

extern Global global;

