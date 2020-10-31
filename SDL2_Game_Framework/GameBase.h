#pragma once

#include <SDL.h>

#include "renderer.h"

class GameBase
{
public:
    GameBase();
    virtual ~GameBase();

    void StartGame();

protected:

    bool InitializeProcesses();

    void ProcessInput();
    bool Update(float elapsedTime);
    void Render();

    virtual bool OnInitialize();
    virtual bool OnGameUpdate(float elapsedTime);
    virtual void OnGameRender(Renderer* renderer);
    virtual void OnGameInput(const SDL_Event& event);
    virtual void OnExitRequested();

    Renderer* GetRenderer();

private:
    Renderer m_Renderer;

    SDL_Event event;

    bool m_bGameExiting = false;
};