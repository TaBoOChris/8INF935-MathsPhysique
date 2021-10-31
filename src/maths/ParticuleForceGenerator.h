#pragma once
#include "Particule.h"

/// <summary>
/// Interface des classes de generateurs de forces
/// </summary>
class ParticuleForceGenerator
{
public:

    virtual void updateForce(Particule *particule, float duration)=0;

};
