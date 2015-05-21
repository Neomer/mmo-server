#ifndef SPHERECOLLISION
#define SPHERECOLLISION

/**************************
 *
 *  Класс для работы с матрицами
 *
 * ****************************
 *
 *********************************************/

#include "abstractcollision.h"

namespace MMO_SERVER
{

namespace Physics
{

class SphereCollision : public AbstractCollision
{
public:
    SphereCollision() :
        AbstractCollision(CT_Sphere)
    {
        this->__c.setRecalculate(true);
        this->__r = 0;
        this->__r2 = 0;
    }

    SphereCollision(Vector3f center, float radius) :
        AbstractCollision(CT_Sphere)
    {
        this->__c = center;
        this->__c.setRecalculate(true);
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

    /***********************************************
    * Тесты:
    * 21.05.15:
    * Сравнение 2ух алгоритмов через Sqrt и через квадраты (5 млн итерраций)
    * 1. 2,105 - 2,107
    * 2. 1,976 - 1,986
    *
    *
    * ******************************************/
    CollisionSolver sphereToSphereCheck(SphereCollision * c)
    {
        CollisionSolver ret;


        float dsq = this->center().distanceToSq(&(c->center())),
                rs = this->radius() + c->radius();

        if (dsq < (rs) * (rs))
        {
            ret.incident = true;
            Vector3f n = (c->center() * -1) + this->center();
            n.setLength(rs - qSqrt(dsq));
            ret.normal = n;
        }
        else
        {
            ret.incident = false;
        }


        /*
        float dsq = this->center().distanceTo(&(c->center()));

        if (dsq < this->radius() + c->radius())
        {
            ret.incident = true;
            Vector3f n = (c->center() * -1) + this->center();
            n.setLength(this->radius() + c->radius() - dsq);
            ret.normal = n;
        }
        else
        {
            ret.incident = false;
        }
        */
        return ret;
    }
};

}

}

#endif // SPHERECOLLISION

