#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Screen
{
    public:

        bool init();

        void render();

        void clear();

        void handle_events();

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Event m_event; //For checking window close
};

#endif // SCREEN_H_INCLUDED
