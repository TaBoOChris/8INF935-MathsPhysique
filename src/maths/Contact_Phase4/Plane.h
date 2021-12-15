#pragma once
#include "Primitive.h"

// *body = null

class Plane :
    public Primitive
{
public:
    Plane();

    Plane(Vector3D normal, float offset);

private:
    Vector3D normal;
    float offset;
};

