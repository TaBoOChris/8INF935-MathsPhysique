#pragma once
#include "Primitive.h"

// *body = null

class Plane :
    public Primitive
{
public:
    Plane();

    Plane(Vector3D normal, float offset);

    Vector3D getNormal();
    float getOffset();

private:
    Vector3D normal;
    float offset;
};

