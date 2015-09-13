#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "vec2.h"
#include <SDL2/SDL.h>
#include "entity_structs.h"
#include <vector>

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
};

class IWorld
{
public:
    virtual ~IWorld() {}
    virtual void run() = 0;
    
    virtual void update() = 0;
};

class IGrid
{
public:
    virtual ~IGrid() {}
    
    virtual void init( vec2d min, vec2d max, int px_cell ) = 0;
    
    virtual void update() = 0;
    
    virtual void find_collisions() = 0; //Go through the grid and check collisions within each cell.
    //Will then generate manifolds and feed them to the collision resolution function. 
    
    virtual vec2<int> convert_to_cell( vec2d point ) = 0;
};

class IEntity
{
public:
    ~IEntity() {}
    virtual void draw( SDL_Renderer *renderer ) = 0; //Draws the shape on the screen.

    void move();
    
    virtual void add_to_grid( std::vector<vec2<int>> *coords ) = 0; //Updates the vector with the coordinates that need to be added.
        
    void add_force( vec2d new_force );
    
    void set_id( int new_id );
        
protected:
    vec2d force;
    vec2d velocity;
    vec2d position; //Represents the centre
    Material m_material;
    MassData m_mass_data;
    int id;
};
#endif 