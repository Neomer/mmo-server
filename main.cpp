#include <QCoreApplication>
#include <QDateTime>
#include "math/abstractmatrix.h"
#include "math/main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();




    qDebug("\nTime elapsed: %s", QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - t).toString("mm:ss.zzz").toLatin1().constData());
    return a.exec();
}
