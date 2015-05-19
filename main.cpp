#include <QCoreApplication>
#include <QDateTime>

#include "math/abstract3vector.h"
#include "math/main.h"
#include "math/colorrgba.h"

using namespace MMO_SERVER;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();




    qDebug("\nTime elapsed: %s", QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - t).toString("mm:ss.zzz").toLatin1().constData());
    return a.exec();
}
