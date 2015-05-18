#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H

#include <string.h>

template < typename Type >
class AbstractMatrix
{
public:
    AbstractMatrix(int r, int c);
    ~AbstractMatrix();

    /**
     * @brief createDiagonal Статический. Возвращает диагональную матрицу.
     * @param d Размер матрицы
     * @param value Значение на диагонали
     * @return
     */
    static AbstractMatrix<Type> * createDiagonal(int d, Type value);

    /**
     * @brief createDiagonal Статический. Возвращает единичную матрицу.
     * @param d Размер матрицы
     * @return
     */
    static AbstractMatrix<Type> * createIdentity(int d);

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
     * @brief add Операция сложения
     * @param matrix
     */
    void add(AbstractMatrix<Type> * matrix);
    void add(float &value);
    void add(int &value);

    /**
     * @brief isSquare TRUE если матрица квадратная
     * @return
     */
    bool isSquare();

    /* Преобразования матрицы */
    /**
     * @brief transpose Транспонировать матрицу
     */
    void transpose();

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
