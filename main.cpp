#include <QCoreApplication>
#include <QDateTime>

#include "math/abstract3vector.h"
#include "math/main.h"
#include "math/colorrgba.h"
#include "core/sceneobject.h"
#include "physics/collisions/spherecollision.h"
#include "physics/world.h"
#include <QList>

using namespace MMO_SERVER;

#define ITERR_COUNT     5000000

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SceneObject so;
    
    Physics::SphereCollision c(Vector3f(0.0f, 0.0f, 0.0f), 5),
            c1(Vector3f(6.0f, 0.0f, 0.0f), 3);

    Physics::World w(Vector3f(0.01f, 0.01f, 0.01f));
    Physics::DynamicObject dyn(&so);

    w.addDynamicObject(&dyn);
    
    w.startSimulation();

    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();

    qDebug("\nTime elapsed: %s", QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - t).toString("mm:ss.zzz").toLatin1().constData());
    return a.exec();
}
