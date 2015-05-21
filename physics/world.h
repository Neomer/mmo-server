#ifndef WORLD
#define WORLD

#include <QTimer>
#include <QDateTime>
#include <QList>
#include "../math/abstract3vector.h"
#include "dynamicobject.h"

namespace MMO_SERVER
{

namespace Physics
{

class World : public QObject
{
    Q_OBJECT

public:
    World(const Vector3f &scale, float gravity = -9.81f, float friction = 0.01f)
    {
        this->__sc = scale;
        this->__g = Vector3f(0.0f, gravity, 0.0f, true);
        this->__t = new QTimer(this);
        this->__f = friction;
        connect(this->__t, SIGNAL(timeout()), this, SLOT(tick()));
    }

    ~World()
    {
        delete this->__t;
    }

    void startSimulation()
    {
        this->__t->setInterval(200);
        this->__t->start();
        this->__st = QDateTime::currentDateTime().toMSecsSinceEpoch();
    }
    
    void addDynamicObject(DynamicObject * object)
    {
        object->applyForce(this->__g);
        object->__gf = this->__f;
        object->__ws = this->__sc;
        this->__ob.append(object);
    }

private slots:
    void tick()
    {
        qint64 current_time = QDateTime::currentDateTime().toMSecsSinceEpoch();
        float delta_time = (current_time - this->__st) * 0.001;
        
        for (int i = 0; i < this->__ob.length(); i++)
        {
            this->__ob.at(i)->tick(delta_time);
        }

        this->__st = current_time;
    }

private:
    // Гравитация, Масштаб мира
    Vector3f __g, __sc;
    // Сопротивление среды
    float __f;
    // Таймер
    QTimer * __t;
    // Отсечка времени прошлого обновления системы
    qint64 __st;
    // Список тел в системе
    QList<DynamicObject *> __ob;
};

}

}


#endif // WORLD

