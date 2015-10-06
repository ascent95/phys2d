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
class Renderer;

class IEntity
{
public:
    IEntity() : m_material( {} ), m_mass_data( {} ), m_aabb( {} ), m_id( 0 ), m_colour( 0xFF000000 ) {}
    
    ~IEntity() {}
    
    virtual void draw( Renderer& r ) = 0; //Uses visitor pattern.
    
    virtual bool intersect_visit( IEntity *e ) = 0;
    
    virtual bool intersect( Circle *circ ) = 0;
    
    virtual bool intersect( Rectangle *rect ) = 0;
    
    virtual void positional_correction( double penetration, vec2d normal, IEntity *e ); 
    
    void update( double dt );
    
    void add_force( vec2d new_force );
    
    bool intersect_broad( IEntity *e );
    
    void resolve_collision( vec2d normal, vec2d approach, IEntity *collider );

    int get_id() const;
    AABB get_AABB() const;
    double get_mass() const;
    vec2d get_position() const;
    Uint32 get_colour() const;
    void set_colour( Uint32 colour );
    void set_id( int new_id );    
protected:
    virtual void calc_AABB() = 0;
    virtual void calc_mass() = 0;
    void circle_vs_rectangle( Circle *circ, Rectangle *rect );
    
    vec2d m_force;
    vec2d m_velocity;
    vec2d m_position; //Represents the centre
    Material m_material;
    MassData m_mass_data;
    AABB m_aabb;
    int m_id;
    Uint32 m_colour;
    
private:
    void apply_forces( double dt );
};

class Circle : public IEntity
{
public:
    
    Circle( vec2d position, double radius, double density, vec2d velocity );
    Circle( vec2d position, double radius ) : Circle( position, radius, 1, vec2d {0,0} ) {}
    void draw( Renderer& r );
    
    bool intersect_visit( IEntity *e );
    bool intersect( Circle *circ );
    bool intersect( Rectangle *rect );
    
    double get_radius() const;
protected:
    void calc_AABB();
    void calc_mass();
private:
       
    double m_radius;
};

class Rectangle : public IEntity
{
public:
    Rectangle( vec2d position, double width, double height, double density, vec2d velocity );
    Rectangle( vec2d position, double width, double height ) : Rectangle( position, width, height, 1, vec2d { 0, 0 } ) {}
    void draw( Renderer& r );
    
    bool intersect_visit( IEntity *e );
    
    bool intersect( Circle *circ );
    
    bool intersect( Rectangle *rect );
protected:
    void calc_AABB();
    void calc_mass();
private:

    double m_width;
    double m_height;
};

//Define other derived classes here.
#endif // ENTITY_H_INCLUDED
