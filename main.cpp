#include <QCoreApplication>
#include <QDateTime>

#include "math/abstract2vector.h"
#include "math/main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();

    int b[] = {0, 5};
    Abstract2Vector<int> v, v1(b);

    v.print();
    v1.print();

    qDebug("\nTime elapsed: %s", QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - t).toString("mm:ss.zzz").toLatin1().constData());
    return a.exec();
}
