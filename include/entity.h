#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <vector>
#include "vec2.h"
#include "interfaces.h"
#include <SDL2/SDL.h>

class Circle : public IEntity
{
public:
    void draw( SDL_Renderer *renderer ) override {};
    
    void add_to_grid( std::vector<vec2<int>> *coords );
private:
    double m_radius;
};

class Rectangle : public IEntity
{
public:
    void draw( SDL_Renderer *renderer ) override {};
    
    void add_to_grid( std::vector<vec2<int>> *coords );
private:
    double m_width;
    double m_height;
};



//Define other derived classes here.
#endif // ENTITY_H_INCLUDED
