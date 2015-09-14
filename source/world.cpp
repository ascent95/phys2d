/*
 * The World class is the controller of the physics engine.
 * It is responsible for adding entities, stepping/updating
 * and tying everything together.
 */

#include "world.h"
#include "screen.h"
#include "grid.h"

World::World()
{
    m_screen = new Screen( this );
    m_grid = new Grid();
}

World::~World()
{
    delete m_screen;
    delete m_grid;
}

void World::run()
{
    m_screen->init( "Phys2D" );
    vec2d min ( 0, 0 );
    vec2d max ( 640, 480 );
    m_grid->init( min, max, 20 );
    
    const double fps = 100;
    const double dt = 1 / fps;
    double accumulator = 0;
    
    double frame_start = SDL_GetTicks() / 1000.0;
    
    Circle test ( vec2d { 10, 10 }, 10, vec2d { 100, 20 } );
    m_grid->add( &test );
    
    while( m_screen->is_running() )
    {
        const double current_time = SDL_GetTicks() / 1000.0;
        accumulator += current_time - frame_start;
        frame_start = current_time;
        
        if( accumulator > 0.2 )
        {
            accumulator = 0.2;
        }
        m_screen->clear();
        m_screen->handle_events();
        while( accumulator > dt )
        {
            accumulator -= dt;
            m_grid->update( dt );
        }
        draw_entities();
        m_screen->render();
    }
    
    m_screen->quit();
}

void World::draw_entities()
{
    std::vector< IEntity* > *entities = m_grid->get_entities();
    SDL_Renderer *renderer = m_screen->get_renderer();
    
    for( std::vector< IEntity* >::iterator it = entities->begin(); it != entities->end(); ++it )
    {
        (*it)->draw( renderer );
    }
}
