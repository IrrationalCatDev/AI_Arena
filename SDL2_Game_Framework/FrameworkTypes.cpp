#include "FrameworkTypes.h"

namespace Colors
{
    const Color Red = {0xFF,0x00,0x00,0xFF};
    const Color Green = {0x00,0xFF,0x00,0xFF};
    const Color Blue = {0x00,0x00,0xFF,0xFF};
    const Color Magenta = {0xFF,0x00,0xFF,0xFF};
    const Color Yellow = {0xFF,0xFF,0x00,0xFF};
    const Color Teal = {0x00,0xFF,0xFF,0xFF};
    const Color White = {0xFF,0xFF,0xFF,0xFF};
    const Color Black = {0x00,0x00,0x00,0xFF};
}

Rect MakeRect(int x, int y, int w, int h)
{
    Rect r{x,y,w,h};
    return r;
}
