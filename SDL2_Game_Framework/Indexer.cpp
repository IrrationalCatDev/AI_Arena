#include "Indexer.h"


void Indexer::SetData(int w, int h, int xOff, int yOff)
{
    m_RectWidth = w;
    m_RectHeight = h;
    m_xOffset = xOff;
    m_yOffset = yOff;
}

Rect Indexer::GetRectAtIndex(int xCoord, int yCoord)
{
    Rect retVal;
    retVal.w = m_RectWidth;
    retVal.h = m_RectHeight;
    retVal.x = (xCoord*m_RectWidth+xCoord*m_xOffset);
    retVal.y = (yCoord*m_RectWidth+yCoord*m_xOffset);
    return retVal;
}
