#ifndef ABSTRAC2TVECTOR_H
#define ABSTRAC2TVECTOR_H

#include <string.h>

template < typename Type >
class Abstract2Vector
{
public:
    Abstract2Vector();
    Abstract2Vector(Type * value);

    inline void setX(Type value);
    inline void setY(Type value);

    inline Type x();
    inline Type y();

    /**
      Меняет местами Х и Y
     */
    void swap();



private:
    Type __values[2];
};

#endif // ABSTRACTVECTOR_H
