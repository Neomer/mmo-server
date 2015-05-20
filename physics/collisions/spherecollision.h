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
        this->__c.setRecalculate(false);
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
    CollisionSolver checkCollision(AbstractCollision *collision)
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

        CollisionSolver cs;
        cs.incident = false;
        return cs;
    }


private:
    float __r, __r2;
    Vector3f __c;

    CollisionSolver sphereToSphereCheck(SphereCollision * c)
    {
        CollisionSolver ret;

        Vector3f n1(this->center() * -1.0f + c->center()), n2 = n1, n;

        n1.setLength(this->radius());
        n1.print();
        n2.setLength(c->radius() * -1);
        n2.print();
        if (this->center().distanceTo(&(c->center())) <= this->radius() + c->radius())
        {
            ret.incident = true;
            n = n2 + n1;
            //n.setLength(n);
            ret.normal = n;
        }

        return ret;
    }
};

}

}

#endif // SPHERECOLLISION

