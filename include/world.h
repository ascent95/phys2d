#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

class World
{
    public:
        World( Screen *screen ) : m_screen( screen ), m_unique( 0 );

        void add( Entity *e ); //Add an entity to the grid. Assign it a unique ID.

        void service(); //Do timestep and update the world. Render to screen.

    private:
        Screen *m_screen; //Need a pointer to the screen so that we can render entities
        Grid m_grid;
        int m_unique;
}

#endif // WORLD_H_INCLUDED
