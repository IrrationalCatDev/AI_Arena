#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

#include "main.h"

#include "EntityBase.h"


//temp stuff
int posx = 0;
int posy = 0;
bool temp = false;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    MainObject game;
    
    bool bDone = !game.InitializeProcesses();;
    auto delay = chrono::milliseconds(33);
    chrono::milliseconds elapsed;
    auto last = chrono::steady_clock::now();
    while (!bDone)
    {
        auto start = chrono::steady_clock::now();
        game.ProcessInput();
        elapsed = chrono::duration_cast<chrono::milliseconds>(start-last);
        bDone = game.Update(elapsed.count()/1000.0f);
        last = chrono::steady_clock::now();
        game.Render();
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration_cast<chrono::milliseconds>(
                    chrono::milliseconds(33)-
                    chrono::duration_cast<chrono::milliseconds>(end-start));
        if(diff.count() > 0)
            this_thread::sleep_for(diff);
    }
    
    return 0;
}

MainObject::MainObject()
{

}

MainObject::~MainObject()
{

    //destroy any other sdl things
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

bool MainObject::InitializeProcesses()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        SDL_assert(false);
        return false;
    }

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

    if(!renderer.Initialize())
    {
        return false;
    }
    return true;
}

void MainObject::ProcessInput()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            temp = true;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_q:
                temp = true;
                break;
            case SDLK_w:
                posy -= 1;
                break;
            case SDLK_a:
                posx -= 1;
                break;
            case SDLK_s:
                posy += 1;
                break;
            case SDLK_d:
                posx += 1;
                break;
            case SDLK_n:
                Vec2 newPos = {50,50};
                Vec2 newVel = {1000,1000};
                auto newEntity = new EntityBase();
                newEntity->SetPosition(newPos);
                newEntity->SetVelocity(newVel);
                //_entities.push_back(newEntity);
                break;
            }
        }
        //process event
    }
}

bool MainObject::Update(float elapsedTime)
{
    // for(auto entity : _entities)
    // {
    //     entity->Update(elapsedTime);
    // }
    return temp;
}

void MainObject::Render()
{
    //clear
    SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,0xff);
    SDL_RenderClear(m_pRenderer);

    //do rendery stuff
    // for(auto& entity : _entities)
    // {
    //     auto pos = entity->GetPosition();
    //     SDL_Rect rect = {pos.x,pos.y,50,50};
    //     SDL_SetRenderDrawColor(m_pRenderer,0xff,0,0,0xff);
    //     SDL_RenderFillRect(m_pRenderer, &rect);
    // }

    //present
    SDL_RenderPresent(m_pRenderer);
}