/*
 * This class represents any object that can be added to the world.
 * Entities can have shapes associated with them, as well as other attributes.
 */

#include "interfaces.h"
#include "entity.h"
#include "collision.h"
#include "vec2.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

Circle::Circle ( vec2d position, double radius, vec2d velocity )
{
    m_position = position;
    m_radius = radius;
    m_velocity = velocity;
    calc_AABB();
    
    m_material.restitution = 1;
    
    m_mass_data.mass = M_PI * radius * radius;
    m_mass_data.inv_mass = 1 / m_mass_data.mass;
}

void Circle::calc_AABB()
{
    m_aabb.min.x = m_position.x - m_radius;
    m_aabb.min.y = m_position.y - m_radius;
    m_aabb.max.x = m_position.x + m_radius;
    m_aabb.max.y = m_position.y + m_radius;
}

void Circle::draw ( SDL_Renderer* renderer )
{
    circleColor( renderer, m_position.x, m_position.y, m_radius, m_colour);
}

bool Circle::intersect_visit ( IEntity* e )
{
    return e->intersect( this );
}

bool Circle::intersect ( Rectangle* rect )
{
    printf( "Intersecting a Rectangle\n" );
    return true;
}

bool Circle::intersect ( Circle* circ )
{
    vec2d AtoB = circ->m_position - m_position;
    double rad_lengths = circ->m_radius + m_radius;
    double penetration = rad_lengths - AtoB.length();
    if( penetration > 0 )
    {
        vec2d normal = AtoB.normalize();
        vec2d approach = circ->m_velocity - m_velocity;
        float vel_along_normal = vec2d::dot( normal, approach );
        
        if( vel_along_normal > 0 )
        {
            printf( "Already separating!\n" );
        }
        else
        {
            double max_restitution = std::max( m_material.restitution, circ->m_material.restitution );
            double j = ( 1 + max_restitution ) * vel_along_normal / ( m_mass_data.inv_mass + circ->m_mass_data.inv_mass );
            m_velocity.x += j * normal.x * m_mass_data.inv_mass;
            m_velocity.y += j * normal.y * m_mass_data.inv_mass;
            circ->m_velocity.x -= j * normal.x * circ->m_mass_data.inv_mass;
            circ->m_velocity.y -= j * normal.y * circ->m_mass_data.inv_mass;
            
            
        }
        printf( "Intersecting a Circle\n" );
    }
    
    return true;
}

Rectangle::Rectangle ( vec2d position, double width, double height, vec2d velocity ) : m_width( width ), m_height( height )
{
    m_position = position;
    m_velocity = velocity;
}


void Rectangle::draw ( SDL_Renderer* renderer )
{
    rectangleColor( renderer, m_aabb.min.x, m_aabb.min.y, m_aabb.max.x, m_aabb.max.y, m_colour );
}

void Rectangle::calc_AABB()
{
    m_aabb.min.x = m_position.x - m_width / 2;
    m_aabb.min.y = m_position.y - m_height / 2;
    m_aabb.max.x = m_position.x + m_width / 2;
    m_aabb.max.y = m_position.y + m_height / 2;
}

bool Rectangle::intersect_visit ( IEntity* e )
{
    return false;
}

bool Rectangle::intersect ( Circle* circ )
{
    return false;
}

bool Rectangle::intersect ( Rectangle* rect )
{
    return false;

}



