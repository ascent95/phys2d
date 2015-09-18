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
#include <assert.h>


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



Circle::Circle ( vec2d position, double radius, double density, vec2d velocity )
{
    m_position = position;
    m_radius = radius;
    m_velocity = velocity;
    calc_AABB();
    
    m_material.density = density;
    m_material.restitution = 1;
    
    assert( m_material.density || m_velocity.length() == 0 );
    
    calc_mass();
}

void Circle::calc_AABB()
{
    m_aabb.min.x = m_position.x - m_radius;
    m_aabb.min.y = m_position.y - m_radius;
    m_aabb.max.x = m_position.x + m_radius;
    m_aabb.max.y = m_position.y + m_radius;
}

void Circle::calc_mass()
{
    m_mass_data.mass = M_PI * m_radius * m_radius * m_material.density;
    if( m_mass_data.mass )
    {
        m_mass_data.inv_mass = 1 / m_mass_data.mass;
    }
    else
    {
        m_mass_data.inv_mass = 0;
    }
    
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
    circle_vs_rectangle( this, rect );
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
        
        resolve_collision( normal, approach, circ );
        return true;
    }
    return false;
}

double Circle::get_radius()
{
    return m_radius;
}


Rectangle::Rectangle ( vec2d position, double width, double height, double density, vec2d velocity ) : m_width( width ), m_height( height )
{
    m_position = position;
    m_velocity = velocity;
    calc_AABB();
    
    m_material.density = density;
    m_material.restitution = 1;
    
    calc_mass();
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

void Rectangle::calc_mass()
{
    m_mass_data.mass =  m_width * m_height * m_material.density;
    if( m_mass_data.mass )
    {
        m_mass_data.inv_mass = 1 / m_mass_data.mass;
    }
    else
    {
        m_mass_data.inv_mass = 0; //Infinite mass is represented by 0 mass and inv_mass
    }
}


bool Rectangle::intersect_visit ( IEntity* e )
{
    return e->intersect( this );
}

bool Rectangle::intersect ( Circle* circ )
{
    circle_vs_rectangle( circ, this );
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

bool clamp_to_edge( vec2d *v, AABB range )
{
    double half_x = ( range.max.x - range.min.x ) / 2;
    double half_y = ( range.max.y - range.min.y ) / 2;
    bool outside = false; 
    
    if( abs( v->x - range.min.x - half_x ) > half_x || abs( v->y - range.min.y - half_y ) > half_y )
    {
        outside = true;
        if( v->x < range.min.x ) v->x = range.min.x;
        else if( v->x > range.max.x ) v->x = range.max.x;
        if( v->y < range.min.y ) v->y = range.min.y;
        else if( v->y > range.max.y ) v->y = range.max.y;
    }
    else
    {
        if( v->y - range.min.y > v->x - range.min.x )
        {
            if( v->y - range.min.y > -( v->x - range.min.x ) + half_y * 2 )
            {
                v->y = range.max.y;
            }
            else
            {
                v->x = range.min.x;
            }
        }
        else
        {
            if( v->y - range.min.y > -( v->x - range.min.x ) + half_y * 2  )
            {
                v->x = range.max.x;
            }
            else
            {
                v->y = range.min.y;
            }
        }
    }
    return outside;
}

void IEntity::circle_vs_rectangle( Circle *circ, Rectangle *rect )
{
    vec2d closest = circ->m_position;
    
    bool outside = clamp_to_edge( &closest, rect->m_aabb );
    double penetration = circ->get_radius() - ( closest - circ->m_position ).length();
    
    if( penetration > 0 )
    {
        vec2d normal = ( closest - circ->m_position ).normalize();
        if( !outside ) normal *= -1;
        
        vec2d approach = rect->m_velocity - circ->m_velocity;
        
        circ->resolve_collision( normal, approach, rect );
    }
}
