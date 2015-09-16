#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class IScreen
{
public:
    virtual ~IScreen() {}
    virtual bool init( const char *title ) = 0;
    virtual void quit() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void handle_events() = 0;
    virtual bool is_running() = 0;
    
    virtual SDL_Renderer *get_renderer() = 0;
};

class IWorld;

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
