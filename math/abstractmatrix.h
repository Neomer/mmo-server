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

template < typename Type >
class AbstractMatrix
{
    friend class AbstractMatrix;

public:
    AbstractMatrix();
    AbstractMatrix(int r, int c);
    AbstractMatrix(int r, int c, Type * data);
    ~AbstractMatrix();

    /**
     * @brief createDiagonal Статический. Возвращает диагональную матрицу.
     * @param d Размер матрицы
     * @param value Значение на диагонали
     * @return
     */
    static AbstractMatrix<Type> createDiagonal(int d, Type value);

    /**
     * @brief createDiagonal Статический. Возвращает единичную матрицу.
     * @param d Размер матрицы
     * @return
     */
    static AbstractMatrix<Type> createIdentity(int d);

    void set(int r, int c, Type value);
    Type get(int r, int c);

    /**
     * @brief numColumns Количество столбцов
     * @return
     */
    inline int numColumns();

    /**
     * @brief numRows Количество строк
     * @return
     */
    inline int numRows();

    /**
     * @brief numRows Количество элементов матрицы
     * @return
     */
    inline int numElements();

    /**
     * @brief add Операция сложения
     * @param matrix
     */
    void add(AbstractMatrix<Type> * matrix);
    void add(Type value);

    /**
     * @brief add Операция умножения
     * @param matrix
     */
    AbstractMatrix<Type> multi(AbstractMatrix<Type> * matrix);
    void multi(Type value);

    /**
     * @brief isSquare TRUE если матрица квадратная
     * @return
     */
    bool isSquare();

    /**
     * @brief isSquare TRUE если матрица matrix равна текущей
     * @return
     */
    bool isEqual(AbstractMatrix<Type> * matrix);

    /* Преобразования матрицы */
    /**
     * @brief transpose Транспонировать матрицу
     */
    void transpose();

    void print();

    bool operator == (AbstractMatrix<Type> &m);
    void operator += (Type v);
    void operator += (AbstractMatrix<Type> v);
    void operator += (AbstractMatrix<Type> * v);

    void operator *= (Type v);
    void operator *= (AbstractMatrix<Type> v);
    void operator *= (AbstractMatrix<Type> * v);

private:
    inline int getIndex(int r, int c);

    // Значения матрицы
    Type * __v;
    // Кол-во строк, столбцов, элементов
    int __r, __c, __count;
    // Транспонирование
    bool __t;
};

#endif // ABSTRACTMATRIX_H
