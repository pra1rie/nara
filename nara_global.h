#pragma once

#include "nara_util.h"
#include "nara_window.h"

// I'm unsure whether i keep a global window or not

typedef struct nara_global {
	bool isRunning;
	Window *window;
} Global;

extern Global global;

