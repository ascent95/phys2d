/*
 * This class represents any object that can be added to the world.
 * Entities can have shapes associated with them, as well as other attributes.
 */

#include "entity.h"
#include "vec2.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>


void IEntity::set_id ( int new_id )
{
    m_id = new_id;
}

int IEntity::get_id()
{
    return m_id;
}

AABB IEntity::get_AABB()
{
    return m_aabb;
}

void IEntity::update ( double dt )
{
    m_position.x += m_velocity.x * dt;
    m_position.y += m_velocity.y * dt;
    calc_AABB();
}

bool AABBvsAABB( AABB a, AABB b )
{
    if( a.max.x < b.min.x || a.min.x > b.max.x ) return false;
    if( a.min.y > b.max.y || a.max.y < b.min.y ) return false;
    
    return true;
}

bool IEntity::intersect_broad ( IEntity* e )
{
    return AABBvsAABB( m_aabb, e->m_aabb );
}

void IEntity::set_colour ( Uint32 colour )
{
    m_colour = colour;
}



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
        /*
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
        */
        
        resolve_collision( normal, approach, circ );
        return true;
    }
    return false;
}

Rectangle::Rectangle ( vec2d position, double width, double height, vec2d velocity ) : m_width( width ), m_height( height )
{
    m_position = position;
    m_velocity = velocity;
    
    m_material.restitution = 1;
    
    m_mass_data.mass = width * height;
    m_mass_data.inv_mass = 1 / m_mass_data.mass;
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
    return e->intersect( this );
}

bool Rectangle::intersect ( Circle* circ )
{
    return false;
}

bool Rectangle::intersect ( Rectangle* rect )
{
    vec2d AtoB = rect->m_position - m_position;
    double a_half = ( m_aabb.max.x - m_aabb.min.x ) / 2;
    double b_half = ( rect->m_aabb.max.x - rect->m_aabb.min.x ) / 2;
    
    double x_overlap = a_half + b_half - abs( AtoB.x );
    
    if( x_overlap > 0 )
    {
        //There is an x overlap
        a_half = ( m_aabb.max.y - m_aabb.min.y ) / 2;
        b_half = ( rect->m_aabb.max.y - rect->m_aabb.min.y ) / 2;
        
        double y_overlap = a_half + b_half - abs( AtoB.y );
        if( y_overlap > 0 )
        {
            //There is a collision
            
            vec2d normal ( 0, 0 );
            if( y_overlap > x_overlap )
            {
                normal.x = AtoB.x;
            }
            else
            {
                normal.y = AtoB.y;
            }
            normal.normalize();
            vec2d approach = rect->m_velocity - m_velocity;
            
            resolve_collision( normal, approach, rect );
        }
    }
    return false;

}


void IEntity::resolve_collision ( vec2d normal, vec2d approach, IEntity* collider )
{
    float vel_along_normal = vec2d::dot( approach, normal );
    
    if( vel_along_normal > 0 ) return; //Already separating.
    
    double max_restitution = std::max( m_material.restitution, collider->m_material.restitution );
    double j = ( 1 + max_restitution ) * vel_along_normal / ( m_mass_data.inv_mass + collider->m_mass_data.inv_mass );
    m_velocity.x += j * normal.x * m_mass_data.inv_mass;
    m_velocity.y += j * normal.y * m_mass_data.inv_mass;
    collider->m_velocity.x -= j * normal.x * collider->m_mass_data.inv_mass;
    collider->m_velocity.y -= j * normal.y * collider->m_mass_data.inv_mass;
}

