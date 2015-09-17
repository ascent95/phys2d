/*
 * The World class is the controller of the physics engine.
 * It is responsible for adding entities, stepping/updating
 * and tying everything together.
 */

#include "world.h"
#include "screen.h"
#include "grid.h"
#include "entity.h"

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
    m_grid->init( vec2d { -20, -20 }, vec2d { 800, 600 }, 40 );
    
    const double fps = 100;
    const double dt = 1 / fps;
    double accumulator = 0;
    
    double frame_start = get_time();
    
    /*
    Circle test1 ( vec2d { 200, 300 }, 10, vec2d { 50, 0 } );
    Circle test2 ( vec2d { 400, 300 }, 30, vec2d { -50, 0 } );
    Rectangle test3 ( vec2d { 300, 100 }, 100, 100 , vec2d { 0, 50 } );
    Rectangle test4 ( vec2d { 300, 300 }, 10, 10 , vec2d { 0, 0 } );
    test3.set_colour( 0xFFFF0000 );
    test4.set_colour( 0xFF0000FF );
    m_grid->add( &test1 );
    m_grid->add( &test2 );
    m_grid->add( &test3 );
    m_grid->add( &test4 );
    */
    
    Circle test1 ( vec2d { 300, 200 }, 10, vec2d { 50, 0 } );
    Rectangle test2 ( vec2d { 420, 200 }, 10, 10 , vec2d { 0, 0 } );
    Circle test3 ( vec2d { 500, 200 }, 10, vec2d { -50, 0 } );
    m_grid->add( &test1 );
    m_grid->add( &test2 );
    m_grid->add( &test3 );
    while( m_screen->is_running() )
    {
        const double current_time = get_time();
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

double World::get_time()
{
    return SDL_GetTicks() / 1000.0;
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
