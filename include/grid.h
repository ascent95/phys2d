#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED


#define RESERVED_ENTITIES 10

#include <vector>
#include "interfaces.h"
#include "entity.h"

class Grid : public IGrid
{
public:
    Grid() : m_unique( 0 ) {}
    
    void init( vec2d min, vec2d max, int px_cell );
    
    void add( IEntity *e );
    
    void update();
    
    void find_collisions(); //Go through the grid and check collisions within each cell.
    //Will then generate manifolds and feed them to the collision resolution function. 
    
    vec2<int> convert_to_cell( vec2d point );
private:
    std::vector< IEntity* > m_entities;
    std::vector< IEntity* > **m_grid;
    int m_unique;
    vec2d m_min;
    int m_width; //In cells
    int m_height; //In cells
    int m_px_cell; //In pixels
    
    void add_to_cell( int x, int y, IEntity *e ); //Allows an entity to add itself to a cell in the grid
};
#endif // GRID_H_INCLUDED
