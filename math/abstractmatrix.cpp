#include "abstractmatrix.h"

#include "math/main.h"
#include <QString>

template<typename Type>
AbstractMatrix<Type>::AbstractMatrix()
{
    this->__count = 0;
    this->__r = 0;
    this->__c = 0;
    this->__t = false;
}

template<typename Type>
AbstractMatrix<Type>::AbstractMatrix(int r, int c)
{
    this->__count = r * c;
    __v = new Type[ this->__count ];
    this->__r = r;
    this->__c = c;
    this->__t = false;

    memset(__v, 0, __count * sizeof(Type));
}

template<typename Type>
AbstractMatrix<Type>::~AbstractMatrix()
{
    delete [] __v;
}

template<typename Type>
AbstractMatrix<Type> AbstractMatrix<Type>::createDiagonal(int d, Type value)
{
    AbstractMatrix<Type> m(d, d);
    for (int i = 0; i < d; i++)
    {
        m.set(i, i, value);
    }

    return m;
}

template<typename Type>
AbstractMatrix<Type> AbstractMatrix<Type>::createIdentity(int d)
{
    AbstractMatrix<Type> m(d, d);
    for (int i = 0; i < d; i++)
    {
        m.set(i, i, 1);
    }

    return m;
}

template<typename Type>
void AbstractMatrix<Type>::set(int r, int c, Type value)
{
    if ((!__MATH::between<int>(-1, __r, r, false)) || (!__MATH::between<int>(-1, __c, c, false)))
        return;

    this->__v[this->getIndex(r, c)] = value;
}

template<typename Type>
Type AbstractMatrix<Type>::get(int r, int c)
{
    if ((!__MATH::between<int>(-1, __r, r, false)) || (!__MATH::between<int>(-1, __c, c, false)))
        return 0;

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
void AbstractMatrix<Type>::add(float value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::add(double value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::add(long double value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::add(int value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::add(long long value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::multi(AbstractMatrix<Type> *matrix)
{

}

template<typename Type>
void AbstractMatrix<Type>::multi(float value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] * value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::multi(double value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] * value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::multi(long double value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] * value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::multi(int value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] * value;
    }
}

template<typename Type>
void AbstractMatrix<Type>::multi(long long value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] * value;
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
void AbstractMatrix<Type>::print()
{
    for (int r = 0; r < this->numRows(); r++)
    {
        for (int c = 0; c < this->numColumns(); c++)
        {
            printf("%d ", this->get(r, c));
        }
        printf("\n");
    }
}

template<typename Type>
int AbstractMatrix<Type>::getIndex(int r, int c)
{
    if (this->__t)
        return c * this->__r + r;
    else
        return r * this->__c + c;

}

// Pre-defined classes

// Integer types
template class AbstractMatrix<bool>;
template class AbstractMatrix<char>;
template class AbstractMatrix<short>;
template class AbstractMatrix<int>;
template class AbstractMatrix<long>;
template class AbstractMatrix<long long>;
template class AbstractMatrix<unsigned int>;
template class AbstractMatrix<unsigned long>;
template class AbstractMatrix<unsigned short>;
template class AbstractMatrix<unsigned char>;
template class AbstractMatrix<unsigned long long>;

//Floating-point types
template class AbstractMatrix<float>;
template class AbstractMatrix<double>;
//template class AbstractMatrix<long double>;
