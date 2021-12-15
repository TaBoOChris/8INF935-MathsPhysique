#pragma once
#include "Primitive.h"
#include "Plane.h"

class Box :
    public Primitive
{
public:
    Box();
    Box(CorpsRigide* self, Vector3D halfsizes, Matrix4 matrix);
    Contact contact(Plane other);

    Vector3D getHalfsize();
    Matrix4 getOffset();
    CorpsRigide* getBody();
private:
    Vector3D halfsizes;
};

