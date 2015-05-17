#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H

#include <string.h>

template < typename Type >
class AbstractMatrix
{
public:
    AbstractMatrix(int r, int c);
    ~AbstractMatrix();

    void setValue(int r, int c, Type value);

private:
    Type * __v;
    int __r, __c;
};

#endif // ABSTRACTMATRIX_H
