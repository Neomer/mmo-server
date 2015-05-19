#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H

/**************************
 *
 *  Класс для работы с матрицами
 *
 * ****************************
 *
 * Тесты:
 * 19.05.15:
 * Умножение матрицы 3х3 на число за 100 млн итерраций
 * 1. Умножение на целое число за 2.5 сек.
 * 2. Умножение на вещественное число за 2.5 сек.
 * 3. Умножение на матрицу (1 млн) 1.25 сек
 *********************************************/

#include <string.h>
#include <stdio.h>
#include "math/main.h"
#include <stdlib.h>
#include <typeinfo>
#include <QString>

namespace MMO_SERVER
{

template < typename Type >
class AbstractMatrix
{
public:

    AbstractMatrix()
    {
        this->__count = 0;
        this->__r = 0;
        this->__c = 0;
        this->__t = false;
    }

    AbstractMatrix(int r, int c)
    {
        this->__count = r * c;
        __v = new Type[ this->__count ];
        this->__r = r;
        this->__c = c;
        this->__t = false;

        memset(__v, 0, __count * sizeof(Type));
    }

    AbstractMatrix(int r, int c, Type * data)
    {
        this->__count = r * c;
        __v = new Type[ this->__count ];
        this->__r = r;
        this->__c = c;
        this->__t = false;

        memcpy(__v, data, __count * sizeof(Type));
    }

    ~AbstractMatrix()
    {
        delete [] __v;
    }

    /**
     * @brief Статический. Возвращает диагональную матрицу.
     * @param d Размер матрицы
     * @param value Значение на диагонали
     * @return
     */
    static AbstractMatrix<Type> createDiagonal(int d, Type value)
    {
        AbstractMatrix<Type> m(d, d);
        for (int i = 0; i < d; i++)
        {
            m.set(i, i, value);
        }

        return m;
    }

    /**
     * @brief Статический. Возвращает единичную матрицу.
     * @param d Размер матрицы
     * @return
     */
    static AbstractMatrix<Type> createIdentity(int d)
    {
        AbstractMatrix<Type> m(d, d);
        for (int i = 0; i < d; i++)
        {
            m.set(i, i, 1);
        }

        return m;
    }

    void set(int r, int c, Type value)
    {
        if ((!__MATH::between<int>(-1, __r, r, false)) || (!__MATH::between<int>(-1, __c, c, false)))
            return;

        this->__v[this->getIndex(r, c)] = value;
    }

    Type get(int r, int c)
    {
        if ((!__MATH::between<int>(-1, __r, r, false)) || (!__MATH::between<int>(-1, __c, c, false)))
            return 0;

        return this->__v[this->getIndex(r, c)];
    }

    /**
     * @brief Количество столбцов
     * @return
     */
    inline int numColumns()
    {
        return this->__c;
    }

    /**
     * @brief Количество строк
     * @return
     */
    inline int numRows()
    {
        return this->__r;
    }

    /**
     * @brief Количество элементов матрицы
     * @return
     */
    inline int numElements()
    {
        return this->__count;
    }

    /**
     * @brief Операция сложения матриц
     * @param matrix
     */
    void add(AbstractMatrix<Type> * matrix)
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

    /**
     * @brief Операция сложения с числом
     * @param matrix
     */
    void add(Type value)
    {
        for (int i = 0; i < this->__count; i++)
        {
            this->__v[i] = this->__v[i] + value;
        }
    }

    /**
     * @brief Операция умножения мариц
     * @param matrix
     */
    AbstractMatrix<Type> multi(AbstractMatrix<Type> * matrix)
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

    /**
     * @brief Операция умножения с числом
     * @param matrix
     */
    void multi(Type value)
    {
        for (int i = 0; i < this->__count; i++)
        {
            this->__v[i] = this->__v[i] * value;
        }
    }

    /**
     * @brief TRUE если матрица квадратная
     * @return
     */
    bool isSquare()
    {
        return this->__r == this->__c;
    }

    /**
     * @brief TRUE если матрица matrix равна текущей
     * @return
     */
    bool isEqual(AbstractMatrix<Type> * matrix)
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

    /* Преобразования матрицы */
    /**
     * @brief Транспонировать матрицу
     */
    void transpose()
    {
        this->__t = !this->__t;
    }

    /**
     * @brief Распечатывает значения матрицы
     */
    void print()
    {
        QString fmt("%");
        fmt.append(typeid(Type).name()).append(" ");
        for (int r = 0; r < this->numRows(); r++)
        {
            for (int c = 0; c < this->numColumns(); c++)
            {
                printf(fmt.toLatin1().constData(), this->get(r, c));
            }
            printf("\n");
        }
    }

    bool operator == (AbstractMatrix<Type> m)
    {
        return this->isEqual(&m);
    }

    void operator += (Type v)
    {
        this->add(v);
    }

    void operator += (AbstractMatrix<Type> v)
    {
        this->add(&v);
    }

    void operator += (AbstractMatrix<Type> * v)
    {
        this->add(v);
    }


    void operator *= (Type v)
    {
        this->multi(v);
    }

    void operator *= (AbstractMatrix<Type> v)
    {
        this->multi(&v);
    }

    void operator *= (AbstractMatrix<Type> * v)
    {
        this->multi(v);
    }

    void operator = (AbstractMatrix<Type> &v)
    {
        memcpy(this->__v, v.__v, v.numElements() * sizeof(Type));
        this->__r = v.__r;
        this->__c = v.__c;
        this->__count = v.__count;
        this->__t = v.__t;
    }

private:
    inline int getIndex(int r, int c)
    {
        if (this->__t)
            return c * this->__r + r;
        else
            return r * this->__c + c;

    }

    // Значения матрицы
    Type * __v;
    // Кол-во строк, столбцов, элементов
    int __r, __c, __count;
    // Транспонирование
    bool __t;
};

}
#endif // ABSTRACTMATRIX_H
