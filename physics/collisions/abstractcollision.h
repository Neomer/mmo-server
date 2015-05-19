#ifndef ABSTRACTCOLLISION
#define ABSTRACTCOLLISION

#include "../../math/main.h"
#include "../../math/abstract3vector.h"

namespace MMO_SERVER
{

namespace Physics
{

enum CollisionType
{
    CT_Sphere,
    CT_Box,
    CT_Capsule
};

class AbstractCollision
{
public:
    AbstractCollision(CollisionType type)
    {
        __type = type;
    }

    virtual bool checkCollision(AbstractCollision * collision) = 0;

    CollisionType type()
    {
        return __type;
    }

private:
    CollisionType __type;
};

}

}

#endif // ABSTRACTCOLLISION

