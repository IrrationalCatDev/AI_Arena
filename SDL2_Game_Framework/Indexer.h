#pragma once

#include "FrameworkTypes.h"

class Indexer
{
public:
    Indexer(int width, int height, int xOffset, int yOffset);
    ~Indexer()=default;

    Rect GetRectAtIndex(int xCoord, int yCoord);

private:
    int m_RectWidth;
    int m_RectHeight;
    int m_xOffset;
    int m_yOffset;
};