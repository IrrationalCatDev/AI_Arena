#pragma once

#include <SDL_rect.h>

using AssetHandle = int;
using SurfaceHandle = int;
using Rect = SDL_Rect;

struct Color
{
    //color format as 0xRRGGBBAA
    Color(unsigned int color)
    {
        r = (0xff000000&color)>>24;
        g = (0xff0000&color)>>16;
        b = (0xff00&color)>>8;
        a = (0xff&color);
    }
    Color(int inr, int ing, int inb, int ina) : r(inr), g(ing), b(inb), a(ina){}
    int r,g,b,a;
};

namespace Colors
{
    extern const Color Red;
    extern const Color Green;
    extern const Color Blue;
    extern const Color Magenta;
    extern const Color Yellow;
    extern const Color Teal;
    extern const Color White;
    extern const Color Black;
}

enum class PrimitiveRenderMode
{
    eFill,
    eLine,
};


Rect MakeRect(int x, int y, int w, int h);
