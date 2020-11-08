#pragma once

#include "FrameworkTypes.h"
#include "Indexer.h"

class Sprite
{
public:
    Sprite() = default;
    virtual ~Sprite() = default;

    void InitSprite(const AssetHandle& assetHandle);
    
    void SetIndexer(int w, int h, int xOff, int yOff);
    void SetSpriteIndex(int x, int y);
    void SetPosition(int x, int y);
    void SetSize(int size);
    void SetSize(int w, int h);

    const AssetHandle& GetAssetHandle() const;
    const Rect& GetSpriteRect() const;
    const Rect& GetDestRect() const;
private:
    AssetHandle m_AssetHandle;
    Rect m_SpriteRect;
    Rect m_DestRect;
    Indexer m_Indexer;
};