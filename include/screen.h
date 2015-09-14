#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SDL2/SDL.h>
#include "interfaces.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Screen : public IScreen
{
    public:
        Screen( IWorld *wld );
        
        bool init( const char *title );
        void quit();
        void render();
        void clear();
        void handle_events();
        bool is_running();
        
        SDL_Renderer *get_renderer();

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        IWorld *m_world;
        SDL_Event m_event; //For checking window close
        bool m_running;
};

#endif // SCREEN_H_INCLUDED
