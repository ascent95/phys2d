#include "grid.h"
#include <vector>
#include <math.h>

void Grid::init( vec2d min, vec2d max, int px_cell )
{    
    double w = max.x - min.x;
    double h = max.y - min.y;
    m_width = ( w + px_cell - 1 ) / px_cell;
    m_height = ( h + px_cell - 1 ) / px_cell;
    m_px_cell = px_cell;
    
    m_entities.reserve( RESERVED_ENTITIES );
    m_grid = new std::vector< IEntity* >*[ m_width ];
}

void Grid::add ( IEntity* e )
{
    //Add it to the list of entities
    m_entities.push_back( e );
    
    //Now add it to the grid
    std::vector<vec2<int>> coords;
    e->add_to_grid( &coords );
    
    //coords is now populated with the coordinates that need to be filled.
    for( std::vector< vec2<int> >::iterator it = coords.begin(); it != coords.end(); ++it )
    {
        vec2<int> coord = *it;
        add_to_cell( coord.x, coord.y, e );
    }
    
}

void Grid::update()
{

}

void Grid::find_collisions()
{

}

void Grid::add_to_cell ( int x, int y, IEntity* e )
{
    if( !m_grid[ x ] )
    {
        m_grid[ x ] = new std::vector< IEntity* >[ m_height ];
    }
    m_grid[ x ][ y ].push_back( e );
}

vec2< int > Grid::convert_to_cell ( vec2d point )
{
    vec2< int > result;
    result.x = floor( ( point.x - m_min.x ) / m_px_cell );
    result.y = floor( ( point.y - m_min.y ) / m_px_cell );
    
    return result;
}
