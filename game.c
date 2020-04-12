#include "game.h"

int init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, Game* game)
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
    game->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!game->window)
    {
        fprintf(stderr, "Error: Could not create window (SDL_CreateWindow)");
        return EXIT_FAILURE;
    }
    //if window creation was successful, then the renderer will be created.
    game->renderer = SDL_CreateRenderer(game->window, -1, 0);
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    if (!game->renderer)
    {
        fprintf(stderr, "Error: Could not create renderer (SDL_CreateRenderer)");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void handle_events(Game* game)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        game->is_running = false;
        break;
        
    default:
        break;
    }
}
void update(void)
{

}
void render(Game* game)
{
    SDL_RenderClear(game->renderer);
    //add things to render here
    SDL_RenderPresent(game->renderer);
}
void clean(Game* game)
{
 SDL_DestroyWindow(game->window);
 SDL_DestroyRenderer(game->renderer);
 SDL_Quit();
 fprintf(stdout, "Game cleaned sucessfully\n");
}

Game* game_ctruct(void)
{
    Game* game = (Game*)malloc(sizeof(Game));
    game->is_running = true;
    game->renderer = NULL;
    game->window = NULL;
    return game;
}

bool running(Game* game)
{
    return game->is_running;
}

