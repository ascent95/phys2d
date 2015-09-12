#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SDL2/SDL.h>
#include "world.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Screen
{
    public:
        Screen() : m_running( true ) {}

        bool init( const char *title, World *world );
        
        void quit();

        void render();

        void clear();

        void handle_events(); //These will use the pointer to the world to add new entities
        
        bool is_running(); //Returns m_closed

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        World *m_world;
        SDL_Event m_event; //For checking window close
        bool m_running; //Gets updated by handle_events
};

#endif // SCREEN_H_INCLUDED
