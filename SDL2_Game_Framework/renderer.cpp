#include "renderer.h"
#include <SDL_assert.h>
#include <SDL_Image.h>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
    //just in case we didn't go through the proper channels...
    Cleanup();
}

void Renderer::Cleanup()
{
    //clean up our SDL stuff
    for (auto& asset : m_Surfaces)
    {
        SDL_DestroyTexture(asset.second);
    }
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    
}

void Renderer::UnloadAsset(AssetHandle handle)
{
    auto& asset = m_Surfaces[handle];
    SDL_DestroyTexture(asset);
    asset = nullptr;
}

bool Renderer::Initialize()
{
    m_pWindow = SDL_CreateWindow("AI_Arena",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_OPENGL);
    if(m_pWindow == nullptr)
    {
        SDL_assert(false);
        return false;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
    if(m_pRenderer == nullptr)
    {
        SDL_assert(false);
        return false;
    }
    m_pScreen = SDL_GetWindowSurface(m_pWindow);

    //TODO: give the user a way to specify which image types they want to load
    //We have to dynamically init JPEG PNG TIFF and WEBP
    //For now let's just load PNGs
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags)&imgFlags))
    {
        SDL_assert(false);
        return false;
    }

    return true;
}

AssetHandle Renderer::LoadAsset(std::string fileName)
{
    //-1 means asset failed to load
    AssetHandle newAssetHandle = -1;
    SDL_Surface* pNewSurface = IMG_Load(fileName.c_str());
    if (pNewSurface == NULL)
    {
        _ASSERT(!"Failed to load asset");
    }
    else
    {
        SDL_Texture* pNewTexture = SDL_CreateTextureFromSurface(m_pRenderer,pNewSurface);
        //eventually maybe have some way of auto atlasing these textures
        //and the handle will indicate where in the atlas they are
        newAssetHandle = m_NextHandle++;
        m_Surfaces.insert(std::make_pair(newAssetHandle,pNewTexture));
        //no longer need the surface now that we have the texture
        SDL_FreeSurface(pNewSurface);
    }
    return newAssetHandle;
}

void Renderer::BeginDraw()
{
    SDL_SetRenderDrawColor(m_pRenderer,0,0,0,0xff);
    SDL_RenderClear(m_pRenderer);
}

void Renderer::Present()
{
    SDL_RenderPresent(m_pRenderer);
}

void Renderer::RenderCopy(AssetHandle handle, Rect src, Rect dest)
{
    SDL_RenderCopy(m_pRenderer, m_Surfaces[handle],&src,&dest);
}