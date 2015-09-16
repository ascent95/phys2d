#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <vector>
#include "vec2.h"
#include "interfaces.h"
#include <SDL2/SDL.h>

class Circle : public IEntity
{
public:
    
    Circle( vec2d position, double radius, vec2d velocity );
    Circle( vec2d position, double radius ) : Circle( position, radius, vec2d {0,0} ) {}
    void draw( SDL_Renderer *renderer );
    
    bool intersect_visit( IEntity *e );
    bool intersect( Circle *circ );
    bool intersect( Rectangle *rect );
    
    void calc_AABB();
private:
    double m_radius;
};

class Rectangle : public IEntity
{
public:
    Rectangle( vec2d position, double width, double height, vec2d velocity );
    Rectangle( vec2d position, double width, double height ) : Rectangle( position, width, height, vec2d { 0, 0 } ) {}
    void draw( SDL_Renderer *renderer );
    
    void calc_AABB();
    
    bool intersect_visit( IEntity *e );
    
    bool intersect( Circle *circ );
    
    bool intersect( Rectangle *rect );
    
private:
    double m_width;
    double m_height;
};

//Define other derived classes here.
#endif // ENTITY_H_INCLUDED
