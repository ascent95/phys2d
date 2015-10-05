/*
 * Everything relating to drawing to the screen. This means all
 * interaction with SDL.
 */

#include "screen.h"
#include "world.h"
#include "entity.h"
#include <SDL2/SDL.h>
#include <cstdio>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL.h>

bool Renderer::init_renderer( SDL_Window* window )
{
    m_renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( m_renderer == NULL )
    {
        return false;
    }
    else
    {
        SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        return true;
    }
}


void Renderer::draw ( const Rectangle& ent )
{
    AABB aabb = ent.get_AABB();
    rectangleColor( m_renderer, aabb.min.x, aabb.min.y, aabb.max.x, aabb.max.y, ent.get_colour() );
}

void Renderer::draw ( const Circle& ent )
{
    vec2d pos = ent.get_position();
    circleColor( m_renderer, pos.x, pos.y, ent.get_radius(), ent.get_colour() );
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( m_renderer );
}

void Renderer::render()
{
    SDL_RenderPresent( m_renderer );
}

void Renderer::quit()
{
    SDL_Quit();
}

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
            m_renderer = new Renderer;
            if( !m_renderer->init_renderer( m_window ) )
            {
                std::printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
        }
    }
    return success;
}

void Screen::clear()
{
    m_renderer->clear();
    
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
    m_renderer->render();
}

void Screen::quit()
{
    m_renderer->quit();
}

Renderer& Screen::get_renderer()
{
    return *m_renderer;
}


