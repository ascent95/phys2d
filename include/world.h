#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "screen.h" //Circular include
#include "entity.h"
#include "grid.h"

class World //The presenter
{
public:
    void init( Screen *screen );

    void add( Entity *e ); //Might need to change this to some sort of handler of a click event sent from Screen.

    void update(); //Do timestep and update the world. Render to screen.

private:
    Screen *m_screen; //Need a pointer to the screen so that we can render entities
    Grid m_grid;
};

#endif // WORLD_H_INCLUDED
