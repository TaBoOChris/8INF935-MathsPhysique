#pragma once
#include "../Particule.h"
#include "../Vecteur3D.h"

/// <summary>
/// Interface des classes de generateurs de forces
/// </summary>
class ParticuleForceGenerator
{
public:

    virtual void updateForce(Particule *particule, float duration)=0;

};
