#include "collision.h"
#include <string.h>

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

bool AABBvsAABB( AABB a, AABB b )
{
    if( a.max.x < b.min.x || a.min.x > b.max.x ) return false;
    if( a.min.y > b.max.y || a.max.y < b.min.y ) return false;
    
    return true;
}
