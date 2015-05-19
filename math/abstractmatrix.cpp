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
AbstractMatrix<Type>::AbstractMatrix(int r, int c, Type *data)
{
    this->__count = r * c;
    __v = new Type[ this->__count ];
    this->__r = r;
    this->__c = c;
    this->__t = false;

    memcpy(__v, data, __count * sizeof(Type));
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
int AbstractMatrix<Type>::numElements()
{
    return this->__count;
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
void AbstractMatrix<Type>::add(Type value)
{
    for (int i = 0; i < this->__count; i++)
    {
        this->__v[i] = this->__v[i] + value;
    }
}

template<typename Type>
AbstractMatrix<Type> AbstractMatrix<Type>::multi(AbstractMatrix<Type> *matrix)
{
    AbstractMatrix<Type> m(this->numRows(), matrix->numColumns());

    if ((this->numColumns() != matrix->numRows()))
        return m;

    for (int c = 0; c < this->numColumns(); c++)
    {
        for (int r = 0; r < this->numRows(); r++)
        {
            Type z = 0;
            for (int c1 = 0; c1 < this->numColumns(); c1++)
            {
                z += this->get(r, c1) * matrix->get(c1, c);
            }
            m.set(r, c, z);
        }
    }

    return m;
}

template<typename Type>
void AbstractMatrix<Type>::multi(Type value)
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
bool AbstractMatrix<Type>::isEqual(AbstractMatrix<Type> *matrix)
{
    if ((this->numRows() != matrix->numRows())||(this->numColumns() != matrix->numColumns()))
        return false;

    for (int r = 0; r < this->numRows(); r++ )
    {
        for (int c = 0; c < this->numColumns(); c++ )
        {
            if (this->get(r, c) != matrix->get(r, c))
                return false;
        }
    }

    return true;
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
bool AbstractMatrix<Type>::operator ==(AbstractMatrix<Type> &m)
{
    if ((m.numRows() != this->numRows())||(m.numColumns() != this->numColumns()))
        return false;

    for (int r = 0; r < m.numRows(); r++ )
    {
        for (int c = 0; c < m.numColumns(); c++ )
        {
            if (m.get(r, c) != this->get(r, c))
                return false;
        }
    }

    return true;
}

template<typename Type>
void AbstractMatrix<Type>::operator +=(Type v)
{
    this->add(v);
}

template<typename Type>
void AbstractMatrix<Type>::operator +=(AbstractMatrix<Type> *v)
{
    this->add(v);
}

template<typename Type>
void AbstractMatrix<Type>::operator *=(Type v)
{
    this->multi(v);
}

template<typename Type>
void AbstractMatrix<Type>::operator *=(AbstractMatrix<Type> v)
{
    this->multi(&v);
}

template<typename Type>
void AbstractMatrix<Type>::operator *=(AbstractMatrix<Type> *v)
{
    this->multi(v);
}

template<typename Type>
void AbstractMatrix<Type>::operator +=(AbstractMatrix<Type> v)
{
    this->add(&v);
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
