#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "grid.h"
#include "screen.h"

class IWorld
{
public:
    virtual ~IWorld() {}
    virtual void run() = 0;

};

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
