#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <vector>
#include <SDL2/SDL.h>
#include "vec2.h"

struct Material
{
    double density;
    double restitution;
};

struct MassData
{
    double mass;
    double inv_mass;
    double inertia;
    double inv_inertia;
};

struct AABB
{
    vec2d min;
    vec2d max;
};

class Circle;
class Rectangle;

class IEntity
{
public:
    IEntity() : m_material( {} ), m_mass_data( {} ), m_aabb( {} ), m_id( 0 ), m_colour( 0xFF000000 ) {}
    
    ~IEntity() {}
    
    virtual void draw( SDL_Renderer *renderer ) = 0; //Draws the shape on the screen.
    
    virtual void calc_AABB() = 0;   
    
    virtual bool intersect_visit( IEntity *e ) = 0;
    
    virtual bool intersect( Circle *circ ) = 0;
    
    virtual bool intersect( Rectangle *rect ) = 0;
    
    void update( double dt );
    
    void add_force( vec2d new_force );

    bool intersect_broad( IEntity *e );
    
    void resolve_collision( vec2d normal, vec2d approach, IEntity *collider );

    int get_id();
    AABB get_AABB();
    void set_colour( Uint32 colour );
    void set_id( int new_id );    
protected:
    vec2d m_force;
    vec2d m_velocity;
    vec2d m_position; //Represents the centre
    Material m_material;
    MassData m_mass_data;
    AABB m_aabb;
    int m_id;
    Uint32 m_colour;
};

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
