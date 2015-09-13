/*
 * The World class is the controller of the physics engine.
 * It is responsible for adding entities, stepping/updating
 * and tying everything together.
 */

#include "world.h"
#include "screen.h"

World::World()
{
    m_screen = new Screen( this );
}

World::~World()
{
    delete m_screen;
}

void World::run()
{
    m_screen->init( "Phys2D" );
    while( m_screen->is_running() )
    {
        m_screen->clear();
        m_screen->handle_events();
        update();
        m_screen->render();
    }
    
    m_screen->quit();
}

void World::update ()
{
    
}
