#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Circle;
class Rectangle;
class IWorld;

class Renderer //will use visitor pattern to move all graphics calls to Renderer class.
{
public:
    void render( const Circle& ent );
    void render( const Rectangle& ent );
private:
    SDL_Renderer *m_renderer;
};

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
    
    virtual Renderer& get_renderer() = 0;
};

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
        
        Renderer& get_renderer();

    private:
        SDL_Window *m_window;
        Renderer *m_renderer;
        IWorld *m_world;
        SDL_Event m_event; //For checking window close
        bool m_running;
};

#endif // SCREEN_H_INCLUDED
