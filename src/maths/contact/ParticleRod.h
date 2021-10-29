#pragma once
#include "ParticleLink.h"
#include <vector>

class ParticleRod :
    public ParticleLink
{
private:
    float len;

public:
    ParticleRod(Particule* partA, Particule* partB, float len);

    void ajouterContact(std::vector<ParticleContact*> particleContacts);
};

