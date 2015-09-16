#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED


#define RESERVED_ENTITIES 10

#include <vector>
#include <string>
#include "vec2.h"

class IEntity;

struct Pair
{
    IEntity *a;
    IEntity *b;
};

class Pair_Cache
{
public:
    bool add( Pair man );
    std::vector< std::string > id_pairs;
    std::vector< Pair > entity_pairs;
};

class IGrid
{
public:
    virtual ~IGrid() {}
    
    virtual void init( vec2d min, vec2d max, int px_cell ) = 0;
    
    virtual void update( double dt ) = 0;
private:
    virtual void broad_phase( Pair_Cache *ps ) = 0; //Go through the grid and check collisions within each cell.
    
    virtual void narrow_phase( Pair_Cache *ps ) = 0;
    
    virtual vec2<int> convert_to_cell( vec2d point ) = 0;
};

class Grid : public IGrid
{
public:
    Grid() : m_unique( 0 ) {}
    
    ~Grid();
    
    void init( vec2d min, vec2d max, int px_cell );
    
    void add( IEntity *e );
    
    void update( double dt );
    
    void broad_phase( Pair_Cache *ps ); //Go through the grid and check collisions within each cell.
    //Will then generate manifolds and feed them to the collision resolution function. 
    
    void narrow_phase( Pair_Cache *ps );
    
    std::vector< IEntity* >* get_entities();
    
private:
    std::vector< IEntity* > m_entities;
    std::vector< IEntity* > **m_grid;
    int m_unique;
    vec2d m_min;
    int m_width; //In cells
    int m_height; //In cells
    int m_px_cell; //In pixels
    
    void add_to_cell( vec2< int > pos, IEntity *e ); //Adds an entity to a cell
    vec2<int> convert_to_cell( vec2d point ); //Finds the cell location of a point
    void insert_in_grid( IEntity *e ); //Uses above functions to insert an entity into all relevant cells
    void remake_grid();
};



#endif // GRID_H_INCLUDED
