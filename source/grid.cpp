#include "grid.h"
#include <vector>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include "entity.h"

Grid::~Grid()
{
    for(int i = 0; i < m_width; i++)
    {
        if( m_grid[ i ] ) 
        {
            delete[] m_grid[ i ];
            m_grid[ i ] = nullptr;
        }
    }
    delete[] m_grid;
}


void Grid::init( vec2d min, vec2d max, int px_cell )
{    
    m_min = min;
    double w = max.x - min.x;
    double h = max.y - min.y;
    m_width = ( w + px_cell - 1 ) / px_cell;
    m_height = ( h + px_cell - 1 ) / px_cell;
    
    assert( px_cell );
    m_px_cell = px_cell;
    
    m_entities.reserve( RESERVED_ENTITIES );
    m_grid = new std::vector< IEntity* >*[ m_width ]();
}

void Grid::add ( IEntity* e )
{
    //Add it to the list of entities
    e->set_id( m_unique++ );
    m_entities.push_back( e );
    
    insert_in_grid( e );
    
}

void Grid::update( double dt )
{
    for( std::vector< IEntity* >::iterator it = m_entities.begin(); it != m_entities.end(); ++it )
    {
        (*it)->update( dt );
    }
    remake_grid();
    Pair_Cache ps;
    broad_phase( &ps );
    narrow_phase( &ps );
}

void Grid::broad_phase( Pair_Cache *ps ) //Broad phase collision check
{
    //For each occupied column
    for( int col = 0; col < m_width; col++ )
    {
        if( m_grid[ col ] == nullptr ) continue;
        
        for( int row = 0; row < m_height; row++ )
        {
            if( m_grid[ col ][ row ].empty() ) continue;
            
            for( std::vector< IEntity* >::iterator it = m_grid[ col ][ row ].begin(); it != m_grid[ col ][ row ].end(); ++it )
            {
                IEntity *to_check = *it;
                std::vector< IEntity* >::iterator check_against = it;
                ++check_against;
                for(; check_against != m_grid[ col ][ row ].end(); ++check_against )
                {
                    if( to_check->intersect_broad( *check_against ) )
                    {
                        //If there is an AABB intersection, generate a pair and add it to the cache.
                        ps->add( Pair { to_check, *check_against } );
                    }
                }
            }
        }
    }            
}

void Grid::narrow_phase ( Pair_Cache* ps )
{
    for( std::vector< Pair >::iterator it = ps->entity_pairs.begin(); it != ps->entity_pairs.end(); ++it )
    {
        if( (*it).a->intersect_visit( (*it).b ) )
        {
            //They intersect and the collision has been resolved
            
        }
    }
}

//Private functions 
void Grid::add_to_cell ( vec2< int > pos, IEntity* e )
{    
    if( pos.x < m_width && pos.y < m_height && pos.x >= 0 && pos.y >= 0 )
    {
        if( !m_grid[ pos.x ] )
        {
            m_grid[ pos.x ] = new std::vector< IEntity* >[ m_height ]();
        }
        m_grid[ pos.x ][ pos.y ].push_back( e );
    }
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
    for(; counter.x <= max_cell.x; counter.x++ )
    {
        for(; counter.y <= max_cell.y; counter.y++ )
        {
            add_to_cell( counter, e );
        }
        counter.y = min_cell.y;
    }
}

void Grid::remake_grid()
{
    for(int i = 0; i < m_width; i++)
    {
        if( m_grid[ i ] ) 
        {
            delete[] m_grid[ i ];
            m_grid[ i ] = nullptr;
        }
    }
    for( std::vector< IEntity* >::iterator it = m_entities.begin(); it != m_entities.end(); ++it )
    {
        insert_in_grid( *it );
    }
}


std::vector< IEntity* >* Grid::get_entities()
{
    return &m_entities;
}

bool Pair_Cache::add ( Pair pair )
{
    int id_a = pair.a->get_id();
    int id_b = pair.b->get_id();
    char str_pair[16];
    if( id_a < id_b ) sprintf( str_pair, "%d:%d", id_a, id_b );
    else sprintf( str_pair, "%d:%d", id_a, id_b );

    if( std::find ( id_pairs.begin(), id_pairs.end(), str_pair) == id_pairs.end() )
    {
        //Does not contain the pair
        id_pairs.push_back( str_pair );
        entity_pairs.push_back( pair );
        return true; //Was a success. The pair is now added.
    }
    return false;
}

