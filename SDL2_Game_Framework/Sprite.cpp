#include "Sprite.h"


void Sprite::InitSprite(const AssetHandle& assetHandle)
{
    //seems like we should be doing more here. I guess for now this is fine.
    m_AssetHandle = assetHandle;
}

void Sprite::SetPosition(int x, int y)
{
    m_DestRect.x = x;
    m_DestRect.y = y;
}

void Sprite::SetIndexer(int w, int h, int xOff, int yOff)
{
    m_Indexer.SetData(w,h,xOff,yOff);
}

void Sprite::SetSpriteIndex(int x, int y)
{
    m_SpriteRect = m_Indexer.GetRectAtIndex(x,y);
}

void Sprite::SetSize(int size)
{
    m_DestRect.w = m_DestRect.h = size;
}

void Sprite::SetSize(int w, int h)
{
    m_DestRect.w = w;
    m_DestRect.h = h;
}

const AssetHandle& Sprite::GetAssetHandle() const
{
    return m_AssetHandle;
}

const Rect& Sprite::GetSpriteRect() const
{
    return m_SpriteRect;
}

const Rect& Sprite::GetDestRect() const
{
    return m_DestRect;
}
