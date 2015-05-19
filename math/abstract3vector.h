#ifndef ABSTRAC3TVECTOR_H
#define ABSTRAC3TVECTOR_H

#include "abstractmatrix.h"
#include <qmath.h>

namespace MMO_SERVER
{

template < typename Type >
class Abstract3Vector : public AbstractMatrix<Type>
{
public:
    /**
     * @brief
     * @param recalculate TRUE если нужно пересчитывать параметры вектора автоматически.
     * Выгодно если, координаты не меняются реже, чем используются параметры, аткие как длина
     */
    Abstract3Vector(bool recalculate = false) :
        AbstractMatrix<Type>(1, 3)
    {
        this->__l = this->__l2 = 0;
        this->__recalc = recalculate;
    }

    /**
     * @brief
     * @param value Массив со значениями
     * @param recalculate TRUE если нужно пересчитывать параметры вектора автоматически.
     * Выгодно если, координаты не меняются реже, чем используются параметры, аткие как длина
     */
    Abstract3Vector(Type * value, bool recalculate = false) :
        AbstractMatrix<Type>(1, 3, value)
    {
        this->__recalc = recalculate;
        if (this->__recalc) this->updateLength();
    }

    /**
     * @brief Abstract3Vector
     * @param x
     * @param y
     * @param z
     * @param recalculate TRUE если нужно пересчитывать параметры вектора автоматически.
     * Выгодно если, координаты не меняются реже, чем используются параметры, аткие как длина
     */
    Abstract3Vector(Type x, Type y, Type z, bool recalculate = false) :
        AbstractMatrix<Type>(1, 3)
    {
        this->__recalc = recalculate;
        setXYZ(x, y, z);
        if (this->__recalc) this->updateLength();
    }

    inline void setX(Type value)
    {
        this->set(0, 0, value);
        if (this->__recalc) this->updateLength();
    }

    inline void setY(Type value)
    {
        this->set(0, 1, value);
        if (this->__recalc) this->updateLength();
    }

    inline void setZ(Type value)
    {
        this->set(0, 2, value);
        if (this->__recalc) this->updateLength();
    }

    inline void setXYZ(Type * v)
    {
        this->set(0, 0, v[0]);
        this->set(0, 1, v[1]);
        this->set(0, 2, v[2]);
        if (this->__recalc) this->updateLength();
    }

    inline void setXYZ(Type x, Type y, Type z)
    {
        this->set(0, 0, x);
        this->set(0, 1, y);
        this->set(0, 2, z);
        if (this->__recalc) this->updateLength();
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

    /**
     * @brief Расстояние до точки
     * @param v
     * @return
     */
    float distanceTo(Abstract3Vector<Type> *v)
    {
        return qSqrt(this->x() * v->x() + this->y() * v->y() + this->z() * v->z() );
    }

    /**
     * @brief Квадрат расстояние до точки
     * @param v
     * @return
     */
    float distanceToSq(Abstract3Vector<Type> *v)
    {
        return this->x() * v->x() + this->y() * v->y() + this->z() * v->z();
    }

    /**
     * @brief Длина вектора
     * @return
     */
    float length()
    {
        if (this->__recalc)
            return __l;
        else
            return qSqrt(this->x() * this->x() + this->y() * this->y() + this->z() * this->z());
    }

    /**
     * @brief Квадрат длины вектора
     * @return
     */
    float lengthSq()
    {
        if (this->__recalc)
            return __l2;
        else
            return this->x() * this->x() + this->y() * this->y() + this->z() * this->z();
    }

    /**
     * @brief Угол между двумя векторами
     * @param v
     * @return
     */
    float angleTo(Abstract3Vector<Type> *v)
    {
        return qAcos(this->distanceToSq(v) / (this->length() * v->length()));
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

    void updateLength()
    {
        this->__l2 = this->x() * this->x() + this->y() * this->y() + this->z() * this->z();
        this->__l = qSqrt(this->__l2);
    }

    // Длина вектора, квадрат длины вектора
    float __l, __l2;
    // Флаг динамического пересчета параметров вектора
    bool __recalc;
};

}
#endif // ABSTRACT3VECTOR_H
