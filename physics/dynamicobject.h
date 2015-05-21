#ifndef DYNAMICOBJECT
#define DYNAMICOBJECT

#include "../math/abstract3vector.h"
#include "../core/sceneobject.h"
#include <QList>

namespace MMO_SERVER
{

namespace Physics
{

class DynamicObject
{
    friend class World;
    
public:
    DynamicObject(SceneObject * object)
    {
        this->__ob = object;
    }

    void applyForce(const Vector3f &force)
    {
        this->__f.append(force);
        this->__g.setXYZ(0.0f, 0.0f, 0.0f);
        
        for (int i = 0; i < this->__f.length(); i++)
        {
            this->__g += __f.at(i);
        }
    }
    
    void applyImpulse(const Vector3f &target, const Vector3f &impulse)
    {
        this->__a += impulse;
    }
    
    void tick(float period)
    {
        Vector3f a;
        
        a = this->__g * period;
        
        a.setXYZ(a.x() * this->__ws.x(), a.y() * this->__ws.y(), a.z() * this->__ws.z());
        
        this->__ob->location() += a;
    }

private:
    // Объект на сцене
    SceneObject * __ob;
    // Список глобальных сил
    QList<Vector3f> __f;
    // Скорость, Ускорение, Глобальная сила, Масштаб системы
    Vector3f __v, __a, __g, __ws;
    // Глобальное сопротивление среды
    float __gf;
};

}

}


#endif // DYNAMICOBJECT

