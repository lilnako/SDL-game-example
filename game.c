#include "game.h"

bool is_running = true;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    //bool for fullscreen. if fullscreen is true, it sets flags to the value
    //corresponding to SDL_WINDOW_FULLSCREEN (1)
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    //initializes all subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error: could not initialize SDL (SDL_Init)");
        return EXIT_FAILURE;
    }
    //if the SDL_Init was successful, the window will be created
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!window)
    {
        fprintf(stderr, "Error: Could not create window (SDL_CreateWindow)");
        return EXIT_FAILURE;
    }
    //if window creation was successful, then the renderer will be created.
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    if (!renderer)
    {
        fprintf(stderr, "Error: Could not create renderer (SDL_CreateRenderer)");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void handle_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;
    
    default:
        break;
    }
}
void update()
{

}
void render()
{
    SDL_RenderClear(renderer);
    //add things to render here
    SDL_RenderPresent(renderer);
}
void clean()
{
 SDL_DestroyWindow(window);
 SDL_DestroyRenderer(renderer);
 SDL_Quit();
 fprintf(stdout, "Game cleaned sucessfully\n");
}



bool running()
{
    return is_running;
}

