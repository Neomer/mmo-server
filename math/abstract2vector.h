#ifndef ABSTRAC2TVECTOR_H
#define ABSTRAC2TVECTOR_H

#include "abstractmatrix.h"

namespace MMO_SERVER
{

template < typename Type >
class Abstract2Vector : public AbstractMatrix<Type>
{
public:
    Abstract2Vector() :
        AbstractMatrix<Type>(1, 2)
    {

    }

    Abstract2Vector(Type * value) :
        AbstractMatrix<Type>(1, 2, value)
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

    inline Type x()
    {
        this->get(0, 0);
    }

    inline Type y()
    {
        this->get(0, 1);
    }

    /**
      Меняет местами Х и Y
     */
    void swap()
    {
        Type tmp = this->get(0, 0);
        this->set(0, 0, this->get(0, 1));
        this->set(0, 1, tmp);
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

}
#endif // ABSTRACTVECTOR_H
