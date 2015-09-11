#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <vector>

class Grid
{
public:
    void add( Entity *e );
	
	void find_collisions(); //Go through the grid and check collisions within each cell.
	//Will then generate manifolds and feed them to the collision resolution function. 
private:
    vector<*Entity> **m_entities;
}
#endif // GRID_H_INCLUDED
