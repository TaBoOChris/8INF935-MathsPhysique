#pragma once
#include "Primitive.h"
class Box :
    public Primitive
{
public:
    Box();
    Box(Vector3D halfsizes);
private:
    Vector3D halfsizes;
};

