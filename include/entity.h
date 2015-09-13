#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <vector>
#include "vec2.h"
#include <SDL2/SDL.h>

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

class Entity
{
public:
    virtual void draw( SDL_Renderer *renderer ) = 0; //Draws the shape on the screen.

    void move();
        
    void add_force( vec2d new_force );
        
protected:
    vec2d force;
    vec2d velocity;
    vec2d position; //Represents the centre
    Material m_material;
    MassData m_mass_data;
    std::vector<Entity*> m_grid_entries;
//Needs to contain a list of grid cells which it is in.
};

class Circle : public Entity
{
public:
    void draw( SDL_Renderer *renderer ) override {};
private:
    double radius;
};

class Rectangle : public Entity
{
public:
    void draw( SDL_Renderer *renderer ) override {};
private:
    double width;
    double height;
};



//Define other derived classes here.
#endif // ENTITY_H_INCLUDED
