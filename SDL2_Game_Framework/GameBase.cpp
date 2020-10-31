#include <chrono>
#include <thread>

#include "GameBase.h"

using namespace std;

GameBase::GameBase()
{

}

GameBase::~GameBase()
{
    m_Renderer.Cleanup();
    //do we need to uninitialize the generic renderer?
    SDL_Quit();
}

bool GameBase::InitializeProcesses()
{
    //TODO: make this area a little more dynamic
    //so the user can customize their SDL experience
    if(SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        SDL_assert(false);
        return false;
    }

    if(!m_Renderer.Initialize())
    {
        return false;
    }

    if (!OnInitialize())
    {
        _ASSERT(!"OnInitialize failed");
        return false;
    }
    

    return true;
}

void GameBase::ProcessInput()
{
    while(SDL_PollEvent(&event))
    {
        //process event
        if(event.type == SDL_QUIT)
        {
            m_bGameExiting = true;
        }
        else
        {
            OnGameInput(event);
        }
    }
}

void GameBase::Render()
{
    m_Renderer.BeginDraw();
    OnGameRender(&m_Renderer);
    m_Renderer.Present();
}


bool GameBase::Update(float elapsedTime)
{
    if (!m_bGameExiting)
    {
        m_bGameExiting = !OnGameUpdate(elapsedTime);
    }

    //The game itself might request an exit during the run
    //So check again and request an exit at this time
    if (m_bGameExiting)
    {
        OnExitRequested();
    }
    return !m_bGameExiting;
}

bool GameBase::OnGameUpdate(float elapsedTime)
{
    //Game gets to do their update now
    //Return true because reasons
    return true;
}

void GameBase::OnGameRender(Renderer* renderer)
{
    //Game gets to do their render now
}
void GameBase::OnGameInput(const SDL_Event& event)
{
    //Game gets to process their own input
}

void GameBase::OnExitRequested()
{
    //Game gets to clean up anything (save data etc) now
    //The program will end shortly after this function ends
    //Game base will then clean up its SDL stuff and
    //anything else it is responsible for
}

void GameBase::StartGame()
{
    //TODO: is all this chrono stuff really necessary?
    //Seems like a lot of effort for not much reward
    bool bDone = !InitializeProcesses();
    auto delay = chrono::milliseconds(33);
    chrono::milliseconds elapsed;
    auto last = chrono::steady_clock::now();
    while (!bDone)
    {
        ProcessInput();
        auto start = chrono::steady_clock::now();
        elapsed = chrono::duration_cast<chrono::milliseconds>(start-last);
        bDone = !Update(elapsed.count()/1000.0f);
        last = chrono::steady_clock::now();
        Render();
        auto end = chrono::steady_clock::now();
        auto diff = chrono::duration_cast<chrono::milliseconds>(
            delay-chrono::duration_cast<chrono::milliseconds>(end-start));
        if(diff.count() > 0)
            this_thread::sleep_for(diff);
    }
}

Renderer* GameBase::GetRenderer()
{
    return &m_Renderer;
}

bool GameBase::OnInitialize()
{
    return true;
}