#include "entity.h"

struct Manifold
{
    Entity *a;
    Entity *b;
    double penetration;
    vec2d normal;
};

void resolve_collision( Manifold *m ); //This function calls the correct algorithm for resolving the collision. Check collision hasn't already been done.

void rect_vs_rect( Manifold *m );

void circle_vs_circle( Manifold *m );

void rect_vs_circle( Rectangle *rect, Circle *circ, double penetration, vec2d normal );

//Need to create a class that will keep track of unique collisions. 