#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

class Entity
{
    public:
        draw( SDL_Renderer *renderer );

    protected:

    private:
        Material m_material;
        MassData m_mass_data;

    //Needs to contain a list of grid cells which it is in.
}

struct Material
{
    double density;
    double restitution;
}

struct MassData
{
    double mass;
    double inv_mass;
    double inertia;
    double inv_inertia;
}

//Define other derived classes here.
#endif // ENTITY_H_INCLUDED
