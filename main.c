#include "game.h"
#include <SDL2/SDL.h>



int main()
{
    init("game window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (is_running)
    {
        handle_events();
        update();
        render();
    }
    
    clean();
}
