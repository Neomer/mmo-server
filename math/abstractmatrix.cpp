#include "abstractmatrix.h"

template<typename Type>
AbstractMatrix<Type>::AbstractMatrix(int r, int c)
{
    __v = new Type[ r * c ];
    this->__r = r;
    this->__c = c;
}

template<typename Type>
AbstractMatrix<Type>::~AbstractMatrix()
{
    delete __v;
}

template<typename Type>
void AbstractMatrix<Type>::setValue(int r, int c, Type value)
{
    if (((r > __r) || (r < 0)) || ((c > __c) || (c < 0)))
        return;

    this->__v[c * this->__r + r] = value;
}
