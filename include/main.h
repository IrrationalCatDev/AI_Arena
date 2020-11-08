#pragma once

#include "../SDL2_Game_Framework/GameBase.h"
#include "../SDL2_Game_Framework/Sprite.h"

class MainObject : public GameBase
{
public:
    MainObject() = default;
    ~MainObject() = default;
 
private:
    bool OnInitialize() override;
    bool OnGameUpdate(float elapsedTime) override;
    void OnGameRender(Renderer* renderer) override;
    void OnGameInput(const SDL_Event& event) override;
    void OnExitRequested() override;

    Sprite tempAsset;

    
};


