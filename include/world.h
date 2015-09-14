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

    void draw_entities();

private:
    IScreen *m_screen; //Need a pointer to the screen so that we can render entities
    Grid *m_grid;
    
    double get_time();
};

#endif // WORLD_H_INCLUDED
