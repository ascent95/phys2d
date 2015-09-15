#include "interfaces.h"
#include "collision.h"

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

bool IEntity::intersect_broad ( IEntity* e )
{
    return AABBvsAABB( m_aabb, e->m_aabb );
}
