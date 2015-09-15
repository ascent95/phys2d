#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "interfaces.h"
#include "entity_structs.h"
#include "entity.h"
#include <vector>
#include <string>
#include <algorithm>

struct Pair
{
    IEntity *a;
    IEntity *b;
};

/*
struct Manifold
{
    Pair pair;
    double penetration;
    vec2d normal;
};
*/

class Pair_Cache
{
public:
    bool add( Pair man );
    std::vector< std::string > id_pairs;
    std::vector< Pair > entity_pairs;
};

//void resolve_collision( Manifold *m ); //This function calls the correct algorithm for resolving the collision. Check collision hasn't already been done.

//void rect_vs_rect( Manifold *m );

//void circle_vs_circle( Manifold *m );

//void rect_vs_circle( Rectangle *rect, Circle *circ, double penetration, vec2d normal );

bool AABBvsAABB( AABB a, AABB b );

//Need to create a class that will keep track of unique collisions. 

#endif