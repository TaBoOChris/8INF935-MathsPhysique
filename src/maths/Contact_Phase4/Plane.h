#pragma once
#include "Primitive.h"

// *body = null

class Plane :
    public Primitive
{
private:
    Vector3D normal;
    float offset;

public:

    // ------ Constructor ----------
    Plane();
    Plane(Vector3D normal, float offset);

    // ------ Getters ----------
    Vector3D getNormal();
    float getOffset();

};

