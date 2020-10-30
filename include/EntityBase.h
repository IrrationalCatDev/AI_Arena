#include "Types.h"

class EntityBase
{
public:
    void Update(float elapsedTime);
    const Vec2& GetPosition();
    void SetPosition(const Vec2& newPos);
    const Vec2& GetVelocity();
    void SetVelocity(const Vec2& newVel);
    bool IsAlive();
    void SetAlive(bool setAlive);
private:
    bool bAlive;
    Vec2 position;
    Vec2 velocity;
};

class EntityPool
{
public:
    EntityPool() = default;
    ~EntityPool();

    void Insert(EntityBase* pNewEntity);
    void Remove(EntityBase* pRemovedEntity);
private:
    vector<EntityBase*> m_vEntities;
};