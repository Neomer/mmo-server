#include <QCoreApplication>
#include <QDateTime>

#include "math/abstract3vector.h"
#include "math/main.h"
#include "math/colorrgba.h"
#include "core/sceneobject.h"
#include "physics/collisions/spherecollision.h"

using namespace MMO_SERVER;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();

    Physics::SphereCollision c(Vector3f(0, 0, 0), 5),
            c1(Vector3f(6, 0, 0), 3);

    qDebug("%d", c.checkCollision(&c1));

    qDebug("\nTime elapsed: %s", QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - t).toString("mm:ss.zzz").toLatin1().constData());
    return a.exec();
}
