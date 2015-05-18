#include "abstractmatrix.h"

template<typename Type>
AbstractMatrix<Type>::AbstractMatrix(int r, int c)
{
    this->__count = r * c;
    __v = new Type[ this->__count ];
    this->__r = r;
    this->__c = c;

    memset(__v, 0, __count);
}

template<typename Type>
AbstractMatrix<Type>::~AbstractMatrix()
{
    delete [] __v;
}

template<typename Type>
AbstractMatrix<Type> *AbstractMatrix<Type>::createDiagonal(int d, Type value)
{
    AbstractMatrix<Type> * m = new AbstractMatrix<Type>(d, d);
    for (int i = 0; i < d; i++)
    {
        m->set(i, i, value);
    }

    return m;
}

template<typename Type>
AbstractMatrix<Type> *AbstractMatrix<Type>::createIdentity(int d)
{
    AbstractMatrix<Type> * m = new AbstractMatrix<Type>(d, d);
    for (int i = 0; i < d; i++)
    {
        m->set(i, i, 1);
    }

    return m;
}

template<typename Type>
void AbstractMatrix<Type>::set(int r, int c, Type value)
{
    if (((r > __r) || (r < 0)) || ((c > __c) || (c < 0)))
        return;

    this->__v[this->getIndex(r, c)] = value;
}

template<typename Type>
Type AbstractMatrix<Type>::get(int r, int c)
{
    if (((r > __r) || (r < 0)) || ((c > __c) || (c < 0)))
        return;

    return this->__v[this->getIndex(r, c)];
}

template<typename Type>
int AbstractMatrix<Type>::numColumns()
{
    return this->__c;
}

template<typename Type>
int AbstractMatrix<Type>::numRows()
{
    return this->__r;
}

template<typename Type>
void AbstractMatrix<Type>::add(AbstractMatrix<Type> *matrix)
{
    if ((this->__r != matrix->numRows())||(this->__c != matrix->numColumns()))
        return;

    for (int r = 0; r < this->__r; r++)
    {
        for (int c = 0; c < this->__c; c++)
        {
            this->set(r, c, this->get(r, c) + matrix->get(r, c));
        }
    }
}

template<typename Type>
void AbstractMatrix<Type>::add(float &value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::add(int &value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
bool AbstractMatrix<Type>::isSquare()
{
    return this->__r == this->__c;
}

template<typename Type>
void AbstractMatrix<Type>::transpose()
{
    this->__t = !this->__t;
}

template<typename Type>
int AbstractMatrix<Type>::getIndex(int r, int c)
{
    if (this->__t)
        return c * this->__r + r;
    else
        return r * this->__c + c;

}
