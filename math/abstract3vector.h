#ifndef ABSTRAC3TVECTOR_H
#define ABSTRAC3TVECTOR_H

#include "abstractmatrix.h"

template < typename Type >
class Abstract3Vector : public AbstractMatrix<Type>
{
public:
    Abstract3Vector() :
        AbstractMatrix<Type>(1, 3)
    {

    }

    Abstract3Vector(Type * value) :
        AbstractMatrix<Type>(1, 3, value)
    {
    }

    inline void setX(Type value)
    {
        this->set(0, 0, value);
    }

    inline void setY(Type value)
    {
        this->set(0, 1, value);
    }

    inline void setZ(Type value)
    {
        this->set(0, 2, value);
    }

    inline Type x()
    {
        this->get(0, 0);
    }

    inline Type y()
    {
        this->get(0, 1);
    }

    inline Type z()
    {
        this->get(0, 2);
    }

private:
    void set(int r, int c, Type value)
    {
        AbstractMatrix<Type>::set(r, c, value);
    }

    Type get(int r, int c)
    {
        return AbstractMatrix<Type>::get(r, c);
    }
};

#endif // ABSTRACT3VECTOR_H
