#ifndef ABSTRAC2TVECTOR_H
#define ABSTRAC2TVECTOR_H


template < typename Type >
class Abstract2Vector
{
public:
    Abstract2Vector()
    {
        memset(__values, 0, 2);
    }

    Abstract2Vector(Type * value)
    {
        memcpy(__values, value, 2);
    }

    void setX(Type value)
    {
        __values[0] = value;
    }

    void setY(Type value)
    {
        __values[0] = value;
    }

    Type x()
    {
        return __values[0];
    }

    Type y()
    {
        return __values[1];
    }

    /**
      Меняет местами Х и Y
     */
    void swap()
    {
        Type tmp = __values[0];
        __values[0] = __values[1];
        __values[1] = tmp;
    }



private:
    Type __values[2];
};

#endif // ABSTRACTVECTOR_H
