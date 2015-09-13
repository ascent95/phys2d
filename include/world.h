#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "interfaces.h"
#include "entity.h"
#include "grid.h"

class World : public IWorld//The presenter
{
public:
    World();
    
    ~World();
    
    void run();

    //void add( Entity *e ); //Might need to change this to some sort of handler of a click event sent from Screen.

    void update(); //Do timestep and update the world. Render to screen.

private:
    IScreen *m_screen; //Need a pointer to the screen so that we can render entities
    Grid m_grid;
};

#endif // WORLD_H_INCLUDED
