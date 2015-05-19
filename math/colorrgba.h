#ifndef COLORRGBA
#define COLORRGBA

#include <qmath.h>
#include "math/abstractmatrix.h"

namespace MMO_SERVER
{

class ColorRGBAf : public AbstractMatrix<float>
{
public:
    ColorRGBAf() :
        AbstractMatrix<float>(1, 4)
    {
    }

    ColorRGBAf(float * value) :
        AbstractMatrix<float>(1, 4, value)
    {
    }

    ColorRGBAf(float r, float g, float b, float a = 1.0f) :
        AbstractMatrix<float>(1, 4)
    {
        setRGBA(r, g, b, a);
    }

    inline void setR(float value)
    {
        set(0, 0, value);
    }

    inline void setG(float value)
    {
        set(0, 1, value);
    }

    inline void setB(float value)
    {
        set(0, 2, value);
    }

    inline void setA(float value)
    {
        set(0, 3, value);
    }

    inline void setRGBA(float * value)
    {
        set(0, 0, value[0]);
        set(0, 1, value[1]);
        set(0, 2, value[2]);
        set(0, 3, value[3]);
    }

    inline void setRGBA(float r, float g, float b, float a = 1.0f)
    {
        set(0, 0, r);
        set(0, 1, g);
        set(0, 2, b);
        set(0, 3, a);
    }

    inline float r()
    {
        return get(0, 0);
    }

    inline float g()
    {
        return get(0, 1);
    }

    inline float b()
    {
        return get(0, 2);
    }

    inline float a()
    {
        return get(0, 3);
    }

private:
    void set(int r, int c, float value)
    {
        AbstractMatrix<float>::set(r, c, value);
    }

    float get(int r, int c)
    {
        return AbstractMatrix<float>::get(r, c);
    }
};

class ColorRGBAi : public AbstractMatrix<int>
{
public:
    ColorRGBAi() :
        AbstractMatrix<int>(1, 4)
    {
    }

    ColorRGBAi(int * value) :
        AbstractMatrix<int>(1, 4, value)
    {
    }

    ColorRGBAi(int r, int g, int b, int a = 255) :
        AbstractMatrix<int>(1, 4)
    {
        setRGBA(r, g, b, a);
    }

    inline void setR(int value)
    {
        set(0, 0, value);
    }

    inline void setG(int value)
    {
        set(0, 1, value);
    }

    inline void setB(int value)
    {
        set(0, 2, value);
    }

    inline void setA(int value)
    {
        set(0, 3, value);
    }

    inline void setRGBA(int * value)
    {
        set(0, 0, value[0]);
        set(0, 1, value[1]);
        set(0, 2, value[2]);
        set(0, 3, value[3]);
    }

    inline void setRGBA(int r, int g, int b, int a = 255)
    {
        set(0, 0, r);
        set(0, 1, g);
        set(0, 2, b);
        set(0, 3, a);
    }

    inline int r()
    {
        return get(0, 0);
    }

    inline int g()
    {
        return get(0, 1);
    }

    inline int b()
    {
        return get(0, 2);
    }

    inline int a()
    {
        return get(0, 3);
    }

private:
    void set(int r, int c, int value)
    {
        AbstractMatrix<int>::set(r, c, value);
    }

    int get(int r, int c)
    {
        return AbstractMatrix<int>::get(r, c);
    }
};
}
#endif // COLORRGBA

