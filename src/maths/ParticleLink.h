#pragma once
#include "ParticleContactGenerator.h"

class ParticleLink :
    public ParticleContactGenerator
{

protected:
    Particule* particules[2];

public:
    float currentLen() const;
    ParticleLink(Particule* partA, Particule* partB);
};

