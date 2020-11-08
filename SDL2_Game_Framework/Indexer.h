#pragma once

#include "FrameworkTypes.h"

class Indexer
{
public:
    Indexer() = default;
    ~Indexer() = default;
    void SetData(int w, int h, int xOff, int yOff);
    Rect GetRectAtIndex(int xCoord, int yCoord);

private:
    int m_RectWidth;
    int m_RectHeight;
    int m_xOffset;
    int m_yOffset;
};