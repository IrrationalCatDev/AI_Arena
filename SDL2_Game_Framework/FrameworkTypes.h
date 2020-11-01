#pragma once

#include <SDL_rect.h>

using AssetHandle = int;
using SurfaceHandle = int;
using Rect = SDL_Rect;
struct Color
{
    int r,g,b,a;
};

enum class PrimitiveRenderMode
{
    eFill,
    eLine,
};


Rect MakeRect(int x, int y, int w, int h);
