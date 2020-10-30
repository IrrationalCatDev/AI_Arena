#include "EntityBase.h"

void EntityBase::Update(float elapsedTime)
{
    if (bAlive)
    {
        position += (velocity * elapsedTime);
    }
}

const Vec2& EntityBase::GetPosition()
{
    return position;
}

void EntityBase::SetPosition(const Vec2& newPos)
{
    position = newPos;
}

const Vec2& EntityBase::GetVelocity()
{
    return velocity;
}

void EntityBase::SetVelocity(const Vec2& newVel)
{
    velocity = newVel;
}

bool EntityBase::IsAlive()
{
    return bAlive;
}

void EntityBase::SetAlive(bool setAlive)
{
    bAlive = setAlive;
}

EntityPool::~EntityPool()
{
    for(auto& entity : m_vEntities)
    {
        delete entity;
    }
    m_vEntities.clear();
}

void EntityPool::Insert(EntityBase* pNewEntity)
{
    bool bAdded = false;
    for(auto& entity : m_vEntities)
    {
        if(entity = nullptr)
        {
            bAdded = true;
            entity = pNewEntity;
        }
    }
    if(!bAdded)
    {
        m_vEntities.push_back(pNewEntity);
    }
}
void EntityPool::Remove(EntityBase* pRemovedEntity)
{
    for(auto& entity : m_vEntities)
    {
        if(entity == pRemovedEntity)
        {
            delete entity;
            entity = nullptr;
        }
    }
    
}
