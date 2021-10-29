#pragma once
#include "ParticleLink.h"

class ParticleRod :
    public ParticleLink
{
private:
    float len;

public:
    ParticleRod(Particule* partA, Particule* partB, float len);

    void ajouterContact();
};

