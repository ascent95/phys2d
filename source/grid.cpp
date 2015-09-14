#include "grid.h"
#include "interfaces.h"
#include <vector>
#include <math.h>
#include <assert.h>

Grid::~Grid()
{
    for(int i = 0; i < m_width; i++)
    {
        delete m_grid[ i ];
    }
    delete m_grid;
}


void Grid::init( vec2d min, vec2d max, int px_cell )
{    
    double w = max.x - min.x;
    double h = max.y - min.y;
    m_width = ( w + px_cell - 1 ) / px_cell;
    m_height = ( h + px_cell - 1 ) / px_cell;
    m_px_cell = px_cell;
    
    m_entities.reserve( RESERVED_ENTITIES );
    m_grid = new std::vector< IEntity* >*[ m_width ]();
}

void Grid::add ( IEntity* e )
{
    //Add it to the list of entities
    m_entities.push_back( e );
    
    insert_in_grid( e );
    
}

void Grid::update( Uint32 dt )
{
    for( std::vector< IEntity* >::iterator it = m_entities.begin(); it != m_entities.end(); ++it )
    {
        (*it)->update( dt );
    }
}

void Grid::find_collisions()
{

}


//Private functions 
void Grid::add_to_cell ( vec2< int > pos, IEntity* e )
{
    if( !m_grid[ pos.x ] )
    {
        m_grid[ pos.x ] = new std::vector< IEntity* >[ m_height ]();
    }
    m_grid[ pos.x ][ pos.y ].push_back( e );
}

vec2< int > Grid::convert_to_cell ( vec2d point )
{
    vec2< int > result;
    assert( m_px_cell );
    result.x = floor( ( point.x - m_min.x ) / m_px_cell );
    result.y = floor( ( point.y - m_min.y ) / m_px_cell );
    
    return result;
}

void Grid::insert_in_grid ( IEntity* e )
{
    AABB aabb = e->get_AABB();
    vec2< int > min_cell = convert_to_cell( aabb.min );
    vec2< int > max_cell = convert_to_cell( aabb.max );
    vec2< int > counter;
    counter = min_cell;
    for( ; counter.x < max_cell.x; counter.x++ )
    {
        for(; counter.y < max_cell.y; counter.y++ )
        {
            add_to_cell( counter, e );
        }
        counter.y = min_cell.y;
    }
}

std::vector< IEntity* >* Grid::get_entities()
{
    return &m_entities;
}

