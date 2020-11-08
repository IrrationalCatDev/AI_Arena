#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

#include "main.h"
#include "../SDL2_Game_Framework/Indexer.h"

//temp stuff
int posx = 0;
int posy = 0;
bool temp = false;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    MainObject game;
    game.StartGame();
}

bool MainObject::OnInitialize()
{
    auto renderer = GetRenderer();
    //not sure I'm a big fan of this system right now.
    //there's not a good way of the sprite to tell the renderer to unload the asset
    tempAsset.InitSprite(renderer->LoadAsset("Assets/roguelikeChar_transparent.png"));
    tempAsset.SetIndexer(16,16,1,1);
    tempAsset.SetSpriteIndex(1,3);
    tempAsset.SetSize(64);
    return true;
}

bool MainObject::OnGameUpdate(float elapsedTime)
{
    static int pos;
    tempAsset.SetPosition(pos,10);
    pos += 1;
    if (pos > 100)
    {
        pos -= 100;
    }
    return true;
}

void MainObject::OnGameRender(Renderer* renderer)
{
    renderer->RenderRect({64,16,60,80},Colors::Red);
    renderer->RenderSprite(tempAsset);
}

void MainObject::OnGameInput(const SDL_Event& event)
{

}

void MainObject::OnExitRequested()
{

}
