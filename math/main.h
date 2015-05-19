#ifndef MAIN
#define MAIN

namespace __MATH
{
    #define _PI         3.1415926535897932384626433832795
    #define _PI_2       1.5707963267948966192313216916398
    #define _2PI        6.283185307179586476925286766559
    #define _PI_180     0.01745329251994329576923690768489
    #define _180_PI     57.295779513082320876798154814105


    template<typename T>
    /**
     * @brief TRUE, если значение a <= c <= b ( a < c < b при eq = false)
     * @param a MIN
     * @param b MAX
     * @param c TEST
     * @param eq
     * @return
     */
    inline bool between(T a, T b, T c, bool eq = true)
    {
        if (eq)
            return (c >= a) && (c <= b);
        else
            return (c > a) && (c < b);
    }

    template<typename T>
    /**
     * @brief Функция перевода радиан в градусы
     * @param v Значение в радианах
     * @return
     */
    inline float rad2grad(T v)
    {
        return v * _180_PI;
    }

    template<typename T>
    /**
     * @brief Функция перевода градусов в радианы
     * @param v Значение в радианах
     * @return
     */
    inline float grad2rad(T v)
    {
        return v * _PI_180;
    }
}

#endif // MAIN

