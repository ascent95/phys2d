#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <vector>

class Grid
{
public:
    Grid() : m_unique( 0 ) {}
    
    void add( Entity *e );

    void find_collisions(); //Go through the grid and check collisions within each cell.
    //Will then generate manifolds and feed them to the collision resolution function. 
private:
    std::vector< Entity* > **m_entities;
    int m_unique;
};
#endif // GRID_H_INCLUDED
