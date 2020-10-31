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
    tempAsset = renderer->LoadAsset("Assets/roguelikeChar_transparent.png");
    return true;
}

bool MainObject::OnGameUpdate(float elapsedTime)
{
    return true;
}

void MainObject::OnGameRender(Renderer* renderer)
{
    Indexer index(16,16,1,1);
    renderer->RenderCopy(tempAsset,index.GetRectAtIndex(1,1),{16,16,16,16});
}

void MainObject::OnGameInput(const SDL_Event& event)
{

}

void MainObject::OnExitRequested()
{

}
