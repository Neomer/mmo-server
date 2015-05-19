#include <QCoreApplication>
#include <QDateTime>
#include "math/abstractmatrix.h"
#include "math/main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qint64 t = QDateTime::currentDateTime().toMSecsSinceEpoch();

    AbstractMatrix<float> m = AbstractMatrix<float>::createIdentity(3);

    for (long long i = 0; i < 100000000; i++)
    {
        m.multi(1.0f);
    }

    qDebug("%s", QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - t).toString("mm:ss.zzz").toLatin1().constData());

    return a.exec();
}
