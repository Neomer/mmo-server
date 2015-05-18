#include "abstract2vector.h"



template<typename Type>
Abstract2Vector<Type>::Abstract2Vector()
{
    memset(__values, 0, 2);
}

template<typename Type>
Abstract2Vector<Type>::Abstract2Vector(Type *value)
{
    memcpy(__values, value, 2);
}

template<typename Type>
void Abstract2Vector<Type>::setX(Type value)
{
    __values[0] = value;
}

template<typename Type>
void Abstract2Vector<Type>::setY(Type value)
{
    __values[1] = value;
}

template<typename Type>
Type Abstract2Vector<Type>::x()
{
    return __values[0];
}

template<typename Type>
Type Abstract2Vector<Type>::y()
{
    return __values[1];
}

template<typename Type>
void Abstract2Vector<Type>::swap()
{
    Type tmp = __values[0];
    __values[0] = __values[1];
    __values[1] = tmp;
}
