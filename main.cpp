#include <QCoreApplication>
#include "math/abstractmatrix.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AbstractMatrix<int> * m = new AbstractMatrix<int>(1, 1);

    return a.exec();
}
