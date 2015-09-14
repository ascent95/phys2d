/*
 * Everything relating to drawing to the screen. This means all
 * interaction with SDL.
 */

#include "screen.h"
#include "world.h"
#include <SDL2/SDL.h>
#include <cstdio>

Screen::Screen( IWorld *wld ) : m_running( true )
{
    m_world = wld;
}


bool Screen::init( const char *title )
{
    bool success = true;
    
    if( SDL_Init( SDL_INIT_VIDEO ) )
    {
        std::printf( "SDL could not initialise! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        m_window = SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( m_window == NULL )
        {
            std::printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );
            if( m_renderer == NULL )
            {
                std::printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
            }
        }
    }
    return success;
}

void Screen::clear()
{
    SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( m_renderer );
}

void Screen::handle_events()
{
    while( SDL_PollEvent( &m_event ) )
    {
        if( m_event.type == SDL_QUIT )
        {
            m_running = false;
        }
    }
}

bool Screen::is_running()
{
    return m_running;
}

void Screen::render()
{
    SDL_RenderPresent( m_renderer );
}

void Screen::quit()
{
    SDL_Quit();
}

SDL_Renderer *Screen::get_renderer()
{
    return m_renderer;
}


