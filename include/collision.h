#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "interfaces.h"
#include "entity_structs.h"

struct Manifold
{
    IEntity *a;
    IEntity *b;
    double penetration;
    vec2d normal;
};

void resolve_collision( Manifold *m ); //This function calls the correct algorithm for resolving the collision. Check collision hasn't already been done.

void rect_vs_rect( Manifold *m );

void circle_vs_circle( Manifold *m );

void rect_vs_circle( Rectangle *rect, Circle *circ, double penetration, vec2d normal );

bool AABBvsAABB( AABB a, AABB b )
{
    if( a.max.x < b.min.x || a.min.x > b.max.x ) return false;
    if( a.min.y > b.max.y || a.max.y < b.min.y ) return false;
    
    return true;
}

//Need to create a class that will keep track of unique collisions. 

#endif