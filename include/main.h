#pragma once

#include "../SDL2_Game_Framework/GameBase.h"

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

    AssetHandle tempAsset;

    
};


