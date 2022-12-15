#pragma once

#include "nara_util.h"
#include "nara_window.h"

typedef struct nara_global {
	bool isRunning;
	Window window;
} Global;

extern Global global;

