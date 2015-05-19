#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "math/abstract3vector.h"
#include "math/colorrgba.h"

namespace MMO_SERVER
{

class SceneObject
{
public:
    SceneObject()
    {
        this->__sc.setXYZ(1.0f, 1.0f, 1.0f);
    }

    ~SceneObject()
    {

    }

    void setLocation(Vector3f &v)
    {
        this->__l.setXYZ(v.x(), v.y(), v.z());
    }

    void setLocation(float x, float y, float z)
    {
        this->__l.setXYZ(x, y ,z);
    }

    inline Vector3f location()
    {
        return this->__l;
    }

    void setRotation(Vector3f &v)
    {
        this->__rot.setXYZ(v.x(), v.y(), v.z());
    }

    void setRotation(float x, float y, float z)
    {
        this->__rot.setXYZ(x, y ,z);
    }

    inline Vector3f rotation()
    {
        return this->__rot;
    }

    void setScale(Vector3f &v)
    {
        this->__sc.setXYZ(v.x(), v.y(), v.z());
    }

    void setScale(float x, float y, float z)
    {
        this->__sc.setXYZ(x, y ,z);
    }

    inline Vector3f scale()
    {
        return this->__sc;
    }

private:
    // Положение на сцене, масштабирование, поворот
    Vector3f __l, __sc, __rot;
};

}
#endif // SCENEOBJECT_H
