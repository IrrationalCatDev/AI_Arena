#pragma once

#include <SDL_rect.h>

using AssetHandle = int;
using SurfaceHandle = int;
using Rect = SDL_Rect;

Rect MakeRect(int x, int y, int w, int h);
