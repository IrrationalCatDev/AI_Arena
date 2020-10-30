#include <SDL.h>
#include <SDL_assert.h>
#include "ScopeGuard.h"
#include "renderer.h"

class MainObject
{
public:
    MainObject();
    ~MainObject();

    bool InitializeProcesses();

    void ProcessInput();
    bool Update(float elapsedTime);
    void Render();
private:
    Renderer renderer;
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    SDL_Event event;

};


