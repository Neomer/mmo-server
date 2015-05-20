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
    Abstract3Vector(const AbstractMatrix<Type> &matrix, bool recalculate = false) :
        AbstractMatrix<Type>(matrix)
    {
        this->__recalc = recalculate;
        if (recalculate) this->updateLength();
    }

    Abstract3Vector(const Abstract3Vector<Type> &other) :
        AbstractMatrix<Type>(other)
    {
        this->__recalc = other.__recalc;
        this->__l = other.__l;
        this->__l2 = other.__l2;
    }

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

    /**
     * @brief Создает сонаправленный вектор указанной длины
     * @param directionTo базовый вектор
     * @param length Необходимая длина
     * @param recalculate
     */
    Abstract3Vector(Abstract3Vector<Type> directionTo, float length, bool recalculate = false) :
        AbstractMatrix<Type>(1, 3)
    {
        this->__recalc = recalculate;
        float delta = length / directionTo.length();
        this->setXYZ(directionTo.x() * delta, directionTo.y() * delta, directionTo.z() * delta);
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
        return this->get(0, 0);
    }

    inline Type y()
    {
        return this->get(0, 1);
    }

    inline Type z()
    {
        return this->get(0, 2);
    }

    /**
     * @brief Расстояние до точки
     * @param v
     * @return
     */
    float distanceTo(Abstract3Vector<Type> *v)
    {
        return qSqrt(qAbs(this->x() * v->x() + this->y() * v->y() + this->z() * v->z()));
    }

    /**
     * @brief Квадрат расстояние до точки
     * @param v
     * @return
     */
    float distanceToSq(Abstract3Vector<Type> *v)
    {
        return qAbs(this->x() * v->x() + this->y() * v->y() + this->z() * v->z());
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

    /**
     * @brief Изменяет длину вектора не меняя направление
     * @param length Новая длина
     */
    void setLength(float length)
    {
        float delta;
        if (this->__recalc)
            delta = length / this->__l;
        else
            delta = length / this->length();
        setXYZ(this->x() * delta, this->y() * delta, this->z() * delta);
        if (this->__recalc) this->updateLength();
    }

    Abstract3Vector<Type> operator * (Type value)
    {
        return Abstract3Vector<Type>(AbstractMatrix<Type>::operator *(value));
    }

    void operator = (const AbstractMatrix<Type> &v)
    {
        this->copy(v);
    }

    void setRecalculate(bool v)
    {
        this->__recalc = v;
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

typedef Abstract3Vector<float>      Vector3f;
typedef Abstract3Vector<int>        Vector3i;

}
#endif // ABSTRACT3VECTOR_H
