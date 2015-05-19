#include <QCoreApplication>
#include <QDateTime>

#include "math/abstract3vector.h"
#include "math/main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();

    int b[] = {0, 5, 0};
    Abstract3Vector<int> v(true), v1(b, true);

    v.setX(1);
    v.print();
    v1.print();
    qDebug("%f", v1.angleTo(&v));

    for (int i = 0; i < 10000000; i++)
    {
        v1.angleTo(&v);
    }

    qDebug("\nTime elapsed: %s", QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - t).toString("mm:ss.zzz").toLatin1().constData());
    return a.exec();
}
