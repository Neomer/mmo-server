#ifndef MAIN
#define MAIN

namespace __MATH
{
    template<typename T>
    /**
     * @brief __between TRUE, если значение a <= c <= b ( a < c < b при eq = false)
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
}

#endif // MAIN

