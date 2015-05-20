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

struct CollisionSolver
{
    Vector3f normal;
    bool incident;
};

class AbstractCollision
{
public:
    AbstractCollision(CollisionType type)
    {
        __type = type;
    }

    virtual CollisionSolver checkCollision(AbstractCollision * collision) = 0;
    //virtual bool resolveCollision(AbstractCollision * collision) = 0;

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

