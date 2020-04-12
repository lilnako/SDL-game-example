#ifndef game_h
#define game_h
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Game
{
    bool is_running;
    SDL_Window* window;
    SDL_Renderer* renderer;  
} Game;

Game* game_ctruct(void);
int init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, Game* game);
void handle_events(Game* game);
void update(void);
void render(Game* game);
void clean(Game* game);
bool running(Game* game);

bool is_running;
SDL_Window* window;
SDL_Renderer* renderer;

#endif
