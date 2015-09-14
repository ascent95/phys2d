#include "vec2.h"

struct Material
{
    double density;
    double restitution;
};

struct MassData
{
    double mass;
    double inv_mass;
    double inertia;
    double inv_inertia;
};

struct AABB
{
    vec2d min;
    vec2d max;
};