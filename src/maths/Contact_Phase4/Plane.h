#pragma once
#include "Primitive.h"

// *body = null

class Plane :
    public Primitive
{
private:
    Vector3D normal;
    float offset;
};

