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
    m_grid->init( min, max, 10 );
    
    const double fps = 100;
    const double dt = 1 / fps;
    double accumulator = 0;
    
    double frame_start = SDL_GetTicks() / 1000;
    
    vec2d xy ( 10, 10 );
    Circle test ( xy, 10 );
    m_grid->add( &test );
    
    while( m_screen->is_running() )
    {
        const double current_time = SDL_GetTicks() / 1000;
        accumulator += current_time - frame_start;
        frame_start = current_time;
        
        if( accumulator > 200 )
        {
            accumulator = 200;
        }
        
        while( accumulator > dt )
        {
            accumulator -= dt;
            m_screen->clear();
            m_screen->handle_events();
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
