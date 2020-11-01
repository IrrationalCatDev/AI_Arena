#pragma once

#include <SDL_render.h>
#include <String>
#include <stack>
#include <unordered_map>

#include "FrameworkTypes.h"

class Renderer
{
public:
    //do i even want this class? what's the benefit?
    Renderer();
    ~Renderer();

    bool Initialize();
    void Cleanup();

    void BeginDraw();
    void Present();

    AssetHandle LoadAsset(std::string fileName);
    void UnloadAsset(AssetHandle handle);

    void PushViewport(Rect viewport);
    void PopViewport();

    void RenderCopy(AssetHandle handle, Rect src, Rect dest);
    void RenderRect(Rect rect, Color color, PrimitiveRenderMode mode = PrimitiveRenderMode::eFill);

private:
    SDL_Window* m_pWindow = NULL;
    SDL_Renderer* m_pRenderer = NULL;
    SDL_Surface* m_pScreen = NULL;

    AssetHandle m_NextHandle = 0;
    AssetHandle m_MaxHandles = INT32_MAX;
    std::unordered_map<AssetHandle,SDL_Texture*> m_Textures;
    std::unordered_map<std::string,AssetHandle> m_LoadedTextures;
    std::stack<Rect> m_Viewports;
};