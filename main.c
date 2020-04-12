#include "game.h"
#include <SDL2/SDL.h>



int main()
{
    Game* game = game_ctruct();
    init("game window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false, game);
    while (game->is_running)
    {
        handle_events(game);
        update();
        render(game);
    }
    
    clean(game);
}
