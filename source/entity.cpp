/*
 * This class represents any object that can be added to the world.
 * Entities can have shapes associated with them, as well as other attributes.
 */

#include "interfaces.h"
#include "entity.h"
#include "vec2.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL.h>

Circle::Circle ( vec2d position, double radius, vec2d velocity )
{
    m_position = position;
    m_radius = radius;
    m_velocity = velocity;
    calc_AABB();
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
    circleRGBA( renderer, m_position.x, m_position.y, m_radius, 0xFF, 0x00, 0xFF, 0xFF );
}
