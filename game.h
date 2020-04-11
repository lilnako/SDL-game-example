#ifndef game_h
#define game_h
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

// typedef struct Game
// {
//     ;
// } Game;

void game_ctruct(void);
int init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
void handle_events(void);
void update(void);
void render(void);
void clean(void);
bool running(void);

extern bool is_running;
extern SDL_Window* window;
extern SDL_Renderer* renderer;

#endif
