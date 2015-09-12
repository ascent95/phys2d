#include <iostream>
#include "world.h"
#include "screen.h"

int main(int argc, char **argv) {
    Screen game_screen;
    World game_world;
    game_screen.init( "Phys2D", &game_world );
    game_world.init( &game_screen );
    
    while( game_screen.is_running() )
    {
        game_screen.handle_events();
        game_world.update();
        game_screen.render();
    }
    
    game_screen.quit();
    return 0;
}
