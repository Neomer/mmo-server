#ifndef SPHERECOLLISION
#define SPHERECOLLISION

#include "abstractcollision.h"

namespace MMO_SERVER
{

namespace Physics
{

class SphereCollision : public AbstractCollision
{
public:
    SphereCollision(Vector3f center, float radius) :
        AbstractCollision(CT_Sphere)
    {
        this->__c = center;
        this->__r = radius;
        this->__r2 = radius * radius;
    }

    inline float radius()
    {
        return this->__r;
    }

    inline float radiusSq()
    {
        return this->__r2;
    }

    inline Vector3f& center()
    {
        return this->__c;
    }

    // AbstractCollision interface
    bool checkCollision(AbstractCollision *collision)
    {
        switch (collision->type())
        {
            case CT_Sphere:
                return sphereToSphereCheck((SphereCollision *)collision);
                break;

            case CT_Box:
                break;

            case CT_Capsule:
                break;
        }
    }


private:
    float __r, __r2;
    Vector3f __c;

    bool sphereToSphereCheck(SphereCollision * c)
    {
        return this->center().distanceToSq(&(c->center())) <= this->radiusSq() + c->radiusSq();
    }
};

}

}

#endif // SPHERECOLLISION

