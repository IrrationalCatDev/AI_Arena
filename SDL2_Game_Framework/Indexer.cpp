#include "Indexer.h"


Indexer::Indexer(int width, int height, int xOffset, int yOffset)
    : m_RectWidth(width)
    , m_RectHeight(height)
    , m_xOffset(xOffset)
    , m_yOffset(yOffset)
{

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
