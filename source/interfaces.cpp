#include "interfaces.h"

AABB IEntity::get_AABB()
{
    return m_aabb;
}

void IEntity::set_id ( int new_id )
{
    m_id = new_id;
}

void IEntity::update ( double dt )
{
    m_position.x = m_velocity.x * dt;
    m_position.y = m_velocity.y * dt;
    calc_AABB();
}

