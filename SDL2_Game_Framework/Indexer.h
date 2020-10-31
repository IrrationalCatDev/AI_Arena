#pragma once

#include "FrameworkTypes.h"

class Indexer
{
public:
    Indexer(int width, int height, int xOffset, int yOffset);
    ~Indexer()=default;

    Rect GetRectAtIndex(int xCoord, int yCoord)
    {
        Rect retVal;
        retVal.w = m_RectWidth;
        retVal.h = m_RectHeight;
        retVal.x = (xCoord*m_RectWidth+xCoord*m_xOffset);
        retVal.y = (yCoord*m_RectWidth+yCoord*m_xOffset);
    }
private:
    int m_RectWidth;
    int m_RectHeight;
    int m_xOffset;
    int m_yOffset;
};