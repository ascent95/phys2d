#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "vec2.h"
#include <SDL2/SDL.h>
#include <vector>
#include "entity_structs.h"

class IScreen
{
public:
    virtual ~IScreen() {}
    virtual bool init( const char *title ) = 0;
    virtual void quit() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual void handle_events() = 0;
    virtual bool is_running() = 0;
    
    virtual SDL_Renderer *get_renderer() = 0;
};

class IWorld
{
public:
    virtual ~IWorld() {}
    virtual void run() = 0;

};

class Circle;
class Rectangle;
class Pair_Cache;
struct Manifold;

class IGrid
{
public:
    virtual ~IGrid() {}
    
    virtual void init( vec2d min, vec2d max, int px_cell ) = 0;
    
    virtual void update( double dt ) = 0;
    
    virtual void broad_phase( Pair_Cache *ps ) = 0; //Go through the grid and check collisions within each cell.
    
    virtual void narrow_phase( Pair_Cache *ps ) = 0;
    
    virtual vec2<int> convert_to_cell( vec2d point ) = 0;
};

class IEntity
{
public:
    ~IEntity() {}
    virtual void draw( SDL_Renderer *renderer ) = 0; //Draws the shape on the screen.

    void update( double dt );
        
    void add_force( vec2d new_force );
    
    virtual void calc_AABB() = 0;
    
    AABB get_AABB();
    
    bool intersect_broad( IEntity *e );
    
    virtual bool intersect_visit( IEntity *e ) = 0;
    
    virtual bool intersect( Circle *circ ) = 0;
    
    virtual bool intersect( Rectangle *rect ) = 0;
    
    void set_id( int new_id );
    
    int get_id();
        
protected:
    vec2d m_force;
    vec2d m_velocity;
    vec2d m_position; //Represents the centre
    Material m_material;
    MassData m_mass_data;
    AABB m_aabb;
    int m_id;
};
#endif 