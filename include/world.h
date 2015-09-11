#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

class World
{
    public:
        World( Screen *screen ) : m_screen( screen );

        void add( Entity *e ); //Add an entity to the grid.

        void service(); //Do timestep and update the world. Render to screen.

    private:
        Screen *m_screen; //Need a pointer to the screen so that we can render entities.
}

#endif // WORLD_H_INCLUDED
