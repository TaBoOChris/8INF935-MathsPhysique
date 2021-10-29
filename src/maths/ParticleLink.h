#pragma once
#include "ParticleContactGenerator.h"

class ParticleLink :
    public ParticleContactGenerator
{

protected:
    Particule* particules[2];
    float currentLen() const;

public:
    ParticleLink(Particule* partA, Particule* partB);
};

